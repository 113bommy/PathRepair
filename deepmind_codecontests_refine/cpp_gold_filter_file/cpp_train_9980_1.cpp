#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#define SIZE 100005
#define INF 1000000000000005LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
vector <P> query[SIZE];
ll mn[SIZE];
ll dist[SIZE];
bool use[SIZE];
int dp[SIZE];

int main()
{
	int r,c;
	scanf("%d %d",&r,&c);
	int n;
	scanf("%d",&n);
	for(int i=0;i<c;i++) mn[i]=INF;
	for(int i=0;i<n;i++)
	{
		int x,y,a;
		scanf("%d %d %d",&x,&y,&a);
		x--,y--;
		query[x].push_back(P(y,a));
		mn[y]=min(mn[y],(ll) a);
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j+1<query[i].size();j++)
		{
			P p=query[i][j],q=query[i][j+1];
			vec[p.first].push_back(edge(q.first,q.second-p.second));
			vec[q.first].push_back(edge(p.first,p.second-q.second));
		}
	}
	for(int i=0;i<c;i++) dist[i]=INF;
	for(int i=0;i<c;i++)
	{
		if(!use[i])
		{
			dist[i]=0;
			queue <int> que;
			que.push(i);
			ll all=0,all2=mn[i];
			while(!que.empty())
			{
				int v=que.front();que.pop();
				use[v]=true;
				all=min(all,dist[v]);
				all2=min(all2,mn[v]-dist[v]);
				for(int j=0;j<vec[v].size();j++)
				{
					edge e=vec[v][j];
					if(dist[e.to]==INF)
					{
						dist[e.to]=dist[v]+e.cost;
						que.push(e.to);
					}
					else if(dist[e.to]!=dist[v]+e.cost)
					{
						puts("No");
						return 0;
					}
				}
			}
			//Xj=Xi+dist[j]
			//Xj=Xk+dist[j]-dist[k]
			//-> (Xk-dist[k])+all で 0未 があればやばい
			if(all2+all<0)
			{
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
