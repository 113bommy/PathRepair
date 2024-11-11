#include <bits/stdc++.h>
using namespace std;
vector<int> un, sz;
vector<vector<int>> g;
int n, k;
long long ans = 0;
void dfs1(int v, int l) {
  for (int u : g[v]) {
    if (u == l) continue;
    dfs1(u, v);
    sz[v] += sz[u];
  }
  if (un[v]) sz[v]++;
}
void dfs2(int v, int l) {
  for (int u : g[v]) {
    if (u == l) continue;
    ans += min(sz[u], 2 * k - sz[u]);
    dfs2(u, v);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  un.resize(n);
  sz.resize(n);
  g.resize(n);
  for (int i = 0; i < 2 * k; i++) {
    int x;
    scanf("%d", &x);
    un[x - 1] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs1(0, 0);
  dfs2(0, 0);
  printf("%d", ans);
  return 0;
}
