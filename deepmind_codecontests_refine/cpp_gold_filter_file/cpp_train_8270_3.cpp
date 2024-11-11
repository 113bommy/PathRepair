#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
  int r, g;
  cin >> r >> g;
  if (r < g) swap(r, g);
  int h;
  for (int i = 1000; i >= 1; i--) {
    if (i * (i + 1) / 2 - r <= g) {
      h = i;
      break;
    }
  }
  vector<vector<int>> dp(h + 1, vector<int>(h + 1, 0));
  for (int i = 0; i <= h; i++) dp[0][i] = 1;
  int k = h + 1, ans = 0;
  for (int i = 0; i <= r; i++) {
    if (i) dp[i % k][0] = 0;
    for (int j = 1; j <= h; j++) {
      dp[i % k][j] = 0;
      dp[i % k][j] = dp[(i - j + k) % k][j - 1];
      dp[i % k][j] = (dp[i % k][j] + dp[i % k][j - 1]) % mod;
      if (h * (h + 1) / 2 - i <= g && j == h) {
        ans = (ans + dp[i % k][j]) % mod;
      }
    }
  }
  cout << ans << '\n';
}
