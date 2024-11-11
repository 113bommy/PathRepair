#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[105], s[105];
int f[105][105 * 105], c[105][105];
double ans;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  n = read(), x = read(), f[0][0] = c[0][0] = 1;
  for (int i = 1; i <= n; i++)
    a[i] = read(), s[i] = s[i - 1] + a[i], c[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = i - 1; j >= 0; j--)
      for (int k = s[i - 1]; k >= 0; k--) f[j + 1][k + a[i]] += f[j][k];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= s[n]; j++) {
      double p = 1.0 * j / i - ((1.0 * n / i - 1) * x / 2.0 + x);
      if (p >= 0) ans += p / c[n][i] * f[i][j];
    }
  printf("%.9lf\n", s[n] - ans);
  return 0;
}
