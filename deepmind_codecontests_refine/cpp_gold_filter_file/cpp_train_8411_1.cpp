#include <bits/stdc++.h>
using namespace std;

multiset<int> edge[100005];
int memo[100005],f=0;

void dfs(int now)
{
	for (auto i = edge[now].begin(); i != edge[now].end(); ++i)
	{
		if (memo[*i]==1)
		{
			f=1;
		}
		else if (memo[*i]==-1)
		{
			memo[*i]=0;
			edge[*i].erase(now);
			dfs(*i);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;--a;--b;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	int s=-1,cnt=0;
	for (int i = 0; i < n; ++i)
	{
		if (edge[i].size()%2==1)
		{
			cout<<"No\n";
			return 0;
		}
		else if (edge[i].size()>=6)
		{
			cnt=100;
		}
		else if (edge[i].size()==4)
		{
			++cnt;
			if (cnt==1)
			{
				s=i;
			}
			else
			{
				edge[i]={};
			}
		}
	}
	if (cnt>=3)
	{
		cout<<"Yes\n";
		return 0;
	}
	else if (cnt<=1)
	{
		cout<<"No\n";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		memo[i]=-1;
	}
	memo[s]=1;
	dfs(s);
	if (f==1)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
