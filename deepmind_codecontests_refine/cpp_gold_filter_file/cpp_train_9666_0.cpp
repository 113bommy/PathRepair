#include <bits/stdc++.h>
using namespace std;
int n,m,q,i,j,vt[100005],d[100005],c[100005],dp[100005],col[100005];
vector <int> g[100005];
void dfs(int v,int d,int c)
{
	if (!col[v]) col[v]=c;
	if (dp[v]>=d || d==0) return;
	dp[v]=d;for (int i=0;i<g[v].size();++i)
		dfs(g[v][i],d-1,c);
}
int main()
{
	cin>>n>>m;
	for (i=0;i<m;++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>q;
	for (i=0;i<q;++i) cin>>vt[i]>>d[i]>>c[i];
	for (i=q-1;i>=0;--i) dfs(vt[i],d[i],c[i]);
	for (i=1;i<=n;++i) cout<<col[i]<<endl;
}