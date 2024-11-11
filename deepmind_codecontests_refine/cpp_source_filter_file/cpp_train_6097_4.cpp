#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
struct Edge {
  int w, c;
  int u, v;
  int ind;
} e[maxn];
bool operator<(Edge a, Edge b) { return a.w < b.w; }
int dsu_par[maxn];
int dsu_get(int v) {
  if (v == dsu_par[v]) return v;
  return dsu_par[v] = dsu_get(dsu_par[v]);
}
bool dsu_merge(int u, int v) {
  if (dsu_get(u) == dsu_get(v)) return false;
  dsu_par[dsu_get(u)] = dsu_get(v);
  return true;
}
vector<pair<int, int>> neigh[maxn];
int par[20][maxn];
int maxEdge[20][maxn];
int depth[maxn];
void dfs(int v, int p) {
  par[0][v] = p;
  for (auto ee : neigh[v]) {
    int u = ee.first;
    if (u == p) continue;
    depth[u] = depth[v] + 1;
    par[0][u] = v;
    maxEdge[0][u] = e[ee.second].w;
    dfs(u, v);
  }
}
int get(int u, int v) {
  int ret = 0;
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (depth[par[i][u]] >= depth[v]) {
      ret = max(ret, maxEdge[i][u]);
      u = par[i][u];
    }
  }
  for (int i = 19; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      ret = max(ret, maxEdge[i][u]);
      ret = max(ret, maxEdge[i][v]);
      u = par[i][u];
      v = par[i][v];
    }
  }
  if (u != v) {
    ret = max(ret, maxEdge[0][u]);
    ret = max(ret, maxEdge[0][v]);
  }
  return ret;
}
int main() {
  int n, m, S;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &e[i].w);
    e[i].ind = i + 1;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &e[i].c);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &e[i].u, &e[i].v);
  }
  scanf("%d", &S);
  sort(e, e + m);
  for (int v = 1; v <= n; v++) dsu_par[v] = v;
  long long initSum = 0;
  for (int i = 0; i < m; i++) {
    if (dsu_merge(e[i].u, e[i].v)) {
      initSum += e[i].w;
      neigh[e[i].u].push_back(make_pair(e[i].v, i));
      neigh[e[i].v].push_back(make_pair(e[i].u, i));
    }
  }
  dfs(1, 1);
  for (int i = 0; i < 19; i++) {
    for (int v = 1; v <= n; v++) {
      par[i + 1][v] = par[i][par[i][v]];
      maxEdge[i + 1][v] = max(maxEdge[i][v], maxEdge[i][par[i][v]]);
    }
  }
  long long ans = initSum;
  int ch;
  for (int i = 0; i < m; i++) {
    int cost = get(e[i].u, e[i].v);
    if (initSum + e[i].w - cost + S / e[i].c <= ans) {
      ans = initSum + e[i].w - cost + S / e[i].c;
      ch = i;
    }
  }
  printf("%I64d\n", ans);
  for (int v = 1; v <= n; v++) dsu_par[v] = v;
  dsu_merge(e[ch].u, e[ch].v);
  printf("%d %d\n", e[ch].ind, e[ch].w - S / e[ch].c);
  for (int i = 0; i < m; i++) {
    if (dsu_merge(e[i].u, e[i].v)) {
      printf("%d %d\n", e[i].ind, e[i].w);
    }
  }
}
