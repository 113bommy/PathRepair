#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2005;
int64_t dp[N][N];
int64_t powD[N];
int a[N][N];
int n;
struct fen {
  int a[N] = {};
  void add(int i, int v) {
    ++i;
    while (i < N) {
      a[i] += v;
      i += i & (-i);
    }
  }
  int get(int r) {
    int ans = 0;
    while (r > 0) {
      ans += a[r];
      r -= r & (-r);
    }
    return ans;
  }
  bool exist(int i) { return get(i + 1) - get(i); }
};
void calc_dp() {
  dp[0][0] = 1;
  for (int i = (1); i < (N); ++i) dp[i][i] = dp[i - 1][i - 1] * i % mod;
  for (int j = (1); j < (N); ++j)
    dp[j - 1][j] = dp[j - 1][j - 1] * (j - 1) % mod;
  for (int i = (2); i < (N); ++i)
    for (int j = (i); j < (N); ++j)
      dp[j - i][j] =
          (dp[j - i][j - 1] * (j - i) + dp[j - i + 1][j - 1] * (i - 1)) % mod;
  powD[0] = 1;
  for (int i = (1); i < (N); ++i) powD[i] = powD[i - 1] * dp[0][n] % mod;
}
int64_t cnt_first() {
  int64_t ans = 0;
  fen ghabli;
  for (int i = (0); i < (n); ++i) ghabli.add(i, 1);
  for (int i = (0); i < (n); ++i) {
    ans += dp[n - 1 - i][n - 1 - i] * ghabli.get(a[0][i]);
    ans %= mod;
    ghabli.add(a[0][i], -1);
  }
  return ans * powD[n - 1] % mod;
}
int64_t cnt(int i) {
  fen azad, zendan;
  for (int i = (0); i < (n); ++i) zendan.add(i, 1);
  int64_t ans = 0;
  for (int j = (0); j < (n); ++j) {
    ans += azad.get(a[i][j]) *
           dp[azad.get(N) - 1 + zendan.exist(a[i - 1][j])][n - 1 - j] % mod;
    ans += (zendan.get(a[i][j]) -
            (a[i - 1][j] < a[i][j] && zendan.exist(a[i - 1][j]))) *
           dp[azad.get(N) + zendan.exist(a[i - 1][j])][n - 1 - j] % mod;
    ans %= mod;
    if (azad.exist(a[i][j])) azad.add(a[i][j], -1);
    if (zendan.exist(a[i][j])) zendan.add(a[i][j], -1);
    if (zendan.exist(a[i - 1][j]))
      zendan.add(a[i - 1][j], -1), azad.add(a[i - 1][j], 1);
  }
  return ans * powD[n - 1 - i] % mod;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ;
  cin >> n;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) cin >> a[i][j], a[i][j]--;
  calc_dp();
  int64_t ans = 0;
  ans += cnt_first();
  for (int i = (1); i < (n); ++i) ans = (ans + cnt(i)) % mod;
  cout << ans << '\n';
}
