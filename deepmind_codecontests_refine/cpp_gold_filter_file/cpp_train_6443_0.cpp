#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, f, n) for(int i = (int)(f); i < (int)(n); i++)

typedef pair<int, int> P;

const int inf = 1 << 25;

struct edge
{
  int to, cost;
  edge(){}
  edge(int to, int cost):to(to), cost(cost){}
};

vector< vector<edge> > graph;
vector< vector<int> > mincost;

void dijkstra(int s)
{
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, s));
  mincost[s][s] = 0;
  while(!que.empty()) {
    int cost, now;
    tie(cost, now) = que.top(); que.pop();
    if(mincost[s][now] < cost) continue;
    for(edge& e : graph[now]) {
      if(e.cost + cost < mincost[s][e.to]) {
	mincost[s][e.to] = e.cost + cost;
	que.push(P(mincost[s][e.to], e.to));
      }
    }
  }
  //return *max_element(all(mincost[s]));
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, R;
  cin >> N >> R;
  graph.resize(N);
  rep(i, R) {
    int s, t, d;
    cin >> s >> t >> d; s--, t--;
    graph[s].emplace_back(t, d);
    graph[t].emplace_back(s, d);
  }

  mincost.resize(N, vector<int>(N, inf));
  int maxdist = 0;
  rep(i, N) dijkstra(i); //maxdist = max(maxdist, dijkstra(i));
  rep(i, N) reps(j, i+1, N) maxdist = max(maxdist, mincost[i][j]);

  vector<P> ep;
  rep(i, N) reps(j, i+1, N) {
    if(mincost[i][j] == maxdist) ep.emplace_back(i, j);
  }

  vector<int> ans;
  rep(i, N) {
    bool flag = true;
    for(auto& p : ep) {
      int s, t; tie(s, t) = p;
      if(mincost[s][i] + mincost[i][t] == maxdist) flag = false;
    }
    if(flag) ans.push_back(i+1);
  }
  
  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i] << endl;
  
  return 0;
}