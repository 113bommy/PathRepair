#include <stdio.h>
#include <algorithm>

using namespace std;

int x[200200];

int main()
{
	int i,j,n,l;
	scanf("%d %d",&n,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=1;i<n;i++)
	{
		if(x[i]+x[i+1] >= l)
			break;
	}
	if(i == n)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for(j=1;j<i;j++)
			printf("%d\n",j);
		for(j=n-1;j>=i;j--)
			printf("%d\n",j);
	}
	return 0;
}