#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int ms = 1005;
int n, k;
int a[ms], dp[ms][ms];
int solve(int x) {
  dp[0][0] = 1;
  int li = 0;
  for (int i = 1; i <= n; ++i) {
    while (a[i] - a[li + 1] >= x) li++;
    dp[i][0] = dp[i - 1][0];
    for (int j = 1; j <= k && j <= i; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[li][j - 1];
      dp[i][j] %= mod;
    }
  }
  return dp[n][k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i * (k - 1) <= a[n]; i++) {
    ans = ans + solve(i);
    ans %= mod;
  }
  cout << ans;
  return 0;
}
