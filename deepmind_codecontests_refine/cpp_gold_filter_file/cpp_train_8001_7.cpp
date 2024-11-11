#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char in[256];
	fgets(in, 255, stdin);
	int len = strlen(in) - 1;
	in[len] = '\0';
	for(int i=0; i<len; ++i){
		in[i] = toupper(in[i]);
	}
	puts(in);
	return 0;
}