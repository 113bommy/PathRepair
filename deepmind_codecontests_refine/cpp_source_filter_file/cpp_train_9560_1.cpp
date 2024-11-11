#include<stdio.h>
long a, b,c;
long count = 0;
int main() {
	scanf_s("%ld,%ld", &a, &b);
	for (a; a <= b; a++) {
		c = (a % 10) * 10 + ((a % 100) / 10);
			if (a / 1000 == c) count++;
	}
	printf("%ld", count);
}