#include<stdio.h>
int main(void)
{
	int a,b;
	while(scanf("%d",&a)!=EOF) {
	b=a%39;
	if(b==0) b=39;	
	printf("3C%02d\n",b);
	}
	return 0;
}