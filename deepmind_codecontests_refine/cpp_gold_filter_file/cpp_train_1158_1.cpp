#include <bits/stdc++.h>
using namespace std;
const int maxn = 250003;
vector<int> g[maxn], h[maxn], bck[maxn];
int n, m, k, mxdep, mxi, fa[maxn], dep[maxn], ANS[maxn], CNT, RES[maxn][3];
bool vis[maxn];
void init(int u) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (vis[v]) {
      if (v != fa[u] && dep[v] < dep[u]) bck[u].push_back(v);
      continue;
    }
    fa[v] = u;
    dep[v] = dep[u] + 1;
    h[u].push_back(v), h[v].push_back(u);
    init(v);
  }
}
void dfs(int u, int last, int dep) {
  if (dep > mxdep) mxdep = dep, mxi = u;
  for (int v : h[u]) {
    if (v == last) continue;
    dfs(v, u, dep + 1);
  }
}
bool path(int u, int last, int aim) {
  if (u == aim) {
    ANS[++CNT] = u;
    return 1;
  }
  for (int v : h[u]) {
    if (v == last) continue;
    if (path(v, u, aim)) {
      ANS[++CNT] = u;
      return 1;
    }
  }
  return 0;
}
bool f(int u, int v) { return (dep[u] - dep[v]) % 3 != 1; }
void leaf(int u) {
  if (u != 1 && h[u].size() == 1) {
    RES[++CNT][0] = u;
    int x = bck[u][0], y = bck[u][1];
    if (dep[x] < dep[y]) swap(x, y);
    if (f(fa[u], x))
      RES[CNT][1] = fa[u], RES[CNT][2] = x;
    else if (f(fa[u], y))
      RES[CNT][1] = fa[u], RES[CNT][2] = y;
    else if (f(x, y))
      RES[CNT][1] = x, RES[CNT][2] = y;
    else
      assert(0);
    return;
  }
  for (int v : h[u]) {
    if (v == fa[u]) continue;
    leaf(v);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  init(1);
  mxdep = -1;
  dfs(1, 0, 0);
  mxdep = -1;
  int s = mxi;
  dfs(s, 0, 0);
  if (mxdep + 1 >= (n + k - 1) / k) {
    path(s, 0, mxi);
    printf("PATH\n%d\n", CNT);
    for (int i = 1; i <= CNT; i++) printf("%d%c", ANS[i], i < CNT ? ' ' : '\n');
    return 0;
  }
  leaf(1);
  printf("CYCLES\n");
  for (int i = 1; i <= k; i++) {
    printf("%d\n%d %d", dep[RES[i][1]] - dep[RES[i][2]] + 2, RES[i][0],
           RES[i][1]);
    int u = RES[i][1];
    while (u != RES[i][2]) {
      u = fa[u];
      printf(" %d", u);
    }
    puts("");
  }
  return 0;
}
