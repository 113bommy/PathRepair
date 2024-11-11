#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 11;
const long long mod = 1e9 + 7;
const bool debug = false;
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int gg[1 << 5], dp[13][1 << 5][50], sum[13][50], dp2[13][50][13];
int F[N], Finv[N], inv[N];
void init() {
  inv[1] = 1, F[0] = Finv[0] = 1;
  for (int i = 2; i < N; i++)
    inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
  for (int i = 1; i < N; i++) {
    F[i] = F[i - 1] * 1ll * i % mod;
    Finv[i] = Finv[i - 1] * 1ll * inv[i] % mod;
  }
}
int comb(int n, int m) {
  if (n < m) return 0;
  int ret = 1;
  for (int i = 0; i < m; ++i) ret = ret * 1ll * (n - i) % mod;
  return ret * 1ll * Finv[m] % mod;
}
void solve() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i < (1 << 5); ++i) gg[i] = gg[i >> 1] + (i & 1);
  dp[1][1 << m][1] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int tmp = (1 << m); tmp < (1 << (m + 1)); ++tmp) {
      for (int len = 1; len < 50; ++len) {
        if (!dp[i][tmp][len]) continue;
        if (debug)
          cout << "dp " << i << " " << tmp << " " << len << " = "
               << dp[i][tmp][len] << "\n";
        add(sum[i][len], dp[i][tmp][len]);
        if (i + 1 > k) continue;
        for (int j = 1, to; j <= m; ++j) {
          to = (1 << m) | (tmp >> j);
          add(dp[i + 1][to][len + j], dp[i][tmp][len] * 1ll * gg[to] % mod);
        }
      }
    }
  }
  dp2[0][0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int len = 1; len < 50; ++len) {
      for (int t = 1; t <= k; ++t) {
        for (int j = 1; j <= i; ++j) {
          for (int z = 1; z <= len; ++z) {
            if (t != 1) {
              if (z + m > len) continue;
              add(dp2[i][len][t],
                  dp2[i - j][len - z - m][t - 1] * 1ll * sum[j][z] % mod);
            } else
              add(dp2[i][len][t],
                  dp2[i - j][len - z][t - 1] * 1ll * sum[j][z] % mod);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int len = 1; len < 50; ++len) {
    for (int t = 1; t <= k; ++t) {
      if (!dp2[k][len][t]) continue;
      add(ans, dp2[k][len][t] * 1ll * comb(n - len + t, t) % mod);
    }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
