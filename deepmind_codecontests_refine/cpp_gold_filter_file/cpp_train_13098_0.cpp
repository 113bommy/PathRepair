#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
struct edge
{
	ll x,w,c;
	bool operator<(const edge&y)const
	{
		return w>y.w;
	}
	bool operator>(const edge&y)const
	{
		return w<y.w;
	}
}h,v;
ll ans[100005],n,m,ss,t,i,a[100005],x,y,w,c,b[100005],vis1[100005],vis2[100005];
vector<edge> s[100005];
priority_queue<edge> q;
ll minn(ll a,ll b){return a<b?a:b;}
int main()
{
	cin>>n>>m>>ss>>t;
	for(i=1;i<=n;i++)a[i]=b[i]=1e16;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>w>>c;
		s[x].push_back((edge){y,w,c});
		s[y].push_back((edge){x,w,c});
	}
	a[ss]=0;
	q.push((edge){ss,0,0});
	while(!q.empty())
	{
		h=q.top();
		q.pop();
		if(vis1[h.x])continue;
		vis1[h.x]=1;
		for(i=0;i<s[h.x].size();i++)
		{
			v=s[h.x][i];
			if(vis1[v.x])continue;
			if(a[v.x]>a[h.x]+v.w)
			{
				a[v.x]=a[h.x]+v.w;
				q.push((edge){v.x,a[v.x],0});
			}
		}
	}
	b[t]=0;
	q.push((edge){t,0,0});
	while(!q.empty())
	{
		h=q.top();
		q.pop();
		if(vis2[h.x])continue;
		vis2[h.x]=1;
		for(i=0;i<s[h.x].size();i++)
		{
			v=s[h.x][i];
			if(vis2[v.x])continue;
			if(b[v.x]>b[h.x]+v.c)
			{
				b[v.x]=b[h.x]+v.c;
				q.push((edge){v.x,b[v.x],0});
			}
		}
	}
	for(i=1;i<=n;i++)a[i]+=b[i];
	ans[n+1]=1e16;
	for(i=n;i>0;i--)
	{
		ans[i]=minn(ans[i+1],a[i]);
	}
	for(i=1;i<=n;i++)cout<<1000000000000000-ans[i]<<endl;
	return 0;
}