#include <bits/stdc++.h>
using namespace std;
int dp[505][505], dp2[505];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) dp[i][i] = a[i];
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = i; k > j; k--) {
        if (dp[k][i] and dp[k][i] == dp[j][k - 1]) dp[j][i] = dp[k][i] + 1;
      }
    }
  }
  memset(dp2, INT_MAX, sizeof(dp2));
  for (int i = 0; i <= n; i++) dp2[i] = i + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j][i]) {
        if (j == 0)
          dp2[i] = 1;
        else
          dp2[i] = min(dp2[i], dp2[j - 1] + 1);
      }
    }
  }
  cout << dp2[n - 1];
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
