#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> li;
typedef pair<int,ll> il;
typedef vector<il> vil;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vil> graph;
vector<ll> dist;
void dijkstra()
{
	dist[1] = 0ll;
	priority_queue<li,vector<li>,greater<li> >pq;
	pq.push(li(0ll,1));
	while(!pq.empty())
	{
		li x = pq.top();pq.pop();
		ll a = x.first;
		int b = x.second;
		if(dist[b]==a)
		{
			for(int i=0;i<graph[b].size();++i)
			{
				il c = graph[b][i];
				if(dist[c.first]==-1||dist[c.first] > dist[b] + c.second)
				{
					dist[c.first] = dist[b] + c.second;
					pq.push(ii(dist[c.first],c.first));
				}
			}
		}
	}
}
int main()
{
	int n,m,i,x,y;
	ll w;
	cin>>n>>m;
	graph.assign(n+1,vil());
	dist.assign(n+1,-1);
	for(i=1;i<=n;++i)
	{
		graph[i].push_back(il(i-1,0ll));
	}
	for(i=1;i<=m;++i)
	{
		cin>>x>>y>>w;
		graph[x].push_back(il(y,w));
		graph[y].push_back(il(x,w));
	}
	dijkstra();
	printf("%lld",dist[n]);
}