#include <bits/stdc++.h>
using namespace std;
long long dp[100000], n;
int main() {
  cin >> n;
  if (n == 3) {
    cout << "3";
    return 0;
  }
  dp[1] = n - 2;
  dp[2] = dp[1] + n - 3;
  dp[3] = dp[2] + n - 4;
  for (int i = 4; i <= n; i++)
    if (i == n)
      dp[i] = dp[i - 1] + n - 3;
    else
      dp[i] = dp[i - 1] + n - 4;
  cout << dp[n];
  return 0;
}
