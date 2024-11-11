#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, t, i, j, k, l, a[52], b[52], n1[4], m[4], fac[52];
int f1[52][2502], f2[52][52][2502], g[52][52][52][4];
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
  t = read();
  for (i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = read();
    n1[b[i]]++;
    m[b[i]] += a[i];
  }
  for (i = fac[0] = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  f1[0][0] = f2[0][0][0] = 1;
  for (i = 1; i <= n; i++) {
    if (b[i] != 1) continue;
    for (j = n1[1]; j >= 1; j--) {
      for (k = m[1]; k >= a[i]; k--)
        f1[j][k] = (f1[j][k] + f1[j - 1][k - a[i]]) % mod;
    }
  }
  for (i = 1; i <= n; i++) {
    if (b[i] == 2) {
      for (j = n1[2]; j >= 1; j--) {
        for (k = n1[3]; k >= 0; k--) {
          for (l = m[2] + m[3]; l >= a[i]; l--)
            f2[j][k][l] = (f2[j][k][l] + f2[j - 1][k][l - a[i]]) % mod;
        }
      }
    } else if (b[i] == 3) {
      for (j = n1[2]; j >= 0; j--) {
        for (k = n1[3]; k >= 1; k--) {
          for (l = m[2] + m[3]; l >= a[i]; l--)
            f2[j][k][l] = (f2[j][k][l] + f2[j][k - 1][l - a[i]]) % mod;
        }
      }
    }
  }
  g[1][0][0][1] = g[0][1][0][2] = g[0][0][1][3] = 1;
  for (i = 0; i <= n1[1]; i++) {
    for (j = 0; j <= n1[2]; j++) {
      for (k = 0; k <= n1[3]; k++) {
        if (i != 0) {
          if (j < n1[2])
            g[i][j + 1][k][2] = (g[i][j + 1][k][2] + g[i][j][k][1]) % mod;
          if (k < n1[3])
            g[i][j][k + 1][3] = (g[i][j][k + 1][3] + g[i][j][k][1]) % mod;
        }
        if (j != 0) {
          if (i < n1[1])
            g[i + 1][j][k][1] = (g[i + 1][j][k][1] + g[i][j][k][2]) % mod;
          if (k < n1[3])
            g[i][j][k + 1][3] = (g[i][j][k + 1][3] + g[i][j][k][2]) % mod;
        }
        if (k != 0) {
          if (i < n1[1])
            g[i + 1][j][k][1] = (g[i + 1][j][k][1] + g[i][j][k][3]) % mod;
          if (j < n1[2])
            g[i][j + 1][k][2] = (g[i][j + 1][k][2] + g[i][j][k][3]) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (i = 0; i <= n1[1]; i++) {
    for (j = 0; j <= n1[2]; j++) {
      for (k = 0; k <= n1[3]; k++) {
        for (l = 0; l <= t; l++) {
          int res = (g[i][j][k][1] + g[i][j][k][2] + g[i][j][k][3]) % mod;
          res = 1LL * fac[i] * fac[j] % mod * fac[k] % mod * res % mod;
          ans =
              (ans + 1LL * f1[i][l] * f2[j][k][t - l] % mod * res % mod) % mod;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
