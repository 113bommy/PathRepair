#include <bits/stdc++.h>
using namespace std;
int p[100001];
int parent[100001];
int findparent(int x)
{
	if(parent[x]!=x)
		parent[x]=findparent(parent[x]);
	return parent[x];
}
void unionset(int a,int b)
{
	if((a=findparent(a))==(b=findparent(b)))
		return;
	parent[a]=b;
	return;
}
int main()
{
	int n,m,i,ans=0,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		parent[i]=i;
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&b,&c);
		unionset(p[b],p[c]);
	}
	for(i=1;i<=n;i++)
	{
		if(findparent(p[i])==findparent(i))
			ans++;
	}
	printf("%d",ans);
	return 0;
}