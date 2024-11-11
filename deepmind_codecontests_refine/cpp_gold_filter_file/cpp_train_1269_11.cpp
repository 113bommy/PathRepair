#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  vector<int> dp(112345, 0);
  dp[1] = 1;
  for (int i = 2; i < 112345; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= mod;
  }
  int n, m;
  cin >> n >> m;
  cout << (dp[n + 1] + dp[m + 1] - 1) % mod * 2 % mod;
}
