#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, u, c, f, r;
  Edge(){};
  Edge(int v, int u, int c, int f, int r) : v(v), u(u), c(c), f(f), r(r){};
};
const int N = 500, inf = 1000000000;
Edge g[N][N];
int n, m, sz[N], s, t, c[N], p[101][5001], kol1[5001], kol2[5001], kol[5001];
void add_edge(int a, int b, int u, int c) {
  Edge e1(b, u, c, 0, sz[b]), e2(a, 0, -c, 0, sz[a]);
  g[a][sz[a]++] = e1;
  g[b][sz[b]++] = e2;
}
int MinCostFlow() {
  int dist[N], p[N], pr[N], pl[N], flow = 0, cost = 0, nv = t;
  bool used[N];
  memset(pl, 0, sizeof(pl));
  while (true) {
    memset(used, false, sizeof(used));
    for (int i = 1; i <= nv; i++) dist[i] = inf;
    dist[s] = 0;
    while (true) {
      int v, d = inf;
      for (int i = 1; i <= nv; i++)
        if (!used[i] && dist[i] < d) {
          v = i;
          d = dist[i];
        }
      if (d == inf) break;
      used[v] = true;
      for (int i = 0; i <= sz[v] - 1; i++)
        if (g[v][i].f < g[v][i].u &&
            dist[g[v][i].v] > d + pl[v] - pl[g[v][i].v] + g[v][i].c) {
          dist[g[v][i].v] = d + pl[v] - pl[g[v][i].v] + g[v][i].c;
          p[g[v][i].v] = v;
          pr[g[v][i].v] = i;
        }
    }
    if (dist[t] == inf) break;
    int v = t, addflow = inf;
    while (v != s) {
      int u = p[v], j = pr[v];
      addflow = min(addflow, g[u][j].u - g[u][j].f);
      v = u;
    }
    v = t;
    while (v != s) {
      int u = p[v], j = pr[v];
      g[u][j].f += addflow;
      g[v][g[u][j].r].f -= addflow;
      v = u;
    }
    for (int i = 1; i <= nv; i++) pl[i] += dist[i];
    for (int i = 1; i <= nv; i++) pl[i] = max(pl[i], -inf);
    for (int i = 1; i <= nv; i++) pl[i] = min(pl[i], inf);
    flow += addflow;
  }
  return flow;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> c[i];
  memset(kol, 0, sizeof(kol));
  memset(sz, 0, sizeof(sz));
  for (int i = 1; i <= n; i++) kol[c[i]]++;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      if (i != j) {
        add_edge(i, j + m, inf, 1);
      }
  s = 2 * m + 1;
  t = 2 * m + 2;
  for (int i = 1; i <= m; i++) add_edge(s, i, kol[i], 1);
  for (int i = 1; i <= m; i++) add_edge(i + m, t, kol[i], 1);
  int ans = MinCostFlow();
  cout << ans << endl;
  memset(kol1, 0, sizeof(kol1));
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= sz[i] - 1; j++) {
      if (g[i][j].f > 0 && g[i][j].v <= 2 * m) {
        for (int r = 1; r <= g[i][j].f; r++) {
          kol1[i]++;
          p[i][kol1[i]] = g[i][j].v - m;
        }
      }
    }
  }
  memset(kol2, 0, sizeof(kol2));
  for (int i = 1; i <= n; i++) {
    kol2[c[i]]++;
    if (kol2[c[i]] > kol1[c[i]]) {
      cout << c[i] << " " << c[i] << endl;
      continue;
    }
    cout << c[i] << " " << p[c[i]][kol2[c[i]]] << endl;
  }
  return 0;
}
