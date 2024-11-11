#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
int n;
double ans, p[111], f[2][111][10101];
int main() {
  n = read<int>();
  for (int i = 0; i <= n; i++) scanf("%lf", &p[i]);
  ans = p[n / 2];
  if (p[n] == p[1]) {
    printf("%.7lf", ans);
    return 0;
  }
  for (int o = 0; o < 2; o++)
    for (int i = 0; i <= 100; i++)
      for (int j = 0; j <= 10000; j++) f[o][i][j] = -1e18;
  f[0][0][0] = f[1][0][0] = 0;
  for (int i = 0; i <= n / 2; i++) {
    int Max = 100;
    if (n - 2 * i) Max = min(100, 10000 / (n - 2 * i));
    int v = n - 2 * i;
    double w = p[i];
    for (int j = 1; j <= Max; j++) {
      for (int k = v; k <= 10000; k++)
        f[0][j][k] = max(f[0][j][k], f[0][j - 1][k - v] + w);
    }
  }
  for (int i = n / 2 + 1; i <= n; i++) {
    int Max = min(100, 10000 / (2 * i - n));
    int v = 2 * i - n;
    double w = p[i];
    for (int j = 1; j <= Max; j++) {
      for (int k = v; k <= 10000; k++)
        f[1][j][k] = max(f[1][j][k], f[1][j - 1][k - v] + w);
    }
  }
  for (int i = 1; i <= 100; i++) {
    double Max = -1e18;
    for (int k = 10000; k >= 0; k--) {
      Max = max(Max, f[0][i][k]);
      if (Max == -1e18) continue;
      for (int j = 0; j <= 100; j++)
        ans = max(ans, (Max + f[1][j][k]) / (double)(i + j));
    }
  }
  printf("%.9lf", ans);
  return 0;
}
