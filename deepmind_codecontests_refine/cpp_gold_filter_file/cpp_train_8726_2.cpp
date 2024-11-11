#include <bits/stdc++.h>
using namespace std;
int xx[90001];
int yy[90001];
int d[90001];
int main()
{
	int i,j,H,W,D,a,x,y,m;
	scanf("%d%d%d",&H,&W,&D);
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++)
		{
			scanf("%d",&a);
			xx[a]=i;
			yy[a]=j;
		}
	}
	for(i=D+1;i<=H*W;i++)
		d[i]=d[i-D]+abs(xx[i]-xx[i-D])+abs(yy[i]-yy[i-D]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",d[y]-d[x]);
	}
	return 0;
}