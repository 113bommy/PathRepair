#include <bits/stdc++.h>
using namespace std;
vector<int> e[100010];
int p[100010][11], sz[100010];
void gg(int val, int u) {
  sz[u] = 0;
  int q = sqrt(val + .5);
  for (int i = 2; i <= q; ++i) {
    if (val % i == 0) {
      p[u][sz[u]++] = i;
      while (val % i == 0) val /= i;
    }
  }
  if (val != 1) p[u][sz[u]++] = val;
}
int a[100010];
int ans[100010];
bool vis[1000010];
int madep[1000010];
int st[1000010], top;
void dfs(int u, int fa, int change) {
  ans[u] = -1;
  if (change == -1 || change == u) gg(a[u], u);
  int tmpd = -1;
  for (int i = 0; i < sz[u]; ++i) {
    int v = p[u][i];
    if (madep[v] > tmpd) tmpd = madep[v];
  }
  if (tmpd != -1) ans[u] = st[tmpd];
  int tmp[11];
  for (int i = 0; i < sz[u]; ++i) {
    int v = p[u][i];
    if (madep[v] != -1)
      tmp[i] = madep[v];
    else
      tmp[i] = -1, vis[v] = true;
    madep[v] = top;
  }
  st[top++] = u;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs(v, u, change);
  }
  for (int i = 0; i < sz[u]; ++i) {
    int v = p[u][i];
    if (tmp[i] == -1) madep[v] = -1;
    madep[v] = tmp[i];
  }
  --top;
}
int main() {
  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    for (int i = 0; i <= n; ++i) e[i].clear();
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(madep, -1, sizeof(madep));
    top = 0;
    dfs(1, -1, -1);
    for (int i = 0; i < q; ++i) {
      int op, u;
      scanf("%d%d", &op, &u);
      if (op == 1)
        printf("%d\n", ans[u]);
      else {
        scanf("%d", &a[u]);
        dfs(1, -1, u);
      }
    }
  }
  return 0;
}
