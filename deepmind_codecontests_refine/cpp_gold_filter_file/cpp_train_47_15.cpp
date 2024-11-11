#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> dp[3];
  dp[0].assign(n, 0);
  dp[1].assign(n, 0);
  dp[2].assign(n, 0);
  long long x, h, px = -9000000000, ph = 0, M = 1;
  for (int i = 0; i < n; ++i) {
    cin >> x >> h;
    if (i > 0) {
      if (px + ph < x) dp[2][i - 1] = 1 + dp[1][i - 1];
      if (x - h > px + ph) dp[0][i] = dp[2][i - 1] + 1;
      if (x - h > px)
        dp[0][i] = max(dp[0][i], max(1 + dp[1][i - 1], 1 + dp[0][i - 1]));
      dp[1][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
      M = max(M, max(dp[2][i - 1], max(dp[0][i], dp[1][i])));
      if (i == n - 1) {
        dp[2][i] = 1 + dp[1][i];
        M = max(M, dp[2][i]);
      }
    } else {
      dp[0][i] = 1;
      dp[1][i] = 0;
    }
    px = x;
    ph = h;
  }
  cout << M << endl;
  return 0;
}
