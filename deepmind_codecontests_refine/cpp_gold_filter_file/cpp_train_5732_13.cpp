#include <stdio.h>
int main()
{
	int a;
        int b;
	scanf("%d",&a);
        scanf("%d",&b);
	printf("%d %d %lf\n",a/b,a%b,a/(double)b);
	return 0;
}