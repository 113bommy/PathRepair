#include <bits/stdc++.h>
using namespace std;
int w[1010], b[1010];
int f[1010], vis[1010];
int num[1010], d[2][1010];
int Find(int x) { return f[x] == x ? x : (f[x] = Find(f[x])); }
int main() {
  int n, m, W;
  scanf("%d%d%d", &n, &m, &W);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int nx = Find(x), ny = Find(y);
    if (nx != ny) {
      f[ny] = nx;
    }
  }
  memset(d, 0, sizeof d);
  memset(vis, 0, sizeof vis);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= W; j++) d[now][j] = d[1 - now][j];
    if (!vis[i]) {
      int x = Find(i), sw = 0, sb = 0, cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (vis[j]) continue;
        int y = Find(j);
        if (x == y) {
          sw += w[j];
          sb += b[j];
          vis[j] = 1;
          num[++cnt] = j;
        }
      }
      for (int j = 0; j <= W; j++) {
        for (int k = 1; k <= cnt; k++) {
          if (j >= w[num[k]]) {
            d[now][j] = max(d[now][j], d[1 - now][j - w[num[k]]] + b[num[k]]);
          }
        }
        if (j >= sw) {
          d[now][j] = max(d[now][j], d[1 - now][j - sw] + sb);
        }
      }
      now = 1 - now;
    }
  }
  int ans = 0;
  for (int j = 0; j <= W; j++) {
    ans = max(ans, d[1 - now][j]);
  }
  printf("%d\n", ans);
  return 0;
}
