#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[2 * 100011];
void read() {
  cin >> n;
  for (__typeof(n) i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
}
int dp[2 * 100011][3];
void solve() {
  sort(a + 1, a + n + 1);
  a[0] = {-1000000007, 0};
  a[n + 1] = {1000000007, 0};
  int res = 0;
  for (__typeof(n) i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    if (a[i - 1].first + a[i - 1].second < a[i].first)
      dp[i][0] = max(dp[i][0], dp[i - 1][2]);
    if (a[i - 1].first < a[i].first - a[i].second)
      dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
    if (a[i - 1].first + a[i - 1].second < a[i].first - a[i].second)
      dp[i][1] = max(dp[i - 1][2] + 1, dp[i][1]);
    dp[i][2] = max(dp[i - 1][0] + 1, dp[i][2]);
    if (a[i - 1].first + a[i - 1].second < a[i].first)
      dp[i][2] = max(dp[i - 1][2] + 1, dp[i][2]);
    dp[i][2] = max(dp[i - 1][1] + 1, dp[i][2]);
    res = max(res, dp[i][0]);
    res = max(res, dp[i][1]);
    res = max(res, dp[i][2]);
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    read();
    solve();
  }
}
