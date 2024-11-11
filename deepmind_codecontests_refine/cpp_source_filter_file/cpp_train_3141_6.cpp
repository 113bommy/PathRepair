#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 1024000000,1024000000")
using namespace std;
const int N = 1e5 + 15;
int dep[N], sta[N], tp, deg[N];
vector<int> g[N], v[N];
int n, l, r, mid, mxl = 0, mnd = (0x3f3f3f3f);
void dfs1(int u, int f) {
  sta[++tp] = u;
  if (mxl < tp) {
    tp = mxl;
    r = u, mid = sta[tp + 1 >> 1];
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    dfs1(v, u);
  }
  tp--;
}
void dfs2(int u, int f) {
  dep[u] = dep[f] + 1;
  v[dep[u]].push_back(deg[u]);
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    dfs2(v, u);
  }
}
void chk(int u) {
  for (int i = 1; i <= n; i++) v[i].clear();
  dfs2(u, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < v[i].size(); j++)
      if (v[i][j] != v[i][j - 1]) return;
  printf("%d\n", u);
  exit(0);
}
void solve(int u, int f) {
  dep[u] = dep[f] + 1;
  if (deg[u] > 2) return;
  if (deg[u] == 1) {
    if (dep[u] < mnd) mnd = dep[u], r = u;
    return;
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    solve(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  dfs1(l = 1, mxl = 0);
  dfs1(l = r, mxl = 0);
  chk(l), chk(r), chk(mid);
  for (int i = 0; i < g[mid].size(); i++) {
    int u = g[mid][i];
    solve(u, 0);
  }
  chk(r);
  puts("-1");
  return 0;
}
