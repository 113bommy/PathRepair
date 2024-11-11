#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, capacity, cost, rev;
  edge() {}
  edge(int to, int _capacity, int _cost, int _rev)
      : to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
const int inf = 0x3f3f3f3f;
struct Min_Cost_Max_Flow {
  int V, H[6555 + 5], dis[6555 + 5], PreV[6555 + 5], PreE[6555 + 5];
  vector<edge> G[6555 + 5];
  void Init(int n) {
    V = n;
    for (int i = 0; i <= V; ++i) G[i].clear();
  }
  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
  }
  int minCost(int s, int t, int f) {
    int flow = 0;
    int res = 0;
    fill(H, H + 1 + V, 0);
    while (f) {
      priority_queue<pair<int, int>, vector<pair<int, int> >,
                     greater<pair<int, int> > >
          q;
      fill(dis, dis + 1 + V, inf);
      dis[s] = 0;
      q.push(pair<int, int>(0, s));
      while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        int v = now.second;
        if (dis[v] < now.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
          edge& e = G[v][i];
          if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
            dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
            PreV[e.to] = v;
            PreE[e.to] = i;
            q.push(pair<int, int>(dis[e.to], e.to));
          }
        }
      }
      if (dis[t] == inf) break;
      for (int i = 0; i <= V; ++i) H[i] += dis[i];
      int d = f;
      for (int v = t; v != s; v = PreV[v])
        d = min(d, G[PreV[v]][PreE[v]].capacity);
      f -= d;
      flow += d;
      res += d * H[t];
      for (int v = t; v != s; v = PreV[v]) {
        edge& e = G[PreV[v]][PreE[v]];
        e.capacity -= d;
        G[v][e.rev].capacity += d;
      }
    }
    return res;
  }
} mcmf;
int main() {
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  int p = n + n + 2;
  mcmf.Init(n * p + 1);
  for (int i = 0; i < k; i++) {
    int u;
    cin >> u;
    mcmf.add_edge(0, u, 1, 0);
  }
  vector<pair<int, int> > edge = vector<pair<int, int> >(m);
  for (int i = 0; i < m; i++) cin >> edge[i].first >> edge[i].second;
  int tar = n * p + 1;
  for (int t = 0; t < p - 1; t++) {
    for (pair<int, int> e : edge) {
      for (int j = 1; j <= k; j++) {
        mcmf.add_edge(e.first + t * n, e.second + (t + 1) * n, 1,
                      d * (j * 2 - 1));
        mcmf.add_edge(e.second + t * n, e.first + (t + 1) * n, 1,
                      d * (j * 2 - 1));
      }
    }
    for (int i = 2; i <= n; i++) {
      mcmf.add_edge(i + t * n, i + (t + 1) * n, k, 0);
    }
    mcmf.add_edge(1 + t * n, tar, k, t * c);
  }
  cout << mcmf.minCost(0, tar, k) << endl;
  return 0;
}
