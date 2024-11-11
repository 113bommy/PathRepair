#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
template <int SZ>
struct Dinic {
  int N = 0, s, t;
  struct Edge {
    int to, rev;
    long long flow, cap;
    int id;
  };
  vector<Edge> adj[SZ];
  void addEdge(int u, int v, long long cap, int id = 0) {
    N = max(N, max(u, v) + 1);
    Edge a = {v, (int)adj[v].size(), 0, cap, id},
         b = {u, (int)adj[u].size(), 0, 0, id};
    adj[u].push_back(a), adj[v].push_back(b);
  }
  int lvl[SZ];
  typename vector<Edge>::iterator cur[SZ];
  bool bfs() {
    for (int i = 0; i < SZ; i++) lvl[i] = -1, cur[i] = adj[i].begin();
    queue<int> q({s});
    lvl[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &e : adj[u])
        if (lvl[e.to] == -1 && e.flow < e.cap) {
          q.push(e.to);
          lvl[e.to] = lvl[u] + 1;
        }
    }
    return lvl[t] >= 0;
  }
  long long dfs(int u, long long flow) {
    if (u == t || !flow) return flow;
    for (; cur[u] != adj[u].end(); cur[u]++) {
      Edge &e = *cur[u];
      if (lvl[e.to] != lvl[u] + 1 || e.flow == e.cap) continue;
      long long df = dfs(e.to, min(flow, e.cap - e.flow));
      if (df) {
        e.flow += df;
        adj[e.to][e.rev].flow -= df;
        return df;
      }
    }
    return 0;
  }
  long long maxFlow(int _s, int _t) {
    s = _s, t = _t;
    long long totFlow = 0;
    while (bfs()) {
      long long df = dfs(s, numeric_limits<long long>::max());
      while (df) {
        totFlow += df;
        df = dfs(s, numeric_limits<long long>::max());
      }
    }
    return totFlow;
  }
};
int n, m;
pair<int, int> p[MAX];
int ans[MAX];
bool f(int x, bool solve) {
  Dinic<MAX> Network;
  int s = 0, t = n + m + 1;
  for (int i = 1; i <= m; i++) {
    Network.addEdge(s, i, 1);
    Network.addEdge(i, m + p[i].first, 1, 1);
    Network.addEdge(i, m + p[i].second, 1, 2);
  }
  for (int i = 1; i <= n; i++) Network.addEdge(m + i, t, x);
  int flow = Network.maxFlow(s, t);
  if (!solve) return flow == m;
  for (int i = 1; i <= m; i++) {
    for (auto &e : Network.adj[i]) {
      if (e.flow > 0) ans[i] = e.id;
    }
  }
  cout << x << "\n";
  for (int i = 1; i <= m; i++) {
    if (ans[i] == 2)
      cout << p[i].second << " " << p[i].first << "\n";
    else
      cout << p[i].first << " " << p[i].second << "\n";
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n == 1) return cout << 0, 0;
  for (int i = 1; i <= m; i++) cin >> p[i].first >> p[i].second;
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (f(mid, 0))
      r = mid;
    else
      l = mid;
  }
  f(r, 1);
  return 0;
}
