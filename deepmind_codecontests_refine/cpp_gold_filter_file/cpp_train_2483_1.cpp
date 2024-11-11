#include<stdio.h>
int main()
{
	int i,n,m,b;
	while(~scanf("%d %d", &n, &m))
	{
		int ar[51]={0};
		for(i=0; i<2*m; i++)
		{
			scanf("%d", &b);
			ar[b-1]++;
		}
		for(i=0; i<n; i++)
			printf("%d\n", ar[i]);
	}
	return 0;
}