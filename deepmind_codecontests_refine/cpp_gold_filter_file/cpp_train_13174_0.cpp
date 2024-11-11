#include <bits/stdc++.h>
using namespace std;
int x, y, n, k, cnt;
int val[1010], nxt[1010], id[1010];
int f[1010][1010];
int f1[1010];
int ans[1010];
int dis[1010][1010];
int a[1010];
inline void Build(int x, int y) {
  cnt++;
  val[cnt] = y;
  nxt[cnt] = id[x];
  id[x] = cnt;
}
inline void dfs(int x, int fa) {
  for (int i = 1; i <= n; ++i) f[i][x] = a[dis[i][x]] + k;
  for (int i = id[x]; i; i = nxt[i]) {
    int y = val[i];
    if (y == fa) continue;
    dfs(y, x);
    for (int j = 1; j <= n; ++j)
      f[j][x] = f[j][x] + min(f[j][y] - k, f[f1[y]][y]);
  }
  f1[x] = 1;
  for (int i = 1; i <= n; ++i)
    if (f[i][x] < f[f1[x]][x]) f1[x] = i;
}
inline void tong(int x, int fa, int v) {
  for (int i = id[x]; i; i = nxt[i]) {
    int y = val[i];
    if (y == fa) continue;
    if (f[f1[y]][y] > f[v][y] - k)
      ans[y] = v;
    else
      ans[y] = f1[y];
    tong(y, x, ans[y]);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) dis[i][i] = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    dis[x][y] = 1;
    dis[y][x] = 1;
    Build(x, y), Build(y, x);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        if (dis[j][k] > dis[j][i] + dis[i][k])
          dis[j][k] = dis[j][i] + dis[i][k];
  dfs(1, 0);
  printf("%d\n", f[f1[1]][1]);
  ans[1] = f1[1];
  tong(1, 0, ans[1]);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
