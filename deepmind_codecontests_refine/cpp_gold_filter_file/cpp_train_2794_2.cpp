#include<stdio.h>
#include<math.h>
int main()
{
int A,B,x;
	scanf("%d%d%d",&x,&A,&B);
	if(fabs(x-A)<fabs(x-B))
	printf("A");
	else
		printf("B");
	return 0;
	

}