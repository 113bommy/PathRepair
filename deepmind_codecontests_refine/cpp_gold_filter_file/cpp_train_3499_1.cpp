#include <bits/stdc++.h>
using namespace std;
int n, m, C[55], f[55][55], g[55][55], F[55][55], sum;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
inline void R(int& x, int y) {
  x += y;
  x >= 1000000007 ? x -= 1000000007 : 0;
}
inline int pow(int x, int k) {
  for (sum = 1; k; k >>= 1, x = 1LL * x * x % 1000000007)
    if (k & 1) sum = 1LL * sum * x % 1000000007;
  return sum;
}
int main() {
  n = read();
  m = read();
  f[0][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j)
      for (int k = 1; k <= j + 1; ++k)
        for (int l = 1; l <= i - j; ++l)
          R(g[i][min(k, l)], 1LL * f[j][k] * f[i - 1 - j][l] % 1000000007);
    for (int fl = 1; fl <= i; ++fl)
      if (g[i][fl]) {
        memset(F, 0, sizeof(F));
        for (int k = 0, l = 1; k * i <= n; ++k) {
          C[k] = l;
          l = 1LL * l * (k + g[i][fl]) % 1000000007 *
              pow(k + 1, 1000000007 - 2) % 1000000007;
        }
        for (int j = 0; j <= n; ++j)
          for (int l = 1; l <= n + 1; ++l)
            if (f[j][l])
              for (int k = 0; k * i + j <= n && l + k * fl <= 50; ++k)
                R(F[k * i + j][l + k * fl], 1LL * f[j][l] * C[k] % 1000000007);
        memcpy(f, F, sizeof(f));
      }
  }
  printf("%d\n", f[n][m]);
  return 0;
}
