#include <bits/stdc++.h>
using namespace std;
const int maxn = 100009, maxm = 1000009, INF = 1e9;
struct edge {
  int u, v, w, f, c;
};
struct flows {
  int n, s, t, limit, a[maxn], inq[maxn], q[maxn];
  int m, head[maxn], link[maxm], p[maxn];
  edge e[maxm];
  long long d[maxn];
  void init(int _n, int _limit = 0) {
    n = _n;
    m = 0;
    limit = _limit;
    memset(head, -1, sizeof head);
  }
  void addEdge(int u, int v, int c, int w) {
    e[m].u = u;
    e[m].v = v;
    e[m].f = 0;
    e[m].c = c;
    e[m].w = w;
    link[m] = head[u];
    head[u] = m++;
    e[m].u = v;
    e[m].v = u;
    e[m].f = 0;
    e[m].c = 0;
    e[m].w = -w;
    link[m] = head[v];
    head[v] = m++;
  }
  bool SPFA(int s, int t, int &flow, long long &cost) {
    int l = 0, r = 0, u;
    memset(d, 0x3f, sizeof d);
    memset(inq, 0, sizeof inq);
    d[s] = 0;
    q[((r++) % maxn)] = s;
    a[s] = INF;
    while (l < r) {
      u = q[((l++) % maxn)];
      inq[u] = 0;
      for (int k = (head[u]); ~k; k = link[k])
        if (e[k].f < e[k].c && d[u] + e[k].w < d[e[k].v]) {
          d[e[k].v] = d[u] + e[k].w;
          a[e[k].v] = min(a[u], e[k].c - e[k].f);
          p[e[k].v] = k;
          if (!inq[e[k].v]) {
            q[((r++) % maxn)] = e[k].v;
            inq[e[k].v] = 1;
          }
        }
    }
    if (d[t] >= 1e18) return false;
    flow += a[t];
    cost += a[t] * d[t];
    u = t;
    while (u != s) {
      e[p[u]].f += a[t];
      e[p[u] ^ 1].f -= a[t];
      u = e[p[u]].u;
    }
    return true;
  }
  long long MinCost(int s, int t) {
    int flow = 0;
    long long cost = 0, res = 1e18;
    while (SPFA(s, t, flow, cost)) res = min(res, cost);
    if (flow < limit) return -1;
    return cost;
  }
} G;
int n, K, S0, S, T, a[maxn], c[maxn];
int main() {
  scanf("%d%d", &n, &K);
  for (int i = (1); i <= int(n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= int(n); i++) scanf("%d", &c[i]);
  S0 = 2 * n + 1;
  S = S0 + 1;
  T = S + 1;
  G.init(T);
  G.addEdge(S0, S, K, 0);
  for (int i = (1); i <= int(n); i++) {
    G.addEdge(S, i, 1, c[a[i]]);
    G.addEdge(i, i + n, 1, -INF);
    G.addEdge(i + n, T, 1, 0);
  }
  for (int i = (1); i <= int(n); i++)
    for (int j = (i + 1); j <= int(n); j++)
      G.addEdge(i + n, j, 1, (a[i] != a[j]) * c[a[j]]);
  printf("%I64d\n", G.MinCost(S0, T) + 1LL * INF * n);
  return 0;
}
