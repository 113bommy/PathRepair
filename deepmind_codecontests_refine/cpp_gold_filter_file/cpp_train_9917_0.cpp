#include <bits/stdc++.h>
using namespace std;
int n, m;
int h[255], r[255], a[255][255];
int lline[255], rline[255];
int vis[255 * 255], ans[255][255];
inline int qr() {
  char a = 0;
  int w = 1, np = 0;
  while (a < '0' || a > '9') {
    if (a == '-') w = -1;
    a = getchar();
  }
  while (a <= '9' && a >= '0') {
    np = (np << 3) + (np << 1) + (a ^ 48);
    a = getchar();
  }
  return np * w;
}
int main() {
  n = qr(), m = qr();
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= m; j++) {
      h[i] = max(h[i], a[i][j] = qr());
      r[j] = max(r[j], a[i][j]);
    }
  for (register int i = 1; i <= n; i++) vis[h[i]] = 1;
  for (register int i = 1; i <= m; i++)
    !vis[r[i]] ? vis[r[i]] = 2 : vis[r[i]] = 3;
  for (register int k = n * m, x = 0, y = 0; k; k--) {
    if (vis[k] == 3)
      ans[++x][++y] = k, lline[x] = rline[x] = y;
    else if (vis[k] == 2)
      ans[x][++y] = k, rline[x] = y;
    else if (vis[k] == 1)
      ans[++x][y] = k, lline[x] = rline[x] = y;
    else {
      for (register int i = 1, flag = 0; i <= x && !flag; i++) {
        for (register int j = lline[i] - 1; j; j--)
          if (!ans[i][j] && ans[i - 1][j]) {
            ans[i][j] = k, flag = 1, lline[i] = j;
            break;
          }
        for (register int j = rline[i] + 1; j <= y && !flag; j++)
          if (!ans[i][j] && ans[i + 1][j]) {
            ans[i][j] = k, flag = 1, rline[i] = j;
            break;
          }
      }
    }
  }
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= m; j++)
      printf("%d%c", ans[i][j], " \n"[j == m]);
  return 0;
}
