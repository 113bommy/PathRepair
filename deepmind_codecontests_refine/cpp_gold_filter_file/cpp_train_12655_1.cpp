#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = a[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (dp[i - 1] + a[i] < k) {
      ans += k - a[i] - dp[i - 1];
      dp[i] = k - dp[i - 1];
    } else {
      dp[i] = a[i];
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  return 0;
}
