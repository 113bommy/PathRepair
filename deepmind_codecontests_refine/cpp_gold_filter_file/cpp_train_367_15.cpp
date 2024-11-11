#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
inline void file() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
long long ljc, n, D, f[1010][11][1010], _inv[1010], inv[1010], fac[1010];
inline long long getC(long long n, long long m) {
  if (n < m) return 0;
  long long _ = 1;
  for (long long i = 0; i < m; i++) _ = _ * (n - i) % ljc;
  _ = _ * _inv[m] % ljc;
  return _;
}
inline void add(long long &a, const long long &b) {
  a += b;
  a %= ljc;
}
signed main() {
  n = read(), D = read(), ljc = read();
  if (n <= 2) {
    puts("1");
    return 0;
  }
  fac[0] = inv[0] = inv[1] = _inv[0] = 1;
  for (long long i = 1; i <= 100; i++) fac[i] = fac[i - 1] * i % ljc;
  for (long long i = 2; i <= 100; i++)
    inv[i] = (ljc - inv[ljc % i] * (ljc / i) % ljc) % ljc;
  for (long long i = 1; i <= 100; i++) _inv[i] = _inv[i - 1] * inv[i] % ljc;
  for (int i = 0; i <= n; i++) f[1][0][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= D; j++) {
      for (int k = 1; k <= n; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int l = 1; l <= j; l++) {
          if (i < l * k) break;
          if (k > 1)
            add(f[i][j][k], f[i - l * k][j - l][k - 1] *
                                getC(f[k][D - 1][k - 1] + l - 1, l) % ljc);
          else
            add(f[i][j][k], f[i - l * k][j - l][k - 1] *
                                getC(f[k][0][k - 1] + l - 1, l) % ljc);
        }
      }
    }
  }
  if (n & 1) {
    cout << f[n][D][n / 2];
  } else {
    cout << (f[n][D][n / 2] - getC(f[n / 2][D - 1][n / 2 - 1], 2) + ljc) % ljc;
  }
  return 0;
}
