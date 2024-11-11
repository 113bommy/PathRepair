#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
int main() {
  long long n, k, d;
  cin >> n >> k >> d;
  long long dp[n + 1], dp1[n + 1];
  memset(dp, 0, sizeof dp);
  memset(dp1, 0, sizeof dp1);
  dp[0] = 1;
  dp1[0] = 1;
  for (long long i = (1); i < (n + 1); i++) {
    for (long long j = (1); j < (k + 1); j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
        dp[i] %= M;
      }
    }
  }
  for (long long i = (1); i < (n + 1); i++) {
    for (long long j = (1); j < (d); j++) {
      if (i - j >= 0) {
        dp1[i] += dp1[i - j];
        dp1[i] %= M;
      }
    }
  }
  cout << (dp[n] - dp1[n] + M) % M << endl;
}
