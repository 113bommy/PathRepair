#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
int n, m, x;
double a[3011][3011], f[3011][3011], c[3011], d[3011], ans;
int main() {
  R(n), R(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) R(x), a[i][j] = x * 0.001;
  for (int i = 1; i <= m; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= n; j++) f[i][j] = f[i][j - 1] * (1 - a[i][j]);
    d[i] = 1 - f[i][n];
  }
  for (int i = 1; i <= n; i++) {
    int k = 1;
    for (int j = 1; j <= m; j++)
      if (d[k] < d[j]) k = j;
    for (int j = 1; j <= n; j++)
      c[j] = c[j - 1] * (1 - a[k][j]) + f[k][j - 1] * a[k][j];
    for (int j = 0; j <= n; j++) f[k][j] = c[j];
    ans += d[k];
    d[k] -= f[k][n];
  }
  printf("%.10f\n", ans);
  return 0;
}
