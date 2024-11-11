#include <bits/stdc++.h>
using namespace std;
const int N = 7, M = 65;
double p[M][M], f[N][M], w[N][M];
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
double max(double a, double b) { return a > b ? a : b; }
void calc(int x, int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1, i, j;
  calc(x - 1, l, mid), calc(x - 1, mid + 1, r);
  for (i = l; i <= mid; ++i)
    for (j = mid + 1; j <= r; ++j)
      f[x][i] += f[x - 1][i] * f[x - 1][j] * p[i][j],
          f[x][j] += f[x - 1][i] * f[x - 1][j] * p[j][i];
  for (i = l; i <= mid; ++i)
    for (j = mid + 1; j <= r; ++j)
      w[x][i] =
          max(w[x][i], w[x - 1][i] + w[x - 1][j] + f[x][i] * (r - l + 1) / 2),
      w[x][j] =
          max(w[x][j], w[x - 1][i] + w[x - 1][j] + f[x][j] * (r - l + 1) / 2);
}
int main() {
  int n = read(), m = 1 << n, i, j;
  double ans = 0;
  for (i = 1; i <= m; ++i)
    for (j = 1; j <= m; ++j) p[i][j] = 0.01 * read();
  for (i = 1; i <= m; ++i) f[0][i] = 1;
  calc(n, 1, m);
  for (i = 1; i <= m; ++i) ans = max(ans, w[n][i]);
  return !printf("%lf", ans);
}
