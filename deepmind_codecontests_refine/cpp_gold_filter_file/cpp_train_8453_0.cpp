#include <bits/stdc++.h>
using namespace std;
const int maxx = 600010;
const double pi = acos(-1.0);
const double eps = 1e-15;
int t, n, m, u, v;
int ans = 0, total = 0, sum = 0, cnt = 0, l = 0, r = 0;
int a[maxx], x[maxx], y[maxx], upx[maxx], upy[maxx], dx[maxx], dy[maxx];
char c[311][311];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    total = sum = cnt = 0, ans = 4;
    for (int i = 1; i <= n + 1; i++) x[i] = upx[i] = dx[i] = 0;
    for (int i = 1; i <= m + 1; i++) y[i] = upy[i] = dy[i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf(" %c", &c[i][j]);
        if (c[i][j] == 'P') total++, x[i]++, y[j]++;
      }
    if (total == n * m) {
      printf("MORTAL\n");
      continue;
    }
    if (!total) {
      printf("0\n");
      continue;
    }
    for (int i = 1; i <= n; i++) upx[i] = upx[i - 1] + x[i - 1];
    for (int i = n; i >= 1; i--) dx[i] = dx[i + 1] + x[i + 1];
    for (int i = 1; i <= m; i++) upy[i] = upy[i - 1] + y[i - 1];
    for (int i = m; i >= 1; i--) dy[i] = dy[i + 1] + y[i + 1];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (c[i][j] == 'A') {
          l = j, sum = 0;
          for (int k = l; k <= m; k++) {
            if (c[i][k] == 'A') sum++;
            if (c[i][k] == 'P') {
              if (l == 1) {
                if (x[i] == total)
                  ans = min(ans, 1);
                else {
                  if (dx[i] && upx[i])
                    ans = min(ans, 3);
                  else
                    ans = min(ans, 2);
                }
              } else {
                if (x[i] == total)
                  ans = min(ans, 2);
                else {
                  if (dx[i] && upx[i])
                    ans = min(ans, 4);
                  else
                    ans = min(ans, 3);
                }
              }
              j = k;
              break;
            }
            if (k == m) {
              if (l == 1) {
                if (upx[i] && dx[i])
                  ans = min(ans, 2);
                else
                  ans = min(ans, 1);
              } else {
                if (x[i] == total)
                  ans = min(ans, 1);
                else {
                  if (upx[i] && dx[i])
                    ans = min(ans, 3);
                  else
                    ans = min(ans, 2);
                }
              }
              j = m + 1;
            }
          }
        }
      }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (c[i][j] == 'A') {
          l = i, sum = 0;
          for (int k = i; k <= n; k++) {
            if (c[k][j] == 'A') sum++;
            if (c[k][j] == 'P') {
              if (l == 1) {
                if (y[j] == total)
                  ans = min(ans, 1);
                else {
                  if (dy[j] && upy[j])
                    ans = min(ans, 3);
                  else
                    ans = min(ans, 2);
                }
              } else {
                if (y[j] == total)
                  ans = min(ans, 2);
                else {
                  if (dy[j] && upy[j])
                    ans = min(ans, 4);
                  else
                    ans = min(ans, 3);
                }
              }
              i = k;
              break;
            }
            if (k == n) {
              if (l == 1) {
                if (dy[j] && upy[j])
                  ans = min(ans, 2);
                else
                  ans = min(ans, 1);
              } else {
                if (dy[j] && upy[j])
                  ans = min(ans, 3);
                else
                  ans = min(ans, 2);
              }
              i = n + 1;
            }
          }
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
