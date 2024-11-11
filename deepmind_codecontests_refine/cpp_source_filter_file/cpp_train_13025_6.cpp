#include <bits/stdc++.h>
using namespace std;
const long long N = 10004;
const long long INF = 1LL * 1001 * 1001 * 1001 * 1001 * 1001 * 1001;
struct edge {
  long long a, b, cap, flow;
  edge(long long a, long long b, long long cap)
      : a(a), b(b), cap(cap), flow(0) {}
  long long other(long long v) { return v == a ? b : a; }
  long long cap_to(long long v) { return v == b ? cap - flow : flow; }
  void add_flow(long long v, long long f) { flow += (v == b ? f : -f); }
};
vector<edge> e;
vector<long long> g[N];
long long d[N], p[N], pos[N];
long long t, s, n, m, ans;
long long bfs(long long u) {
  queue<long long> q;
  q.push(u);
  d[u] = 1;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    if (u == t) return 1;
    for (long long i = 0; i < g[u].size(); i++) {
      long long to = e[g[u][i]].other(u);
      if (!d[to] && e[g[u][i]].cap_to(to)) {
        d[to] = d[u] + 1;
        p[to] = g[u][i];
        q.push(to);
      }
    }
  }
  return 0;
}
long long dfs(long long u) {
  if (u == t) return 1;
  for (; pos[u] < g[u].size(); pos[u]++) {
    long long to = e[g[u][pos[u]]].other(u);
    if (d[to] == d[u] + 1 && e[g[u][pos[u]]].cap_to(to)) {
      p[to] = g[u][pos[u]];
      if (dfs(to)) return 1;
    }
  }
  return 0;
}
long long dinic() {
  long long flow = 0;
  while (1) {
    memset(d, 0, sizeof(d));
    if (!bfs(s)) return flow;
    memset(pos, 0, sizeof(pos));
    while (dfs(s)) {
      long long cur_flow = INF;
      for (long long v = t; v != s; v = e[p[v]].other(v))
        cur_flow = min(cur_flow, e[p[v]].cap_to(v));
      flow += cur_flow;
      for (long long v = t; v != s; v = e[p[v]].other(v))
        e[p[v]].add_flow(v, cur_flow);
    }
  }
}
void add(long long a, long long b, long long c) {
  e.push_back(edge(a, b, c));
  g[a].push_back(e.size() - 1);
  g[b].push_back(e.size() - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  t = 2 * n + 1;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    add(s, i, x);
  }
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    ans += c;
    add(n + i, t, c);
    add(b, n + i, INF);
    add(a, n + i, INF);
  }
  long long flow = dinic();
  cout << ans - flow;
}
