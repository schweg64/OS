#include "../include/console.h"
enum Color terminal_font_color = GRAY;
void print_character(char c){
	print_character_with_color(c, terminal_font_color);
}

void print_string(char* str){
	print_string_with_color(str, terminal_font_color);
}

void print_line(char* str){
	print_line_with_color(str, terminal_font_color);
}

void set_terminal_font_color(enum Color newColor){
	terminal_font_color = newColor;
}

void print_character_with_color(char c, enum Color color){
	VGA_MEMORY[pos] = c;
        VGA_MEMORY[pos+1] = color;
        pos += 2;	
}

void print_string_with_color(char* str, enum Color color){
	unsigned int i = 0;
        while (str[i] != '\0') {
                print_character_with_color(str[i], color);
                i++;
        }
}

void print_line_with_color(char* str, enum Color color){
	print_string_with_color(str, color);
        pos = pos + (VGA_WIDTH*2 - (pos%(VGA_WIDTH*2)));
}

void shift_terminal_up(){
	unsigned int i = 0;
	while (i < VGA_WIDTH*2*VGA_HEIGHT - 2*VGA_WIDTH){
		VGA_MEMORY[i] = VGA_MEMORY[i+2*VGA_WIDTH];
		i++;
	}
	while (i < VGA_WIDTH*2*VGA_HEIGHT){
		VGA_MEMORY[i] = 0;
		i++;
	}
}
