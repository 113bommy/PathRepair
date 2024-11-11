#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const int mod = 1e9 + 7, N = 310;
inline int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return ans;
}
int inv[N], p[N];
int binom(int n, int m) {
  return (long long)p[n] * inv[n - m] % mod * inv[m] % mod;
}
int f[2][60][60];
int main() {
  p[0] = inv[0] = 1;
  for (int i = 1; i <= 50; i++)
    p[i] = (long long)p[i - 1] * i % mod, inv[i] = qpow(p[i], mod - 2);
  int n = read(), K = read(), tot5 = 0, tot1 = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    tot5 += (x == 50);
    tot1 += (x == 100);
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 0; j <= tot5; j++)
      for (int k = 0; k <= tot1; k++) f[i & 1][j][k] = 0;
    for (int j = 0; j <= tot5; j++) {
      for (int k = 0; k <= tot1; k++) {
        if (i & 1) {
          for (int c5 = 0; c5 <= tot5 - j; c5++) {
            for (int c1 = 0; c1 <= tot1 - k; c1++) {
              if (!c5 && !c1) continue;
              if (50 * c5 + 100 * c1 > K) continue;
              f[1][j + c5][k + c1] += (long long)binom(tot5 - j, c5) *
                                      binom(tot1 - k, c1) % mod * f[0][j][k] %
                                      mod;
              f[1][j + c5][k + c1] %= mod;
            }
          }
        } else {
          for (int c5 = 0; c5 <= j; c5++) {
            for (int c1 = 0; c1 <= k; c1++) {
              if (!c5 && !c1) continue;
              if (50 * c5 + 100 * c1 > K) continue;
              f[0][j - c5][k - c1] += (long long)binom(j, c5) * binom(k, c1) %
                                      mod * f[1][j][k] % mod;
              f[0][j - c5][k - c1] %= mod;
            }
          }
        }
      }
    }
    if (f[i & 1][tot5][tot1]) {
      printf("%d\n%d", i, f[i & 1][tot5][tot1]);
      return 0;
    }
  }
  printf("-1\n0");
  return 0;
}
