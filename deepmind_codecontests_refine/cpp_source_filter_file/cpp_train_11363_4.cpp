#include <bits/stdc++.h>
using namespace std;
int dp[600], n;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n;
  dp[3] = 6, dp[4] = 18;
  for (int i = 5; i <= n; i++) {
    dp[i] = dp[i - 1] + (n * (n - 1));
  }
  cout << dp[n] << endl;
}
