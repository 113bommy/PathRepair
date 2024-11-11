#include <bits/stdc++.h>
using namespace std;
const int max_n = 100010;
int par[max_n], Rank[max_n];
int find(int v) {
  if (v == par[v]) return v;
  return par[v] = find(par[v]);
}
void unite(int u, int v) {
  if (find(u) == find(v)) return;
  int x = find(u), y = find(v);
  if (Rank[x] >= Rank[y]) {
    par[y] = x;
    if (Rank[y] == Rank[x]) Rank[x]++;
  } else
    par[x] = y;
}
struct Edge {
  int from, to, nol;
  long long len;
};
struct cmp {
  bool operator()(Edge A, Edge B) { return A.len < B.len; }
};
vector<Edge> E;
vector<pair<long long, long long> > G[max_n];
int n, m;
int Tree[max_n * 10] = {0};
pair<long long, long long> Ver[max_n];
void MST() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    Rank[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, len;
    scanf("%d%d%d", &u, &v, &len);
    E.push_back({u, v, i, len});
    Ver[i] = {u, v};
  }
  sort(E.begin(), E.end(), cmp());
  for (Edge e : E) {
    int u = e.from, v = e.to;
    if (find(u) != find(v)) {
      G[u].push_back({v, e.len});
      G[v].push_back({u, e.len});
      Tree[e.nol] = 1;
      unite(u, v);
    }
  }
}
long long Par[20][max_n], Dis[20][max_n];
int Depth[max_n];
void dfs(int v, int p, int d) {
  Depth[v] = d;
  Par[0][v] = p;
  for (auto u : G[v]) {
    if (u.first != p) {
      Dis[0][u.first] = u.second;
      dfs(u.first, v, d + 1);
    }
  }
}
void INIT() {
  Dis[0][1] = 0;
  dfs(1, -1, 0);
  for (int k = 0; k < 19; k++) {
    for (int v = 1; v <= n; v++) {
      if (Par[k][v] < 0) {
        Par[k + 1][v] = -1;
        Dis[k + 1][v] = Dis[k][v];
      } else {
        Par[k + 1][v] = Par[k][Par[k][v]];
        Dis[k + 1][v] = max(Dis[k][v], Dis[k][Par[k][v]]);
      }
    }
  }
}
long long LCA(int u, int v) {
  long long res = 0;
  if (Depth[v] < Depth[u]) swap(u, v);
  for (int i = 0; i < 20; i++) {
    if ((Depth[v] - Depth[u]) >> i & 1) {
      res = max(res, Dis[i][v]);
      v = Par[i][v];
    }
  }
  if (u == v) return res;
  for (int i = 19; i >= 0; i--) {
    if (Par[i][u] != Par[i][v]) {
      res = max(Dis[i][u], res);
      res = max(Dis[i][v], res);
      u = Par[i][u];
      v = Par[i][v];
    }
  }
  res = max(res, Dis[0][v]);
  res = max(res, Dis[0][u]);
  return res;
}
int main() {
  MST();
  INIT();
  for (int i = 1; i <= m; i++) {
    if (!Tree[i]) {
      int u = Ver[i].first, v = Ver[i].second;
      printf("%d\n", LCA(u, v));
    }
  }
  return 0;
}
