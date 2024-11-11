#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf=30000;

int edge[30000],nxt[30000],flow[30000],first[300];
int g[300],h[300];
char c[300][300];
int i,j,m,n,s,head,tail,sum_edge;

inline void addedge(int x,int y,int f)
{
	sum_edge++,edge[sum_edge]=y,flow[sum_edge]=f,nxt[sum_edge]=first[x],first[x]=sum_edge;
	return;
}

inline int oppedge(int x)
{
	return ((x-1)^1)+1;
}

inline void buildgraph()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			switch (c[i][j])
			{
				case 'S':
					addedge(0,i,inf),addedge(i,0,0);
					addedge(0,n+j,inf),addedge(n+j,0,0);
					break;
				case 'T':
					addedge(i,n+m+1,inf),addedge(n+m+1,i,0);
					addedge(n+j,n+m+1,inf),addedge(n+m+1,n+j,0);
					break;
				case 'o':
					addedge(i,n+j,1),addedge(n+j,i,1);
					break;
			}
	return;
}

inline int dinic_bfs()
{
	memset(h,0,sizeof(h));
	tail=1,g[tail]=0,h[g[tail]]=1;
	for (head=1;head<=tail;head++)
		for (i=first[g[head]];i!=0;i=nxt[i])
			if ((flow[i]) && (! h[edge[i]]))
				tail++,g[tail]=edge[i],h[g[tail]]=h[g[head]]+1;
	return h[n+m+1];
}

inline int dinic_dfs(int now,int cap)
{
	if (now==n+m+1)
		return cap;
	int s=0,t=0;
	for (int i=first[now];i!=0;i=nxt[i])
		if ((flow[i]) && (h[edge[i]]==h[now]+1))
		{
			t=dinic_dfs(edge[i],min(cap,flow[i]));
			s=s+t,cap=cap-t;
			flow[i]=flow[i]-t,flow[oppedge(i)]=flow[oppedge(i)]+t;
			if (! cap)
				break;
		}
	if (cap)
		h[now]=0;
	return s;
}

inline void maxflow()
{
	while (dinic_bfs())
		s=s+dinic_dfs(0,inf);
	if (s>n*m)
		printf("-1");
	else
		printf("%d",s);
	return;
}

int main()
{
	buildgraph();
	maxflow();
	return 0;
}