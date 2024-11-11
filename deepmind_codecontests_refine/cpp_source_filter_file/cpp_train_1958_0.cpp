#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define N 400005
int st[N],nd[N],a[N];
int pos[N],dfn[N],cnt,sum[N][2],s1;
int fa[N][20],dep[N],ans[N],n,m,an;
int g1[N][2];
bool f[N];
struct mzls
{
	int l,r,id,aa,bb;
	bool p;
}a1[N];
struct node
{
	int to,co,ct;
	node(){}
	node(int xx,int yy,int zz)
	{
		to=xx,co=yy,ct=zz;
	}
};
vector<node>g[N];
bool operator<(mzls a,mzls b)
{
	return pos[a.l]==pos[b.l]?a.r<b.r:a.l<b.l;
}
inline void dfs(int x)
{
	dfn[++cnt]=x;
	st[x]=cnt;
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;i<20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	int l1=g[x].size();
	for(int i=0;i<l1;i++)
	{
		int v=g[x][i].to,co=g[x][i].co,ct=g[x][i].ct;
		if(v==fa[x][0])
			continue;
		fa[v][0]=x;
		g1[v][0]=co,g1[v][1]=ct;
		dfs(v);
	}
	dfn[++cnt]=x;
	nd[x]=cnt;
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
inline void modify(int x)
{
	if(!f[x])
	{
		sum[g1[x][0]][0]++;
		sum[g1[x][0]][1]+=g1[x][1];
		s1+=g1[x][1];
		f[x]=1;
	}
	else
	{
		sum[g1[x][0]][0]--;
		sum[g1[x][0]][1]-=g1[x][1];
		s1-=g1[x][1];
		f[x]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,x1,y1;
		scanf("%d%d%d%d",&x,&y,&x1,&y1);
		g[x].push_back(node(y,x1,y1));
		g[y].push_back(node(x,x1,y1));
	}
	dfs(1);
	int d=sqrt(n);
	for(int i=1;i<=n;i++)
		pos[i]=i/d;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d%d",&a1[i].aa,&a1[i].bb,&a1[i].l,&a1[i].r);
		int lc=LCA(a1[i].l,a1[i].r);
		if(lc==a1[i].l||lc=a1[i].r)
		{
			if(lc==a1[i].r)
				swap(a1[i].l,a1[i].r);
			x=st[a1[i].l]+1;
			y=st[a1[i].r];
			a1[i].p=0;
		}
		else
		{
			if(st[a1[i].l]>st[a1[i].r])
				swap(a1[i].l,a1[i].r);
			x=nd[a1[i].l];
			y=st[a1[i].r];
			a1[i].p=1;
		}
		a1[i].l=x;
		a1[i].r=y;
		a1[i].id=i;
	}
	sort(a1+1,a1+m+1);
	int l1=1,r1=0;
	for(int i=1;i<=m;i++)
	{
		while(l1>a1[i].l)
			modify(dfn[--l1]);
		while(l1<a1[i].l)
			modify(dfn[l1++]);
		while(r1<a1[i].r)
			modify(dfn[++r1]);
		while(r1>a1[i].r)
			modify(dfn[r1--]);
		//int lc=LCA(dfn[l1],dfn[r1]);
		//if(a1[i].p)
		//	modify(lc);
		ans[a1[i].id]=s1-sum[a1[i].aa][1]+sum[a1[i].aa][0]*a1[i].bb;
		//if(a1[i].p)
		//	modify(lc);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}