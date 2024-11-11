#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
const int inf = 1e9;
int n, b, s[5050], f[2][maxn + 5];
short pre[2][maxn + 5];
int out[5050], a[5050];
int main() {
  scanf("%d%d", &n, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
  for (int j = 0; j <= maxn; j++) f[0][j] = f[1][j] = inf;
  f[0][0] = 0;
  int op = 1;
  for (int i = 1; i <= n; i++) {
    op ^= 1;
    for (int j = 0; j <= maxn; j++) f[op ^ 1][j] = inf;
    for (int j = 0; j <= maxn; j++)
      if (f[op][j] != inf) {
        int tot = s[i - 1];
        int rest = b + j - (tot - f[op][j]);
        for (int k = 0; k <= min(rest, a[i] / 2); k++) {
          int now = f[op][j] + a[i] - k;
          int nj = j + (a[i] - k) / 10;
          if (now < f[op ^ 1][nj]) {
            f[op ^ 1][nj] = now;
            pre[i][nj] = a[i] - k;
          }
        }
      }
  }
  op ^= 1;
  int ans = inf, now = 0;
  for (int i = 0; i <= maxn; i++)
    if (ans > f[op][i]) ans = f[op][i], now = i;
  printf("%d\n", ans);
  for (int i = n; i >= 1; i--) {
    out[i] = pre[i][now];
    now = now - out[i] / 10;
    op ^= 1;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i] - out[i]);
  return 0;
}
