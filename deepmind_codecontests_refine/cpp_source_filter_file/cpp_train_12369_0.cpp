#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int edge[300000],next[300000],first[300000];
int d[300000],e[300000],g[300000];
int i,m,n,x,y,head,tail,sum_edge;

inline void addedge(int x,int y)
{
	sum_edge++,edge[sum_edge]=y,next[sum_edge]=first[x],first[x]=sum_edge;
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<n+m;i++)
		scanf("%d%d",&x,&y),addedge(x,y),d[y]++;
	for (i=1;i<=n;i++)
		if (! d[i])
			tail++,g[tail]=i;
	for (head=1;head<=tail;head++)
	{
		for (i=first[g[head]];i!=0;i=next[i])
		{
			d[edge[i]]--;
			if (! d[edge[i]])
				tail++,g[tail]=edge[i],e[g[tail]]=g[head];
		}
	}
	for (i=1;i<=n;i++)
		printf("%d\n",e[i]);
	return 0;
}