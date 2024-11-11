#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, t;
  cin >> n >> s >> t;
  vector<vector<int>> a(5, vector<int>(n + 1));
  for (int i = 0; i < 5; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    a[3][i] += a[0][i];
    a[2][i] -= a[0][i];
    a[4][i] -= a[0][i];
    a[1][i] += a[0][i];
  }
  const long long inf = 1e18;
  vector<long long> dp(n + 1, inf);
  auto Min = [&](long long& a, long long b) {
    if (a > b) a = b;
  };
  bool L = 1, R = 1;
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    vector<long long> ndp(n + 1, inf);
    swap(dp, ndp);
    if (i == s) {
      for (int j = 0; j < i; j++) Min(dp[j], ndp[j] + a[4][i]);
      for (int j = 1; j < i; j++) Min(dp[j - 1], ndp[j] + a[3][i]);
      L = false;
    } else if (i == t) {
      for (int j = 0; j < i; j++) Min(dp[j], ndp[j] + a[2][i]);
      for (int j = 1; j < i; j++) Min(dp[j - 1], ndp[j] + a[1][i]);
      R = false;
    } else {
      for (int j = 0; j < i; j++) Min(dp[j + 1], ndp[j] + a[2][i] + a[4][i]);
      for (int j = (L && R) + 1; j < i; j++)
        Min(dp[j - 1], ndp[j] + a[1][i] + a[3][i]);
      for (int j = L; j < i; j++) Min(dp[j], ndp[j] + a[1][i] + a[4][i]);
      for (int j = R; j < i; j++) Min(dp[j], ndp[j] + a[2][i] + a[3][i]);
    }
  }
  if (s == n)
    dp[0] += a[3].back();
  else if (t == n)
    dp[0] += a[1].back();
  else
    dp[0] += a[1].back() + a[3].back();
  cout << dp[0];
}
