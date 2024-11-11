#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long double EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int all_sum = 0;
  vector<int> pl(m);
  for (int i = 0; i < m; ++i) {
    cin >> pl[i];
    all_sum += pl[i];
  }
  if (m == 1) {
    cout << pl[0] << endl;
    return 0;
  }
  vector<vector<long double>> dp(2, vector<long double>(m + m * n + 7, 0.));
  vector<long double> pref(m + m * n + 7, 0.);
  dp[0][0] = 1.;
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    int lim_s = i * m + m + 1;
    for (int j = 0; j <= lim_s; ++j) {
      pref[j] = dp[cur ^ 1][j] + ((j == 0) ? 0. : pref[j - 1]);
    }
    for (int s = 0; s <= lim_s; ++s) {
      if (s)
        dp[cur][s] = pref[s - 1];
      else
        dp[cur][s] = 0.;
      if (s > m) dp[cur][s] -= pref[s - m - 1];
      if (s >= pl[i]) dp[cur][s] -= dp[cur ^ 1][s - pl[i]];
      dp[cur][s] /= (m - 1);
    }
    cur ^= 1;
  }
  long double ans = 0.;
  cur ^= 1;
  for (int i = 0; i < all_sum; ++i) {
    ans += dp[cur][i];
  }
  cout << fixed << setprecision(10) << 1. + ans * (m - 1);
  return 0;
};
