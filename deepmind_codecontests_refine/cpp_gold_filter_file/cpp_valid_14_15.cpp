#include <bits/stdc++.h>
using namespace std;
const int maxn = 2004;
int nums[maxn];
int dp[maxn][maxn];
int n, k;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> nums[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i - 1; j++) {
      dp[i][j] = dp[i - 1][j] + (i - j == nums[i]);
    }
    for (int j = 1; j < i; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; i++) {
    if (dp[n][i] >= k) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  for (int i = 0; i <= n; i++)
    for (int u = 0; u <= n; u++) dp[i][u] = 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
