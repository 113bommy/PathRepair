#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, k, d;
int dp[200], dp1[200];
int main() {
  cin >> n >> k >> d;
  dp[0] = 0;
  dp1[0] = 1;
  dp[1] = (1 >= d);
  dp1[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(k, i); j++) {
      if (j >= d) {
        dp[i] = (dp[i] + dp1[i - j]) % mod;
      } else {
        dp[i] = (dp[i] + dp[i - j]) % mod;
      }
      dp1[i] = (dp1[i] + dp1[i - j]) % mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
