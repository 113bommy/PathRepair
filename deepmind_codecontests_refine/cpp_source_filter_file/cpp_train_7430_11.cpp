#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int maximize(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline int minimize(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 151, INF = 0x3f3f3f3f, mod = 1000000007;
template <class T>
inline void add(T& a, T b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
int n, m, dp[N][N][4], prefix[N][N][4], f[N][N][4][4];
long long ans;
int main() {
  cin >> n >> m;
  if (n < m) swap(n, m);
  for (int j = 1; j <= m; ++j) {
    for (int k = j; k <= m; ++k) {
      add(ans, 1LL * n);
      dp[j][k][0] = 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int k = 1; k <= m; ++k) {
      for (int j = k; j >= 1; --j) {
        for (int p = 0; p < 4; ++p) {
          prefix[k][j][p] = prefix[k][j + 1][p];
          add(prefix[k][j][p], dp[j][k][p]);
        }
      }
    }
    for (int j = 1; j <= m; ++j) {
      for (int k = j - 1; k <= m; ++k) {
        for (int p = 0; p < 4; ++p) {
          f[j][k][p][0] = f[j][k - 1][p][0];
          add(f[j][k][p][0], prefix[k][j][p]);
          f[j][k][p][1] = f[j][k - 1][p][1];
          add(f[j][k][p][1], prefix[k][1][p] - prefix[k][j + 1][p]);
        }
      }
      for (int k = m; k >= j - 1; --k) {
        for (int p = 0; p < 4; ++p) {
          f[j][k][p][2] = f[j][k + 1][p][2];
          add(f[j][k][p][2], prefix[k][j][p]);
          f[j][k][p][3] = f[j][k + 1][p][3];
          add(f[j][k][p][3], prefix[k][1][p] - prefix[k][j + 1][p]);
        }
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= m; ++j) {
      for (int k = j; k <= m; ++k) {
        add(dp[j][k][0], f[j][k][0][0]);
        add(dp[j][k][1], f[j][k][1][1] - f[j - 1][j - 1][1][1]);
        add(dp[j][k][1], f[j - 1][k][0][1] - f[j - 1][j - 1][0][1]);
        add(dp[j][k][2], f[j][k][2][2] - f[k + 1][k + 1][2][2]);
        add(dp[j][k][2], f[j][k + 1][0][2] - f[k + 1][k + 1][0][2]);
        add(dp[j][k][3], f[j - 1][k + 1][0][3]);
        add(dp[j][k][3], f[j][k + 1][1][3]);
        add(dp[j][k][3], f[j - 1][k][2][3]);
        add(dp[j][k][3], f[j][k][3][3]);
        for (int p = 0; p < 4; ++p)
          add(ans, dp[j][k][p] * (long long)(n - i + 1) % mod);
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
