#include<stdio.h>
void main(){
	char c;
	for(;~(c=getchar());printf("%c",c))
		c>='a'&&c<='z'?c-=32:0;
}