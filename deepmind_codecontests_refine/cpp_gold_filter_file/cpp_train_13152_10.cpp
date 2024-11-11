#include <bits/stdc++.h>
using namespace std;
int dp[4007];
int main() {
  ios::sync_with_stdio(false);
  int n, a;
  cin >> n;
  fill(dp + 1, dp + 4007, -1e9);
  for (int i = 0; i < 3; i++) {
    cin >> a;
    for (int j = a; j <= n; j++) {
      dp[j] = max(dp[j], dp[j - a] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
