#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <deque>
#define inf 0x3F3F3F3F
using namespace std;
struct Node
{
	int x,c;
};
deque<Node>q;
unordered_map<int,vector<int> >e[100005];
unordered_map<int,int>d[100005];
vector<int>g[100005];
int main(void)
{
	int i,x,y,c,cost,n,m,ans=inf;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&c);
		e[x][c].push_back(y);
		e[y][c].push_back(x);
		g[x].push_back(c);
		g[y].push_back(c);
	}
	d[0][0]=0;q.push_back((Node){1,0});
	while(!q.empty())
	{
		x=q.front().x;c=q.front().c;cost=d[x][c];q.pop_front();
		if(d[x].find(0)==d[x].end()||d[x][0]>cost)
		{
			d[x][0]=cost;q.push_front((Node){x,0});
		}
		if(c==0)
		{
			for(i=0;i<g[x].size();++i)
			{
				y=g[x][i];
				if(d[x].find(y)==d[x].end()||d[x][y]>cost+1)
				{
					d[x][y]=cost+1;q.push_back((Node){x,y});
				}
			}
			continue;
		}
		for(i=0;i<e[x][c].size();++i)
		{
			y=e[x][c][i];
			if(d[y].find(c)==d[y].end()||d[y][c]>cost)
			{
				d[y][c]=cost;q.push_front((Node){y,c});
			}
		}
	}
	unordered_map<int,int>::iterator j;
	for(j=d[n].begin();j!=d[n].end();++j)ans=min(ans,j->second);
	if(ans!=inf)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}