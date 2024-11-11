#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define F first
#define S second
#define MP make_pair
int N, K;
int c[5000], r[5000];
bool flag[5000];
int flag2[5000];
vector<int> G[5000], G2[5000];
priority_queue<P, vector<P>, greater<P> > pq;
void bfs(int s)
{
	queue<P> que;
	que.push(MP(s, 0));
	memset(flag, 0, sizeof(flag));
	flag[s] = true;
	while(!que.empty())
	{
		P now = que.front();
		que.pop();
		if(now.S == r[s]) continue;
		for(int i = 0; i < G[now.F].size(); ++i)
		{
			if(!flag[G[now.F][i]])
			{
				flag[G[now.F][i]] = true;
				que.push(MP(G[now.F][i], now.S + 1));
				G2[s].push_back(G[now.F][i]);
			}
		}
	}
}
void dijkstra(int s)
{
	pq.push(MP(0, 0));
	while(!pq.empty())
	{
		P now = pq.top();
		pq.pop();
		for(int i = 0; i < G2[now.S].size(); ++i)
		{
			if(flag2[G2[now.S][i]] > now.F + c[now.S])
			{
				flag2[G2[now.S][i]] = now.F + c[now.S];	
				pq.push(MP(now.F + c[now.S], G2[now.S][i]));
			}
		}
	}
}
int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; ++i)
		scanf("%d%d", c + i, r + i);
	for(int i = 0; i < K; ++i)
	{
		int in1, in2;
		scanf("%d%d", &in1, &in2);
		--in1; --in2;
		G[in1].push_back(in2);
		G[in2].push_back(in1);
	}
	fill(flag2 + 1, flag2 + N, INT_MAX);
	for(int i = 0; i < N; ++i)
		bfs(i);
	dijkstra(0);
	cout << flag2[N - 1] << endl;
}