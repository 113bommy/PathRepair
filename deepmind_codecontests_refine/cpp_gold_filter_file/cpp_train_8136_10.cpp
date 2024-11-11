#include <bits/stdc++.h>
using namespace std;
long long int dp[1000000][2];
int main() {
  int x, i, a[1000000], b[1000000];
  cin >> x;
  for (i = 0; i < x; i++) cin >> a[i];
  for (i = 0; i < x; i++) cin >> b[i];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  for (i = 1; i < x; i++) {
    if (i > 1) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + a[i];
      dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + b[i];
    } else {
      dp[i][0] = dp[i - 1][1] + a[i];
      dp[i][1] = dp[i - 1][0] + b[i];
    }
  }
  cout << max(dp[x - 1][0], dp[x - 1][1]);
  return 0;
}
