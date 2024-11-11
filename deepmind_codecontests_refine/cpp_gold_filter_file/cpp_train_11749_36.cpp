#include <stdio.h>
char c[20];
int main()
{
	int i;
	while(~scanf("%s",c))
	{
		c[5]=' ';
		c[13]=' ';
		printf("%s\n",c);
	}
	return 0;
}