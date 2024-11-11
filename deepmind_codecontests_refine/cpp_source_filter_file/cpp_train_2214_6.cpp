#include <bits/stdc++.h>
using namespace std;
vector<long long> temp(3001, 0);
vector<vector<long long> > dp(3001, temp);
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long i, j, k, l;
  for (i = 0; i < n; i++) cin >> v[i];
  for (i = 0; i < 3001; i++) {
    for (j = 0; j < 3001; j++) dp[i][j] = 0;
  }
  for (i = 0; i < n; i++) {
    dp[v[i]][i] = dp[v[i]][i] + 1;
    if (i == 0) continue;
    for (j = 0; j < 3001; j++) dp[j][i] += dp[j][i - 1];
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      long long a = v[i];
      long long b = v[j];
      if (a == b) continue;
      if (dp[b][i] > 0 && dp[a][j] < dp[a][n - 1]) {
        long long val1 = dp[b][i];
        long long val2 = dp[a][n - 1] - dp[a][j];
        ans = ans + val1 * val2;
      }
    }
  }
  for (i = 0; i <= 3000; i++) {
    if (dp[i][n - 1] > 4) {
      long long val = 1;
      long long count = dp[i][n - 1];
      val = val * count;
      count--;
      val = val * count;
      val = val / 2LL;
      count--;
      val = val * count;
      val = val / 3LL;
      count--;
      val = val * count;
      val = val / 4LL;
      ans = ans + val;
    }
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
