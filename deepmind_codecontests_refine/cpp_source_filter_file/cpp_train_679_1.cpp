#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
void solve() {
  int a, b, k, t;
  cin >> a >> b >> k >> t;
  vector<vector<long long>> dp(t + 1, vector<long long>(2 * k * t + 2));
  dp[0][k * t] = 1;
  for (int i = (int)(0); i < (int)(t); i++) {
    for (int j = (int)(0); j < (int)(2 * k * t + 1); j++) {
      (dp[i + 1][max(0, j - k)] += dp[i][j]) %= mod;
      (dp[i + 1][min(2 * k * t, j + k) + 1] += mod - dp[i][j]) %= mod;
    }
    for (int j = (int)(0); j < (int)(2 * k * t + 1); j++) {
      if (j) (dp[i + 1][j] += mod + dp[i + 1][j - 1]) %= mod;
    }
  }
  vector<long long> sum(2 * k * t + 2);
  for (int i = (int)((2 * k * t + 1) - 1); i >= (int)(0); i--) {
    sum[i] = sum[i + 1] + dp[t][i];
  }
  long long ans = 0;
  for (int i = (int)(0); i < (int)(2 * k * t + 1); i++) {
    int need = b + i - a + 1;
    if (need >= 2 * k * t + 2) continue;
    (ans += dp[t][i] * sum[max(0, need)] % mod) %= mod;
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while (T--) solve();
  return 0;
}
