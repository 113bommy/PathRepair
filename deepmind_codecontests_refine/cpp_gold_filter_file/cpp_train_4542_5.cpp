#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, weigh, nxt, start;
} edge[200];
int size[70], n, x, y, z, s, m, cnt, head[70];
int ans, f[70][70][70][70], g[70][70];
void addedge(int x, int y, int z) {
  edge[++cnt].to = y;
  edge[cnt].weigh = z;
  edge[cnt].nxt = head[x];
  head[x] = cnt;
}
void Dfs(int x, int fa) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int upup = edge[i].to;
    if (upup == fa) continue;
    Dfs(upup, x);
    size[x] += size[upup];
  }
}
int dfs(int x, int y, int cnt, int tot, int z) {
  if (!tot) return 0;
  if (!cnt) return 0x3f3f3f3f;
  if (f[x][y][cnt][tot] != 0x3f3f3f3f) return f[x][y][cnt][tot];
  if (edge[head[x]].to == y && !edge[head[x]].nxt)
    return f[x][y][cnt][tot] = z + dfs(y, x, tot - cnt, tot - cnt, z);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int upup = edge[i].to;
    if (upup == y) continue;
    for (int j = 0; j <= tot; j++) dfs(upup, x, j, tot, edge[i].weigh);
  }
  memset(g, 0, sizeof(g));
  g[0][0] = 0x3f3f3f3f;
  int TOT = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int upup = edge[i].to;
    if (upup == y) continue;
    ++TOT;
    for (int j = 0; j <= tot; j++)
      for (int k = 0; k <= tot - j; k++)
        g[TOT][j + k] =
            max(g[TOT][j + k],
                min(g[TOT - 1][j], dfs(upup, x, k, tot, edge[i].weigh)));
  }
  return f[x][y][cnt][tot] = g[TOT][cnt] + z;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d%d", &x, &y, &z);
    addedge(x, y, z);
    addedge(y, x, z);
  }
  scanf("%d%d", &s, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    size[x]++;
  }
  memset(f, 0x3f, sizeof(f));
  Dfs(s, 0);
  ans = 0x3f3f3f3f;
  for (int i = head[s]; i; i = edge[i].nxt) {
    int upup = edge[i].to;
    ans = min(ans, dfs(upup, s, size[upup], m, edge[i].weigh));
  }
  printf("%d\n", ans);
}
