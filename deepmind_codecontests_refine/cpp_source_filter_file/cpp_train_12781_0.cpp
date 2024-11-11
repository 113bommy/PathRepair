#include<stdio.h>

int main()
{
	int r,g,b,k,flag=0;
	scanf("%d %d %d",&r&g&b);
	scanf("%d",&k);
	while(g<=r)
	{
		g*=2;
		flag++;
	}
	while(b<=g)
	{
		g*=2;
		flag++; 
	}
	if(flag<=k) printf("Yes\n");
	else printf("No\n");
	
	return 0;
 } 