#include <bits/stdc++.h>
using namespace std;
long long n, h1[100010], h2[100010], dp[100010][3];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> h1[i];
  for (int i = 1; i <= n; i++) cin >> h2[i];
  dp[1][0] = 0, dp[1][1] = h1[1], dp[1][2] = h2[1];
  for (int i = 2; i <= n; i++) {
    dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h1[i];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + h2[i];
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}
