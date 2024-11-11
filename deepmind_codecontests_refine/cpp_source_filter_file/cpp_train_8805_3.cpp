#include <bits/stdc++.h>
using namespace std;
const size_t maxn = 80 + 5;
const size_t maxv = maxn + 2;
const int inf = 2e9;
namespace network_flow {
struct Edge {
  int to, cap, cost, rev;
  Edge(int to = 0, int cap = 0, int cost = 0, int rev = 0)
      : to(to), cap(cap), cost(cost), rev(rev) {}
};
vector<Edge> g[maxv];
int dis[maxv], prevv[maxv], preve[maxv];
bool inque[maxv];
inline void add_edge(int u, int v, int cap, int cost) {
  g[u].emplace_back(v, cap, cost, g[v].size());
  g[v].emplace_back(v, 0, -cost, g[u].size() - 1);
}
int spfa(int s, int t) {
  fill(dis, dis + t + 1, inf);
  dis[s] = 0;
  queue<int> que;
  que.push(s);
  inque[s] = true;
  for (int v, i, _; !que.empty();) {
    v = que.front();
    que.pop();
    inque[v] = false;
    assert(v <= t);
    for (i = 0, _ = g[v].size(); i < _; ++i) {
      auto &e = g[v][i];
      if (e.cap > 0 && dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        prevv[e.to] = v;
        preve[e.to] = i;
        if (!inque[e.to]) {
          que.push(e.to);
          inque[e.to] = true;
        }
      }
    }
  }
  return dis[t];
}
int minimum_cost(int s, int t) {
  int ret = 0, d, f, v;
  while ((d = spfa(s, t)) < inf) {
    f = inf;
    for (v = t; v != s; v = prevv[v]) f = min(f, g[prevv[v]][preve[v]].cap);
    ret += d * f;
    for (v = t; v != s; v = prevv[v]) {
      g[prevv[v]][preve[v]].cap -= f;
      g[v][g[prevv[v]][preve[v]].rev].cap += f;
    }
  }
  return ret;
}
}  // namespace network_flow
int n, k, c[maxn], a[maxn], up[maxn];
int main() {
  cin >> n >> k;
  --k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  int sv = n + 1, tv = n + 2;
  network_flow::add_edge(sv, 1, k, 0);
  network_flow::add_edge(n, tv, k, 0);
  for (int i = 1; i < n; ++i) network_flow::add_edge(i, i + 1, k, 0);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += c[a[i]];
    if (up[a[i]]) {
      if (up[a[i]] == i - 1)
        res -= c[a[i]];
      else
        network_flow::add_edge(up[a[i]] + 1, i, 1, -c[a[i]]);
    }
    up[a[i]] = i;
  }
  res += network_flow::minimum_cost(sv, tv);
  printf("%d\n", res);
  return 0;
}
