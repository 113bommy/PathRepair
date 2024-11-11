#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  long long w, b, x;
  cin >> w >> b >> x;
  int birds[n];
  for (int i = 0; i < n; i++) cin >> birds[i];
  int total_birds = accumulate(birds, birds + n, 0);
  long long cost[n];
  for (int i = 0; i < n; i++) cin >> cost[i];
  long long dp[n + 1][total_birds + 1];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= n; i++) dp[i][0] = w;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= total_birds; j++) {
      for (int k = 0; k <= birds[i]; k++) {
        long long mana_left = dp[i][j] - k * cost[i];
        if (mana_left < 0 || j + k > total_birds) {
          break;
        }
        long long mana_cap = w + b * (j + k);
        long long mana = min(mana_left + x, mana_cap);
        dp[i + 1][j + k] = max(dp[i + 1][j + k], mana);
      }
    }
  }
  for (int i = total_birds; i >= 0; --i) {
    if (dp[n][i] != -1) {
      cout << i << endl;
      return 0;
    }
  }
}
