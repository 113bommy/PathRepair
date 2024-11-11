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
  long long dp[total_birds + 1][n + 1];
  memset(dp, -1, sizeof(dp));
  for (int j = 0; j <= n; j++) dp[0][j] = w;
  for (int i = 0; i <= total_birds; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= birds[j]; k++) {
        if (dp[i][j] < k * cost[j]) continue;
        if (i + k > total_birds) continue;
        long long mana = min((dp[i][j] - k * cost[j]) + x, w + b * (i + k));
        if (dp[i + k][j + 1] == -1) {
          dp[i + k][j + 1] = mana;
        } else {
          dp[i + k][j + 1] = max(dp[i + k][j + 1], mana);
        }
      }
    }
  }
  for (int i = total_birds; i >= 0; --i) {
    if (dp[i][n] != -1) {
      cout << i << endl;
      return 0;
    }
  }
}
