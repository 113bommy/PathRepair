#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,ans[maxn],vis[maxn];
vector<int>g[maxn],v[2];
void dfs(int u = 1, int fa = 0, int t = 0)
{
	v[t].push_back(u);
	for(int i = 0; i < (int) g[u].size(); ++i) 
	{
		int v = g[u][i];
		if(v==fa) 	continue;
		dfs(v,u,1-t);
	}
}
int main()
{
	int i,u,t;
	scanf("%d",&n);
	for(i=1;i<n;++i) 
	{
		scanf("%d %d",&u,&t);
		g[u].push_back(t);
		g[t].push_back(u);
	}
	dfs();
	if(v[0].size()>v[1].size()) 	swap(v[0],v[1]);
	int sum = n/3;
	if(v[0].size() <= sum) 
	{
		for(i=1;i<=n;++i)
		{
			if(!v[0].size()) break;
			if(i % 3 == 0) 
			{
				t = v[0].back();
				ans[t] = i;
				v[0].pop_back();
				vis[i]++;
			}
		}
	}
	else
	{
		for(i=1;i<=n;++i) 
		{
			if(!v[0].size()) break;
			if(i % 3 == 1) 
			{
				t = v[0].back();
				ans[t] = i;
				v[0].pop_back();
				vis[i]++;
			}
		}
		for(i=1;i<=n;++i) 
		{
			if(!v[0].size()) break;
			if(i%3==0) 
			{
				t = v[0].back();
				ans[t] = i;
				v[0].pop_back();
				vis[i]++;
			}
		}
	}
	for(i=1;i<=n;++i) 
	{
		if(!v[1].size()) 	break;
		if(!vis[i])
		{
			t = v[1].back();
			ans[t] = i;
			v[1].pop_back();
			vis[i]++;
		}
	}
	for(i=1;i<=n;++i) 	printf("%d ",ans[i]);
}

