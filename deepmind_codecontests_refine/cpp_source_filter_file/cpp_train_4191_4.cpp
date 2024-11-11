#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> R(n + 1), B(n + 1);
  long long red = 0, blue = 0;
  vector<vector<bool> > dp(n + 1, vector<bool>(k, 0));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    cin >> R[i] >> B[i];
    red += R[i], blue += B[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      dp[i][j] = dp[i - 1][(j - (R[i] % k) + k) % k];
      for (int l = 0; l <= min(k - 1, R[i]); l++) {
        if (dp[i - 1][(j - l + k) % k] && (R[i] - l) % k + B[i] >= k) {
          dp[i][j] = dp[i - 1][(j - l + k) % k];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < k - 1; i++) {
    if (dp[n][i]) ans = max(ans, (red + blue - i) / k);
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) solve();
}
