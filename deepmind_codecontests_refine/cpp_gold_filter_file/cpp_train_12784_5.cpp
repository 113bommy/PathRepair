#include<stdio.h>
int main()
{
	int a,b,z[100],i,s,c;
	while(~scanf("%d%d",&a,&b))
	{
		s=0;
		c=1;
		for(i=0;i<a;i++)
		{
			scanf("%d",&z[i]);
			s+=z[i];
			if(s<=b)
			c++;
		}
		printf("%d\n",c);
	} 
	return 0;
 } 