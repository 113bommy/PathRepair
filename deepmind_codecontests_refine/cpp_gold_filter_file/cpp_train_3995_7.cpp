#include <bits/stdc++.h>
using namespace std;
int n, q, i, j, k, a[100002], cnt[100002];
double f[100002][202], c[100002 * 5][10], ans;
int read() {
  char c = getchar();
  int w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
int main() {
  n = read();
  for (i = 1; i <= n; i++) a[i] = cnt[i] = read();
  c[0][0] = 1.0;
  for (i = 1; i <= 500000; i++) {
    c[i][0] = 1.0;
    for (j = 1; j <= min(i, 5); j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  for (i = 1; i <= n; i++) f[i][a[i]] = 1.0, ans += f[i][0];
  q = read();
  while (q--) {
    int u = read(), v = read(), w = read();
    ans -= f[u][0];
    for (i = 0; i <= a[u]; i++) {
      double res = 0;
      for (j = i; j <= min(i + w, cnt[u]); j++) {
        res += f[u][j] * c[j][j - i] * c[cnt[u] - j][w - (j - i)];
      }
      f[u][i] = res / c[cnt[u]][w];
    }
    cnt[u] -= w;
    cnt[v] += w;
    ans += f[u][0];
    printf("%.9lf\n", ans);
  }
  return 0;
}
