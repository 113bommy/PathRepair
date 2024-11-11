#include <bits/stdc++.h>
using namespace std;
int dp[102];
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> dp[i];
    dp[i] += dp[i - 1];
  }
  cin >> x >> y;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[n] - dp[i - 1] >= x && dp[n] - dp[i - 1] <= y && dp[i - 1] >= x &&
        dp[i - 1] <= y) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
