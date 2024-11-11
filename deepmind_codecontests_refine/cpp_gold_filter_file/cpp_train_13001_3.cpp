#include <stdio.h>

int main(void)
{
	int a,b=0,i,j;
	for(i=0;i<10;i++){
		scanf("%d",&a);
		b=b+a;
	}
	printf("%d\n",b);
}