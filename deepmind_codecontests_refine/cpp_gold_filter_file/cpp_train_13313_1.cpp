#define scanf_s scanf
#include<stdio.h>
int main(void) {
	int a, b, i, mo[4] = { 6000,4000,3000,2000 };
	for (i = 0; i < 4; i++) {
		scanf_s("%d %d", &a, &b);
		printf("%d\n", mo[a - 1] * b);
	}	
	return(0);
}