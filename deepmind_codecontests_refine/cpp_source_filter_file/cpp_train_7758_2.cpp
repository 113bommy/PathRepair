#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b;
  long double cap, tcap, flow;
  edge(int a, int b, long double tcap) : a(a), b(b), tcap(tcap) {}
};
const int MAXN = 50;
const long long INF = 1e18;
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
void add_edge(int a, int b, int cap) {
  edge e1 = edge(a, b, cap);
  edge e2 = edge(b, a, 0);
  g[a].push_back((int)e.size());
  e.push_back(e1);
  g[b].push_back((int)e.size());
  e.push_back(e2);
}
bool bfs() {
  int qh = 0, qt = 0;
  q[qt++] = s;
  memset(d, -1, n * sizeof d[0]);
  d[s] = 0;
  while (qh < qt && d[t] == -1) {
    int v = q[qh++];
    for (size_t i = 0; i < g[v].size(); ++i) {
      int id = g[v][i], to = e[id].b;
      if (d[to] == -1 && e[id].flow < e[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[t] != -1;
}
long double dfs(int v, long double flow) {
  if (abs(flow) <= 1e-9) return 0;
  if (v == t) return flow;
  for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]], to = e[id].b;
    if (d[to] != d[v] + 1) continue;
    long double pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
    if (pushed) {
      e[id].flow += pushed;
      e[id ^ 1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
long double dinic() {
  long double flow = 0;
  for (;;) {
    if (!bfs()) break;
    memset(ptr, 0, n * sizeof ptr[0]);
    while (long double pushed = dfs(s, INF)) flow += pushed;
  }
  return flow;
}
int main() {
  scanf("%d", &n);
  int m, k;
  scanf("%d%d", &m, &k);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add_edge(--x, --y, z);
  }
  s = 0;
  t = n - 1;
  long double l = 0, r = 1e6;
  for (int sc = 0; sc < 200; sc++) {
    long double md = (l + r) / 2;
    for (edge& ed : e) {
      ed.flow = 0;
      ed.cap = ed.tcap / md;
    }
    long double flow = dinic();
    if (flow >= k) {
      l = md;
    } else {
      r = md;
    }
  }
  cout.precision(11);
  cout << fixed << l * k;
  return 0;
}
