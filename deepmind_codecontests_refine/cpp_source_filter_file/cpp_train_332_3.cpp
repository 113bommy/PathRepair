#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
int n, q, x, y, a, b, k, fa[maxn][20], dep[maxn];
vector<int> G[maxn];
void dfs(int u, int f) {
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    int v = G[u][i];
    if (v == f) continue;
    dfs(v, u);
  }
}
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 0; i < 20; ++i)
    if ((dep[x] - dep[y]) >> i & 1) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (fa[x][i] == fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return fa[x][0];
}
inline int getdis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i < 20; ++i)
    for (int j = 1; j <= n; ++j) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    int x1 = getdis(a, b);
    int x2 = 1 + getdis(a, x) + getdis(b, y);
    int x3 = 1 + getdis(a, y) + getdis(b, x);
    if (x1 <= k && x1 % 2 == k % 2)
      puts("YES");
    else if (x2 <= k && x2 % 2 == k % 2)
      puts("YES");
    else if (x3 <= k && x3 % 2 == k % 2)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
