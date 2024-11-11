#include <bits/stdc++.h>
using namespace std;
const int maxn = 2002;
void solve() {
  int n, k;
  cin >> n >> k;
  int ans = -1;
  vector<int> a(n + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + (i == a[i]);
    for (int cnt = 1; cnt <= i; cnt++) {
      dp[i][cnt] =
          max(dp[i - 1][cnt - 1], dp[i - 1][cnt] + ((i - cnt) == a[i]));
    }
  }
  for (int i = n; i > 0; i--)
    if (dp[n][i] >= k) ans = i;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
