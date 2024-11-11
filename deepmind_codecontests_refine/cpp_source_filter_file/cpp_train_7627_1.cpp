#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const long long INF = 1LL << 60;
struct Dinic {
  static const int MAXN = 20003;
  struct Edge {
    int u, v;
    long long cap, rest;
  };
  int n, m, s, t, d[MAXN], cur[MAXN];
  vector<Edge> edges;
  vector<int> G[MAXN];
  void init() {
    edges.clear();
    for (int i = 0; i < n; i++) G[i].clear();
    n = 0;
  }
  bool side[MAXN];
  void cut(int u) {
    side[u] = 1;
    for (int i : G[u]) {
      if (!side[edges[i].v] && edges[i].rest) cut(edges[i].v);
    }
  }
  int add_node() { return n++; }
  void add_edge(int u, int v, long long cap) {
    edges.push_back({u, v, cap, cap});
    edges.push_back({v, u, 0, 0LL});
    m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }
  bool bfs() {
    fill(d, d + n, -1);
    queue<int> que;
    que.push(s);
    d[s] = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int ei : G[u]) {
        Edge &e = edges[ei];
        if (d[e.v] < 0 && e.rest > 0) {
          d[e.v] = d[u] + 1;
          que.push(e.v);
        }
      }
    }
    return d[t] >= 0;
  }
  long long dfs(int u, long long a) {
    if (u == t || a == 0) return a;
    long long flow = 0, f;
    for (int &i = cur[u]; i < (int)G[u].size(); i++) {
      Edge &e = edges[G[u][i]];
      if (d[u] + 1 != d[e.v]) continue;
      f = dfs(e.v, min(a, e.rest));
      if (f > 0) {
        e.rest -= f;
        edges[G[u][i] ^ 1].rest += f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }
  long long maxflow(int _s, int _t) {
    s = _s, t = _t;
    long long flow = 0, mf;
    while (bfs()) {
      fill(cur, cur + n, 0);
      while ((mf = dfs(s, INF))) flow += mf;
    }
    return flow;
  }
} dinic;
void go() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }
  int r = 1e9 + 7, l = 0;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    dinic.init();
    dinic.n = n * 2 + 2;
    for (auto &i : v) {
      if (get<2>(i) <= mid) {
        dinic.add_edge(get<1>(i), n + get<2>(i), 1);
      }
    }
    for (int i = 1; i < n + 1; i++) {
      dinic.add_edge(0, i, 1);
      dinic.add_edge(n + i, 2 * n + 1, 1);
    }
    if (dinic.maxflow(0, 2 * n + 1) == n) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (l > 1e9) {
    cout << -1 << '\n';
  } else {
    cout << r << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    go();
  }
}
