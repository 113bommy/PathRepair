#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long dp[n + 1], zero, one, MOD = 1e9 + 7;
  dp[0] = 0;
  long long sum[2] = {0};
  for (int i = 1; i <= n; i++) {
    dp[i] = sum[!(i & 1)] + 1;
    dp[i] %= MOD;
    sum[i & 1] += dp[i];
    sum[i & 1] %= MOD;
  }
  cout << sum[0] + sum[1];
  return 0;
}
