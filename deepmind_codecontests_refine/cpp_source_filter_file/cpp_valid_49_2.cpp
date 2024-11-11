#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 14, mod = 1e9 + 7;
int n, n1, n2, l1, l2, lim, a[14], e[14][14], f[4][128][128], dp[N], ans;
void qmo(int &x) { x += x >> 31 & mod; }
int ksm(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) res = (long long)res * a % mod;
  return res;
}
int calc(int S, int T) {
  return (long long)f[0][S & l1 - 1][T & l1 - 1] * f[1][S & l1 - 1][T >> n1] %
         mod * f[2][S >> n1][T & l1 - 1] % mod * f[3][S >> n1][T >> n1] % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n1 = n >> 1;
  n2 = n + 1 >> 1;
  l1 = 1 << n1;
  l2 = 1 << n2;
  lim = 1 << n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < i; ++j) {
      e[i][j] = (long long)a[i] * ksm(a[i] + a[j], mod - 2) % mod;
      qmo(e[j][i] = mod + 1 - e[i][j]);
    }
  }
  for (int S = 0; S < l1; ++S)
    for (int T = 0; T < l1; ++T)
      if (!(S & T)) {
        f[0][S][T] = 1;
        for (int i = 0; i < n1; ++i)
          if (S >> i & 1)
            for (int j = 0; j < n1; ++j)
              if (T >> j & 1)
                f[0][S][T] = (long long)f[0][S][T] * e[i][j] % mod;
      }
  for (int S = 0; S < l2; ++S)
    for (int T = 0; T < l2; ++T)
      if (!(S & T)) {
        f[3][S][T] = 1;
        for (int i = 0; i < n2; ++i)
          if (S >> i & 1)
            for (int j = 0; j < n2; ++j)
              if (T >> j & 1)
                f[3][S][T] = (long long)f[3][S][T] * e[i + n1][j + n1] % mod;
      }
  for (int S = 0; S < l1; ++S)
    for (int T = 0; T < l2; ++T) {
      f[1][S][T] = 1;
      for (int i = 0; i < n1; ++i)
        if (S >> i & 1)
          for (int j = 0; j < n2; ++j)
            if (T >> j & 1)
              f[1][S][T] = (long long)f[1][S][T] * e[i][j + n1] % mod;
    }
  for (int S = 0; S < l2; ++S)
    for (int T = 0; T < l1; ++T) {
      f[2][S][T] = 1;
      for (int i = 0; i < n2; ++i)
        if (S >> i & 1)
          for (int j = 0; j < n1; ++j)
            if (T >> j & 1)
              f[2][S][T] = (long long)f[2][S][T] * e[i + n1][j] % mod;
    }
  for (int i = 1; i <= n; ++i) {
    for (int S = 1; S < lim; ++S)
      if (__builtin_popcount(S) == i) {
        dp[S] = 1;
        for (int T = S & S - 1; T; T = T - 1 & S)
          qmo(dp[S] -= (long long)dp[T] * calc(T, S - T) % mod);
        ans = (ans + (long long)dp[S] * i * calc(S, lim - 1 - S)) % mod;
      }
  }
  printf("%d\n", ans);
}
