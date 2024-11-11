#include <bits/stdc++.h>
using namespace std;
double f[2][105][105];
int n, K, a[105];
int C2(int x) { return x * (x + 1) / 2; }
int main() {
  scanf("%d%d", &n, &K);
  K = min(K, 1000);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(i + 1); j <= (int)(n); j++) f[0][i][j] = (a[i] > a[j]);
  for (int T = (int)(1); T <= (int)(K); T++) {
    int now = T & 1, pre = now ^ 1;
    memset(f[now], 0, sizeof(f[now]));
    for (int j = (int)(1); j <= (int)(n); j++)
      for (int k = (int)(j + 1); k <= (int)(n); k++) {
        f[now][j][k] = (C2(j - 1) + C2(k - j - 1) + C2(n - k)) * f[pre][j][k];
        for (int s = (int)(k + 1); s <= (int)(j + n); s++)
          f[now][j][k] +=
              (1 - f[pre][s - k][s - j]) * (min(j, s - k) - max(1, s - n) + 1);
        for (int s = (int)(j + 1); s <= (int)(j + k - 1); s++)
          f[now][j][k] +=
              f[pre][s - j][k] * (min(j, s - j) - max(1, s - k + 1) + 1);
        for (int s = (int)(j + k + 1); s <= (int)(n + k); s++)
          f[now][j][k] +=
              f[pre][j][s - k] * (min(k, s - k) - max(j + 1, s - n) + 1);
        f[now][j][k] /= n * (n + 1) / 2;
      }
  }
  double ans = 0;
  for (int j = (int)(1); j <= (int)(n); j++)
    for (int k = (int)(j + 1); k <= (int)(n); k++) ans += f[K & 1][j][k];
  printf("%.15lf\n", ans);
}
