#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> E[250005];
bool vis[250005];
int f[250005][29], dep[250005];
bool lef[250005];
void dfs(int fa, int u, int d) {
  f[u][0] = fa;
  vis[u] = 1;
  dep[u] = d;
  lef[u] = 1;
  for (int i = 0; i < E[u].size(); i++) {
    if (!vis[E[u][i]]) {
      dfs(u, E[u][i], d + 1);
      lef[u] = 0;
    }
  }
  return;
}
void pre() {
  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j <= n; j++) {
      f[j][i] = f[f[j][i - 1]][i - 1];
    }
  }
  return;
}
int g_lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 18; i >= 0; i--) {
    if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  }
  if (u == v) return u;
  for (int i = 18; i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  }
  return f[u][0];
}
int g_dis(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ans = 0;
  for (int i = 18; i >= 0; i--) {
    if (dep[f[u][i]] >= dep[v]) {
      ans += (1 << i);
      u = f[u][i];
    }
  }
  return ans;
}
int gdis(int u, int v) {
  int l = g_lca(u, v);
  return g_dis(l, u) + g_dis(v, l);
}
vector<int> ans;
void output(int x, int y) {
  int l = g_lca(x, y);
  for (int j = y; j != l; j = f[j][0]) printf("%d ", j);
  ans.clear();
  for (int j = x; j != l; j = f[j][0]) ans.push_back(j);
  printf("%d ", l);
  for (int j = ans.size() - 1; j >= 0; j--) printf("%d ", ans[j]);
  return;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(0, 1, 1);
  for (int i = 1; i <= n; i++) {
    if (1LL * dep[i] * k >= n) {
      printf("PATH\n");
      printf("%d\n", dep[i]);
      for (; i; i = f[i][0]) printf("%d ", i);
      return 0;
    }
  }
  pre();
  printf("CYCLES\n");
  int num = 0;
  for (int i = 1; i <= n && num < k; i++) {
    if (lef[i]) {
      int x = -1, y = -1;
      for (int j = 0; j < E[i].size() && (x == -1 || y == -1); j++) {
        if (E[i][j] != f[i][0]) {
          if (x == -1)
            x = E[i][j];
          else
            y = E[i][j];
        }
      }
      num++;
      int t;
      if ((t = gdis(x, y) + 2) % 3 != 0) {
        printf("%d\n", t);
        printf("%d ", i);
        output(x, y);
        printf("\n");
        continue;
      }
      if ((t = gdis(y, i) + 1) % 3 != 0) {
        printf("%d\n", t);
        output(y, i);
        printf("\n");
        continue;
      }
      printf("%d\n", gdis(x, i) + 1);
      output(x, i);
      printf("\n");
    }
  }
  return 0;
}
