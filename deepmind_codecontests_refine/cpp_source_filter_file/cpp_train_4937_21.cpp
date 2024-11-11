#include <bits/stdc++.h>
using namespace std;
int m, f[200005][20 + 5], dep[200005], l, r, len, n = 4;
vector<int> G[200005];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  for (int i = 0; i < G[x].size(); i++) {
    int tmp = G[x][i];
    if (tmp != fa) {
      f[tmp][0] = x;
      dfs(tmp, x);
    }
  }
}
void prepare() {
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= 4; i++) f[i][j] = f[f[i][j - 1]][j - 1];
}
void add(int &x, int maxdep) {
  for (int i = 20; i >= 0; i--)
    if (dep[f[x][i]] >= maxdep) x = f[x][i];
}
int Doubly(int x, int y) {
  if (dep[x] > dep[y]) add(x, dep[y]);
  if (dep[x] < dep[y]) add(y, dep[x]);
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  }
  return f[x][0];
}
int main() {
  G[1].push_back(2), G[1].push_back(3), G[1].push_back(4);
  dfs(1, 0);
  prepare();
  l = 2, r = 4, len = 2;
  scanf("%d", &m);
  while (m--) {
    int u;
    scanf("%d", &u);
    dep[n + 1] = dep[n + 2] = dep[u] + 1;
    f[n + 1][0] = f[n + 2][0] = u;
    for (int i = 1; i <= 20; i++)
      f[n + 1][i] = f[f[n + 1][i - 1]][i - 1],
            f[n + 2][i] = f[f[n + 2][i - 1]][i - 1];
    int lca1 = Doubly(l, u), lca2 = Doubly(r, u);
    int len1 = dep[l] - dep[lca1] + dep[u] - dep[lca1];
    int len2 = dep[r] - dep[lca2] + dep[u] - dep[lca2];
    if (len1 > len2 && len1 + 1 > len) {
      r = n + 1;
      len = len1 + 1;
      printf("%d\n", len);
    } else if (len2 > len1 && len2 + 1 > len) {
      l = n + 1;
      len = len2 + 1;
      printf("%d\n", len);
    } else {
      printf("%d\n", len);
    }
    n += 2;
  }
  return 0;
}
