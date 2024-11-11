#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int> z[200005];
int cnt[200005];
int ans[200005];
void dfs(int a,int b,int c)
{
	c+=cnt[a];
	ans[a]=c;
	for (int i=0;i<z[a].size();i++)
	{
		int v=z[a][i];
		if(v!=b)
		{
			dfs(v,a,c);			
		}
	}
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		z[x].push_back(y);
		z[y].push_back(x);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cnt[x]+=y;
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";		
	}
	cout<<endl;
	return 0;
}
