#include <bits/stdc++.h>
const int mod = 1e9 + 7, N = 505;
int n, f[N][N][2];
bool arr[N][N];
int read() {
  int x = 0, f = 1;
  char s;
  while ((s = getchar()) > '9' || s < '0')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9')
    x = (x << 1) + (x << 3) + (s ^ 48), s = getchar();
  return x * f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) arr[i][j] = read();
  for (int i = 1; i <= n; ++i) f[i][i][0] = 1;
  for (int len = 2; len <= n; ++len)
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      if (arr[i][j])
        for (int k = i; k < j; ++k)
          f[i][j][0] =
              (f[i][j][0] + 1ll * (f[i][k][0] + f[i][k][1]) *
                                (f[k + 1][j][0] + f[k + 1][j][1]) % mod) %
              mod;
      for (int k = i + 1; k < j; ++k)
        if (arr[i][k])
          f[i][j][1] = (f[i][j][1] +
                        1ll * f[i][k][0] * (f[k][j][0] + f[k][j][1]) % mod) %
                       mod;
    }
  printf("%d\n", (f[1][n][0] + f[1][n][1]) % mod);
  return 0;
}
