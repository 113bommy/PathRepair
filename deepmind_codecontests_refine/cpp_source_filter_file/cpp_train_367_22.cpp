#include <bits/stdc++.h>
template <typename T>
inline bool MIN(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool MAX(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
using namespace std;
int n, d, mod;
int inv[1010];
int f[1010][1010][12], g[1010][1010];
int get_C(int m, int n) {
  if (n > m) return 0;
  int res = 1;
  for (int i = m; i > m - n; --i) res = (long long)res * i % mod;
  return (long long)res * inv[n] % mod;
}
int main() {
  scanf("%d%d%d", &n, &d, &mod);
  if (n <= 2) {
    printf("1\n");
    return 0;
  }
  inv[0] = inv[1] = 1;
  for (int i = 2; i < 1010; ++i)
    inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
  for (int i = 2; i < 1010; ++i) inv[i] = (long long)inv[i] * inv[i - 1] % mod;
  f[1][0][0] = f[1][0][d - 1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      for (int k = 1; k <= d; ++k) {
        f[i][j][k] = f[i][j - 1][k];
        for (int c = 1; c <= k && i - c * j > 0; ++c) {
          (f[i][j][k] +=
           (long long)f[i - c * j][min(j - 1, i - c * j - 1)][k - c] * g[j][c] %
           mod) %= mod;
        }
      }
    }
    for (int c = 1; c <= d; ++c) {
      g[i][c] = get_C(f[i][i - 1][d - 1] + c - 1, c);
    }
  }
  int ans = f[n][(n + 1) / 2 - 1][d];
  if (!(n & 1))
    (ans += (long long)f[n / 2][n / 2 - 1][d - 1] *
            (f[n / 2][n / 2 - 1][d - 1] + 1) * inv[2] % mod) %= mod;
  printf("%d\n", ans);
  return 0;
}
