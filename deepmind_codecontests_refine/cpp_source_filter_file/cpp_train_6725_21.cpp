#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int deg[N];
long long g[N][N][N], f[N][N], c[N][N], a[N] = {0, 0, 1, 1};
inline long long mod(long long a) {
  return a > 1000000007 ? a - 1000000007 : a;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x;
}
int main() {
  for (int i = 4; i <= 50; ++i) a[i] = a[i - 1] * (i - 1) % 1000000007;
  for (int i = 0; i <= 50; ++i) c[i][i] = c[i][0] = 1;
  for (int i = 1; i <= 50; ++i)
    for (int j = 1; j < i; ++j) c[i][j] = mod(c[i - 1][j - 1] + c[i - 1][j]);
  g[0][0][0] = 1;
  for (register int j = 0; j <= 50; ++j)
    for (register int k = 0; k <= 50 - j; ++k)
      if (j == 0 && k > 0)
        for (register int l = 2; l < k; ++l)
          g[0][j][k] = mod(g[0][j][k] + g[0][j][k - l - 1] * c[k - 1][l] %
                                            1000000007 * a[l + 1] % 1000000007);
      else {
        if (j >= 2)
          g[0][j][k] = mod(g[0][j][k] + g[0][j - 2][k] * (j - 1) % 1000000007);
        if (k >= 1)
          g[0][j][k] = mod(g[0][j][k] + g[0][j][k - 1] * k % 1000000007);
      }
  for (register int i = 1; i <= 50; ++i)
    for (register int j = 0; j <= 50 - i; ++j)
      for (register int k = 0; k <= 50 - i - j; ++k) {
        if (j >= 1)
          g[i][j][k] = mod(g[i][j][k] + g[i - 1][j - 1][k] * j % 1000000007);
        if (k >= 1)
          g[i][j][k] =
              mod(g[i][j][k] + g[i - 1][j + 1][k - 1] * k % 1000000007);
      }
  register int n = read(), p1 = 0, p2 = 0;
  for (register int i = 1; i <= n; ++i) deg[i] = read();
  f[deg[1] + 1][deg[1]] = 1;
  for (register int i = deg[1] + 2; i <= n; ++i)
    for (register int j = 1; j <= i - deg[1] - 1; ++j) {
      p1 = p2 = 0;
      for (register int k = 1; k <= i - j; k++) {
        if (deg[i - j - k + 1] == 2)
          ++p1;
        else
          ++p2;
        f[i][j] = mod(f[i][j] + f[i - j][k] * g[j][p1][p2] % 1000000007);
      }
    }
  p1 = p2 = 0;
  long long ans = 0;
  for (register int j = 1; j < n; ++j) {
    if (deg[n - j + 1] == 2)
      ++p1;
    else
      ++p2;
    ans = (ans + f[n][j] * g[0][p1][p2] % 1000000007);
  }
  return printf("%I64d", ans), 0;
}
