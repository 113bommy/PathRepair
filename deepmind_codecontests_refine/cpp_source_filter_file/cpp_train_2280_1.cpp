#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define F first
#define S second
#define MP make_pair
#define int long long
#define INF long(1e18)
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;


int n, m, k, s, pp, q, ans[100001];
int dead[100001];
vector<int> road[100001], root;
void bfs(int sta)
{
  queue<P> que;
  que.push(MP(sta, 0));
  dead[sta] = -1;
  while(!que.empty())
  {
    P p = que.front();
    que.pop();
    if(p.S == s) continue;
    for(int i = 0; i < road[p.F].size(); i++)
    {
      if(!dead[p.F][i] || dead[road[p.F][i]] > p.S + 1)
      {
        que.push(MP(road[p.F][i], p.S + 1));
        dead[road[p.F][i]] = p.S + 1;
      }
    }
  }
}
void dijkstra(){
  priority_queue<P> pq;
  pq.push(MP(0, 1));
  ans[1] = 0;
  while(!pq.empty())
  {
    P p = pq.top();
    pq.pop();
    for(int i = 0; i < road[p.S].size(); i++)
    {
      if(dead[road[p.S][i]] == -1) continue;
      if(!dead[road[p.S][i]] && ans[road[p.S][i]] < p.F - pp)
      {
        pq.push(MP(p.F - pp, road[p.S][i]));
        ans[road[p.S][i]] = p.F - pp;
      }
      else if(ans[road[p.S][i]] < p.F - q){
        pq.push(MP(p.F - q, road[p.S][i]));
        ans[road[p.S][i]] = p.F - q;
      }
    }
  }
}
signed main()
{
  cin >> n >> m >> k >> s >> pp >> q;
  for(int i = 0; i < k; i++)
  {
    int a;
    cin >> a;
    root.push_back(a);
  }
  for(int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    road[a].push_back(b);
    road[b].push_back(a);
  }
  for(int i = 0; i < k; i++)
  {
    bfs(root[i]);
  }
  fill(ans, ans + n + 1, -INF);
  dijkstra();
  if(!dead[n])
    cout << -ans[n] - pp << endl;
  else
    cout << -ans[n] - q <<endl;
}