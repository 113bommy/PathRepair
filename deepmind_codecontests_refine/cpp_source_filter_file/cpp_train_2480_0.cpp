#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define Maxn 100005
int n,id[Maxn],par[Maxn],sz[Maxn];
long long a[Maxn];
map <long long,int> mp;
int main()	
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		mp[a[i]]=i;
		id[i]=i;
		sz[i]=1;
	}
	sort(id+1,id+n+1,[&](const int &a,const int &b)->bool{return a[x]>a[y];});
	for (int i=1;i<n;++i)
	{
		int x=id[i];
		par[x]=mp[a[x]-n+2*sz[x]];
		if (!par[x]) return (int)puts("-1")*0;
		sz[par[x]]+=sz[x];
	}
	for (int i=1;i<n;++i) a[id[n]]-=sz[id[i]];
	if (a[id[n]]) return (int)puts("-1")*0;
	for (int i=1;i<n;++i) printf("%d %d\n",id[i],par[id[i]]);
	return 0;
}