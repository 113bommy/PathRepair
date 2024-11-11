#include<bits/stdc++.h>
using namespace std;
const int mx=100010;
int x,y,a,b,c,tot,tat;
long long e[mx*3],r[mx],g[mx],awa;
int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for (int i=1;i<=a;i++)
	{
		scanf("%d",&r[i]);
	}
	sort(r+1,r+a+1);
	for (int i=a;i>=a-x+1;i--)
	{
	    e[++tat]=r[i];
	}
	for (int i=1;i<=b;i++)
	{
		scanf("%d",&g[i]);
	}
	sort(g+1,g+b+1);
	for (int i=b;i>=b-y+1;i--)
	{
	    e[++tet]=g[i];
	} 
	for (int i=1;i<=c;i++)
	{
		scanf("%d",&tot);
		e[++tet]=tot;
	}
	sort(e+1,e+tat+1);
	for (int i=tat;i>=tat-x-y+1;i--)
	{
		awa+=e[i];
	}
	printf("%lld\n",awa);
	return 0;
}