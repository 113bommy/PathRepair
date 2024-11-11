#include <bits/stdc++.h>
#define N 300010
#define inf 1000000000000000ll
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct edge
{
	int u,v,next;
	ll w;
}vs[N<<1];
int n,ee,st[N],bg[N],ed[N],las;
int V1[N],V2[N];
ll F1[N],F2[N],vl[N];
inline void addedge(int u,int v,int w)
{
	vs[++ee].v=v; 
	vs[ee].w=w; vs[ee].u=u;
	vs[ee].next=st[u];st[u]=ee;
}
inline void dfs(int rt,int pr)
{
	bg[rt]=las++;
	V1[rt]=V2[rt]=-1;
	F1[rt]=F2[rt]=inf;
	for(int i=st[rt];i;i=vs[i].next)
	{
		if(vs[i].v==pr) continue;
		dfs(vs[i].v,rt);
		int xx=V1[vs[i].v]; ll yy=F1[vs[i].v]+vs[i].w;
		if(yy>vl[vs[i].v]+vs[i].w)
			yy=vl[vs[i].v]+vs[i].w,
			xx=vs[i].v;
		if(F1[rt]>yy) swap(yy,F1[rt]),swap(xx,V1[rt]);
		if(F2[rt]>yy) swap(yy,F2[rt]),swap(xx,V2[rt]);
	}
	ed[rt]=las;
}
inline void DFS(int rt,int pr)
{
	for(int i=st[rt];i;i=vs[i].next)
	{
		if(vs[i].v==pr) continue;
		int xx=V1[rt]; ll yy=F1[rt]+vs[i].w;
		if(bg[vs[i].v]<=bg[xx]&&bg[xx]<ed[vs[i].v])
		{
			xx=V2[rt]; yy=F2[rt]+vs[i].w;
		}
		if(yy>vs[i].w+vl[rt])
			yy=vl[rt]+vs[i].w, 
			xx=rt;
		if(F1[vs[i].v]>yy) swap(yy,F1[vs[i].v]),swap(xx,V1[vs[i].v]);
		if(F2[vs[i].v]>yy) swap(yy,F2[vs[i].v]),swap(xx,V2[vs[i].v]);
		DFS(vs[i].v,rt);
	}
}
int fa[N];
inline getfa(int x)
{
	return fa[x]==x? x:fa[x]=getfa(fa[x]);
}
int main()
{
	n=read(); for(int i=1;i<=n;i++)
		vl[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(), v=read(), w=read();
		addedge(u,v,w); addedge(v,u,w); 
	}dfs(1,0); DFS(1,0);
	for(int i=1;i<=n;i++) fa[i]=i;
	ll Ans=0;
	for(int i=1;i<=n;i++)
	{
		if(V1[V1[i]]==i&&i>V1[i]) continue;
		Ans+=F1[i]+vl[i];
		int f1=getfa(i),f2=getfa(V1[i]);
		fa[f1]=f2;
	}
	for(int i=1;i<n;i++)
	{
		if(getfa(vs[i<<1].u)==getfa(vs[i<<1].v)) continue;
		Ans+=min(vl[vs[i<<1].u],F1[vs[i<<1].u]);
		Ans+=min(vl[vs[i<<1].v],F1[vs[i<<1].v]);
		Ans+=vs[i<<1].w;
	}
	cout << Ans << endl;
	return 0 ;
}