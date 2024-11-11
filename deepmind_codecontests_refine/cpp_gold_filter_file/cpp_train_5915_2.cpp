#include<stdio.h>
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	if((a+1)/2 >= b)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}