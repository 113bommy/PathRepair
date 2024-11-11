#include<stdio.h>
int main() {
	double a, b;
	scanf_s("%lf %lf", &a, &b);
	printf("%d:%d:%f\n",(int)a/(int)b,(int)a%(int)b,a/b);
}