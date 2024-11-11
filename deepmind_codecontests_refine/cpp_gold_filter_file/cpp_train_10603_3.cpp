#include <bits/stdc++.h>
#define N 20010
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct edge
{
	int u,v,next;
}vs[N*30*2];
int n,st[N*7],ee,las,id[N],nd[N*7],idx[N];
ll X[N],Y[N],V[N];
int dfn[N*7],low[N*7],tim,vis[N*7],op[N],tot,bl[N*7];
stack <int> St;
 
inline void addedge(int u,int v)
{
	vs[++ee].v=v;vs[ee].next=st[u];st[u]=ee;
}
 
inline bool cmp(const int a,const int b)
{
	return V[a]<V[b];
}
void built(int l,int r,int rt)
{
	nd[rt]=++las;
	if(l==r)
	{
		addedge(nd[rt],op[l]);
		return ;
	}
	int mid=(l+r)>>1;
	built(l,mid,rt<<1);
	built(mid+1,r,rt<<1|1);
	addedge(nd[rt],nd[rt<<1]);
	addedge(nd[rt],nd[rt<<1|1]);
}
void linkedge(int L,int R,int x,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		addedge(x,nd[rt]);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=L) linkedge(L,R,x,l,mid,rt<<1);
	if(mid<R) linkedge(L,R,x,mid+1,r,rt<<1|1);
}
void dfs(int rt)
{
	vis[rt]=1; dfn[rt]=low[rt]=++tim;
	St.push(rt);
	for(int i=st[rt];i;i=vs[i].next)
	{
		if(vis[vs[i].v])
		{
			low[rt]=min(low[rt],dfn[vs[i].v]);
		}
		else if(!dfn[vs[i].v])
		{
			dfs(vs[i].v);
			low[rt]=min(low[rt],low[vs[i].v]);
		}
	}
	if(low[rt]==dfn[rt])
	{
		++tot;
		while(St.top()!=rt)
		{
			bl[St.top()]=tot;
			vis[St.top()]=0;
			St.pop();
		}
		St.pop(); bl[rt]=tot; vis[rt]=0;
	}
}
bool check(ll x)
{
	memset(st,0,sizeof st);
	ee=0; las=n+n; tim=0;
	built(1,n+n,1);
	for(int i=1;i<=n+n;i++)
	{
		int pr=upper_bound(V+1,V+1+n+n,V[i]-x)-V;
		int nx=lower_bound(V+1,V+1+n+n,V[i]+x)-V-1;
		if(pr<i) linkedge(pr,i-1,i,1,n+n,1);
		if(nx>i) linkedge(i+1,nx,i,1,n+n,1);
	}
	for(int i=1;i<=las;i++) vis[i]=dfn[i]=low[i]=0;
	for(int i=1;i<=las;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n+n;i++) if(bl[i]==bl[op[i]]) return 0;
	return 1;
}
int main()
{
	//freopen("read.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
		X[i]=read(),Y[i]=read(),
		V[++V[0]]=X[i],id[V[0]]=V[0],
		V[++V[0]]=Y[i],id[V[0]]=V[0];
	sort(id+1,id+1+n+n,cmp);
	for(int i=1;i<=n+n;i++) idx[id[i]]=i;
	for(int i=1;i<=n+n;i++) op[i]=idx[(id[i]&1)? id[i]+1: id[i]-1];
	sort(V+1,V+1+n+n);
	ll l=0,r=1000000000,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}