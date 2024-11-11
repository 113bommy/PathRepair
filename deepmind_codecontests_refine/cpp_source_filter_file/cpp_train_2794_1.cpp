#include<stdio.h>
#include<math.h>
main()
{
int A,B,x;
	scanf("%d%d%d",&x,&A,&B);
	if(fbs(x-A)<fbs(x-B))
	printf("A");
	else
		printf("B");
	return 0;
	

}