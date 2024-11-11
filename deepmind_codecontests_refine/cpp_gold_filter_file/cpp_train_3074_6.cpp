#include <bits/stdc++.h>
using namespace std;
long long int dp[65][2] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  long long int s, x, sub = 0;
  cin >> s >> x;
  if (s == x) sub = 2;
  if (x == 0) {
    if (s % 2)
      cout << "0";
    else
      cout << "1";
    return 0;
  }
  if (s % 2 == 1 && x % 2 == 1) dp[0][0] = 2;
  if (s % 2 == 0 && x % 2 == 0) dp[0][0] = 1, dp[0][1] = 1;
  s /= 2;
  x /= 2;
  for (int i = 1; i <= 64; i++) {
    if (s % 2 == 1 && x % 2 == 1) dp[i][0] = 2 * dp[i - 1][0];
    if (s % 2 == 0 && x % 2 == 0) {
      dp[i][0] += dp[i - 1][0];
      dp[i][1] += dp[i - 1][0];
    }
    if (s % 2 == 1 && x % 2 == 0) {
      dp[i][0] += dp[i - 1][1];
      dp[i][1] += dp[i - 1][1];
    }
    if (s % 2 == 0 && x % 2 == 1) {
      dp[i][1] = 2 * dp[i - 1][1];
    }
    s /= 2;
    x /= 2;
  }
  cout << dp[64][0] - sub;
  return 0;
}
