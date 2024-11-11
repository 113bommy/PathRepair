#include<stdio.h>
int main(void) {
	int i, x;
	for (x = 1;x < 10;x++) {}
	for (i = 1;i < 10;i++) {
		printf("%dx%d=%d\n", x, i, x*i);
	}
}
	return 0;
}