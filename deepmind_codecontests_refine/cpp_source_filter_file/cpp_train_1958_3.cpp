#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
#define int long long -
struct node{int to,nxt,cost,col;}sq[200200];
int all=0,head[100100];
int n,q,dep[100100],fa[100100][20],cnt[100100];
struct qnode{int col,len,x,id;};
vector<qnode> ask[100100];
ll ans[100100],dis[100100],cdis[100100];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void add(int u,int v,int col,int w)
{
	all++;sq[all].to=v;sq[all].nxt=head[u];sq[all].col=col;sq[all].cost=w;head[u]=all;
}

void dfs(int u,int fu)
{
	dep[u]=dep[fu]+1;fa[u][0]=fu;
	rep(i,1,19)
		fa[u][i]=fa[fa[u][i]][i-1];
	for (int i=head[u];i;i=sq[i].nxt)
	{
		int v=sq[i].to;
		if (v==fu) continue;
		dis[v]=dis[u]+sq[i].cost;
		dfs(v,u);
	}
}

int LCA(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	int tmp=dep[u]-dep[v];
	per(i,19,0)
		if ((tmp>>i)&1) u=fa[u][i];
	if (u==v) return u;
	per(i,19,0)
		if (fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];v=fa[v][i];
		}
	return fa[u][0];
}

void dfs1(int u,int fu)
{
	int len=ask[u].size();
	rep(i,0,len-1)
	{
		ans[ask[u][i].id]+=1ll*ask[u][i].x*(dis[u]-cdis[ask[u][i].col]+1ll*ask[u][i].len*cnt[ask[u][i].col]);
	}
	for (int i=head[u];i;i=sq[i].nxt)
	{
		int v=sq[i].to;
		if (v==fu) continue;
		cnt[sq[i].col]++;cdis[sq[i].col]+=sq[i].cost;
		dfs1(v,u);
		cnt[sq[i].col]--;cdis[sq[i].col]-=sq[i].cost;
	}
}

signed main()
{
	n=read();q=read();
	rep(i,1,n-1)
	{
		int u=read(),v=read(),col=read(),w=read();
		add(u,v,col,w);add(v,u,col,w);
	}
	dfs(1,0);
	rep(i,1,q)
	{
		int col=read(),w=read(),u=read(),v=read(),l=LCA(u,v);
		ask[u].push_back((qnode){col,w,1,i});
		ask[v].push_back((qnode){col,w,1,i});
		ask[l].push_back((qnode){col,w,-2,i});
	}
	dfs1(1,0);
	rep(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}