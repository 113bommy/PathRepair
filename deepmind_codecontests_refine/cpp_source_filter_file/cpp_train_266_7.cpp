#include <bits/stdc++.h>
using namespace std;
const int S = 21;
const int N = 10005;
int n, m, t;
int f[1 << S], p[N], dis[N], a[N], b[N], q[N], c[S];
int g[S][S];
void bfs(int x) {
  memset(dis, -1, sizeof dis);
  int st = 0, ed = 1;
  q[0] = x;
  dis[x] = 0;
  while (st < ed) {
    int i = q[st++];
    for (int j = 1; j <= t; ++j) {
      if (i + p[j] <= n && dis[i + p[j]] == -1)
        dis[i + p[j]] = dis[i] + 1, q[ed++] = i + p[j];
      if (i - p[j] >= 0 && dis[i - p[j]] == -1)
        dis[i - p[j]] = dis[i] + 1, q[ed++] = i - p[j];
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    a[x] ^= 1;
    a[x + 1] ^= 1;
  }
  for (int i = 1; i <= t; ++i) scanf("%d", &p[i]);
  memset(b, -1, sizeof b);
  int s = 0;
  for (int i = 0; i <= n; ++i)
    if (a[i]) c[s] = i, b[i] = s++;
  for (int i = 0; i < s; ++i) {
    bfs(c[i]);
    for (int j = 0; j <= n; ++j)
      if (b[j] >= 0) g[i][b[j]] = dis[j] >= 0 ? dis[j] : n * 20;
  }
  memset(f, 1, sizeof f);
  f[0] = 0;
  for (int i = 0; i + 1 < 1 << s; ++i)
    if (f[i] <= n * 20) {
      int x;
      for (int j = 0; j < s; ++j)
        if ((i & 1 << j) == 0) {
          x = j;
          break;
        }
      for (int j = x + 1; j < s; ++j)
        if ((i & 1 << j) == 0 && f[i] + g[x][j] < f[i | 1 << x | 1 << j])
          f[i | 1 << x | 1 << j] = f[i] + g[x][j];
    }
  printf("%d\n", f[(1 << s) - 1] < n * 20 ? f[(1 << s) - 1] : -1);
  return 0;
}
