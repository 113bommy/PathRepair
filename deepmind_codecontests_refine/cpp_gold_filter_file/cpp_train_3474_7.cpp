#include <bits/stdc++.h>
using namespace std;
int b[1010][1010], n, m, K;
long long a[1010][1010], xS[1010][1010], xT[1010][1010], yS[1010][1010],
    yT[1010][1010], zS[1010][1010];
long long sum[1010][1010], w[1010][1010], pl[1010][1010];
void calc(long long res[1010][1010], bool ty) {
  res[K][K] = pl[K][K] = 0;
  for (int i = 1; i <= K; ++i)
    for (int j = 1; j <= K; ++j)
      res[K][K] += a[i][j] * max(0, K - abs(i - K) - abs(j - K)),
          pl[K][K] += a[i][j] * (K - abs(i - K) - abs(j - K) > 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      xS[i][j] = xS[i][j - 1] + a[i][j];
      xT[i][j] = xT[i][j - 1] + a[i][j] * j;
      yS[i][j] = yS[i - 1][j] + a[i][j];
      yT[i][j] = yT[i - 1][j] + a[i][j] * i;
      zS[i][j] = zS[i - 1][j + 1] + a[i][j];
      if (K <= i && i <= n - K + 1 && K <= j && j <= m - K + 1) {
        if (j == K) {
          if (i != K) {
            pl[i][K] =
                pl[i - 1][K] - (zS[i - 1][1] - zS[i - 1 - K][1 + K]) + xS[i][K];
            res[i][K] = res[i - 1][K] - pl[i - 1][K] + xT[i][K];
          }
        } else {
          pl[i][j] = pl[i][j - 1] - (zS[i][j - K] - zS[i - K][j]) +
                     (yS[i][j] - yS[i - K][j]);
          res[i][j] =
              res[i][j - 1] - pl[i][j - 1] +
              (yT[i][j] - yT[i - K][j] - (i - K) * (yS[i][j] - yS[i - K][j]));
        }
      }
    }
  }
  if (ty)
    for (int i = K; i <= n - K + 1; ++i)
      for (int j = K; j <= m - K + 1; ++j)
        res[i][j] -= yT[i][j] - yT[i - K][j] -
                     (i - K) * (yS[i][j] - yS[i - K][j]) + xT[i][j] -
                     xT[i][j - K] - (j - K) * (xS[i][j] - xS[i][j - K]);
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &b[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = b[i][j];
  calc(sum, 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) w[i][j] += sum[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[n - i + 1][j] = b[i][j];
  calc(sum, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) w[i][j] += sum[n - i + 1][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][m - j + 1] = b[i][j];
  calc(sum, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) w[i][j] += sum[i][m - j + 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[n - i + 1][m - j + 1] = b[i][j];
  calc(sum, 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) w[i][j] += sum[n - i + 1][m - j + 1];
  int _x = 0, _y = 0;
  for (int i = K; i <= n - K + 1; ++i) {
    for (int j = K; j <= m - K + 1; ++j) {
      w[i][j] += K * b[i][j];
      if (w[i][j] >= w[_x][_y]) _x = i, _y = j;
    }
  }
  printf("%d %d\n", _x, _y);
  return 0;
}
