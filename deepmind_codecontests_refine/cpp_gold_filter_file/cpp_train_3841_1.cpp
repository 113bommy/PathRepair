#include <stdio.h>

int main(void) {

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a >= c) {
		printf("0\n");
	}
	else if ((a + b) < c) {

		printf("NA\n");
	}
	else {
		printf("%d\n", c - a);

	}
	return 0;
}
