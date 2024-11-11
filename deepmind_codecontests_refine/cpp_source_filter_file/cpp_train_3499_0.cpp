#include <bits/stdc++.h>
const int N = 55, mod = 1000000007;
int n, m, inv[N];
int dp[N][N], g[N][N];
void up(int &x, int y) { x += y - mod, x += x >> 31 & mod; }
void up(int &x, int y, int z) { x = (x + (long long)y * z) % mod; }
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> m, dp[0][1] = inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k < i; ++k) {
        for (int l = j; l <= k + 1; ++l)
          up(g[i][j], dp[k][l], dp[i - k - 1][j]);
        for (int l = j + 1; l <= i - k; ++l)
          up(g[i][j], dp[k][j], dp[i - k - 1][l]);
      }
      for (int p = n - i; ~p; --p)
        for (int q = n - j; ~q; --q)
          if (dp[p][q]) {
            int w = g[i][j], s = w;
            for (int x = 1; x * i <= n - p && x * j <= n + 1 - q; ++x) {
              up(dp[x * i + p][x * j + q], dp[p][q], s);
              s = (long long)s * (w + x) % mod * inv[x + 1] % mod;
            }
          }
    }
  }
  std::cout << dp[n][m] << '\n';
  return 0;
}
