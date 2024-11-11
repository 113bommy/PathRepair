#include <bits/stdc++.h>
using namespace std;
vector<int> g[400100];
int c = 0;
int son[400100], a[400100], f[400100], deg[400100];
int dfs(int u, int fa, int ma, int dep, int &max_dep) {
  c++;
  max_dep = max(max_dep, dep);
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa || a[v] != ma) continue;
    son[u]++;
    dfs(v, u, ma, dep + 1, max_dep);
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  int ma = -0x7fffffff;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i]);
    ma = max(ma, a[i]);
  }
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[v].push_back(u);
    g[u].push_back(v);
    if (a[u] == ma) deg[v]++;
    if (a[v] == ma) deg[u]++;
  }
  int cnt = 0, p;
  for (int i = (1); i <= (n); i++)
    if (a[i] == ma) {
      cnt++;
      p = i;
    }
  if (cnt == 1) {
    for (int i = 0; i < g[p].size(); i++) {
      int v = g[p][i];
      f[v] = 1;
    }
    for (int i = (1); i <= (n); i++)
      if (f[i])
        ma = max(ma, a[i] + 1);
      else if (i != p)
        ma = max(a[i] + 2, ma);
    printf("%d\n", ma);
  } else {
    int max_dep = 0;
    c = 0;
    dfs(p, -1, ma, 0, max_dep);
    if (c < cnt) {
      int flag = 0;
      for (int i = (1); i <= (n); i++)
        if (deg[i] == cnt) {
          flag = 1;
          break;
        }
      if (flag)
        printf("%d\n", ma + 1);
      else
        printf("%d\n", ma + 2);
    } else {
      if (max_dep == 2) {
        if (son[p] == 1)
          printf("%d\n", ma + 1);
        else
          printf("%d\n", ma + 2);
      } else if (max_dep > 2)
        printf("%d\n", ma + 2);
      else
        printf("%d\n", ma + 1);
    }
  }
}
