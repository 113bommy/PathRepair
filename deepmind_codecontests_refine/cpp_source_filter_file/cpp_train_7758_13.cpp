#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
const int inf = (1e9) + 10;
const long double eps = 1e-10;
struct FlowEdge {
  int v, u;
  long long cap, flow = 0;
  FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }
  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1) continue;
        if (level[edges[id].u] != -1) continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  long long dfs(int v, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0) continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
  long long flow() {
    long long f = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};
int n, m;
int bear;
vector<pair<int, int>> edges[maxn];
long long flow(long double mid) {
  Dinic dinic(n + 1, 1, n);
  for (int u = (int)1; u <= (int)n; u++) {
    for (auto it : edges[u]) {
      int v = it.first;
      int cap = it.second;
      dinic.add_edge(u, v, floor(cap / mid));
    }
  }
  return dinic.flow();
}
int main() {
  cin >> n >> m >> bear;
  for (int i = (int)1; i <= (int)m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
  }
  long double lo = 0;
  long double hi = 1e7;
  long double res = 0;
  while (hi - lo > eps) {
    long double mid = (hi + lo) / 2.0;
    long double ans = flow(mid);
    if (ans < bear) {
      hi = mid;
    } else {
      res = max(res, bear * mid);
      lo = mid;
    }
  }
  cout << setprecision(10) << fixed << res << endl;
}
