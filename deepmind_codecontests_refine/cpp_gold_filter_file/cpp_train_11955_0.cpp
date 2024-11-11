#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;
const int Maxn=200005;
ll a[Maxn];
int par[Maxn];
vector <ll> v[Maxn];
ll ans,cnt;
int n,m;
int find(int x)
{
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}
int main()
{
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	rep(i,n) par[i]=i;
	rep(i,m)
	{
		int x,y;
		cin>>x>>y;
		par[find(x)]=find(y);
	}
	rep(i,n)
	{
		v[find(i)].push_back(a[i]);
	}
	vector <ll> p;
	rep(i,n)
	{
		if (v[i].empty()) continue;
		cnt++;
		sort(v[i].begin(),v[i].end());
		ans+=v[i][0];
		for (int j=1;j<v[i].size();j++)
		{
			p.push_back(v[i][j]);
		}
	}
	if (cnt==1)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(p.begin(),p.end());
	rep(i,2*(n-m-1)-cnt)
	{
		if (p.size()<=i)
		{
			cout<<"Impossible\n";
			return 0;
		}
		ans+=p[i];
	}
	cout<<ans<<endl;
	return 0;
}