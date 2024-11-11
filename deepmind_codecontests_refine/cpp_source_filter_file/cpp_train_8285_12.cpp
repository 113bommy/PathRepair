#include <bits/stdc++.h>
using namespace std;
long long k, mod = 1e9 + 7;
long long dp[805][805];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  dp[1][0] = dp[1][1] = 1;
  long long posa = 2;
  for (int i = 2; i < k + 1; i++) {
    if (posa > k) posa = k + 1;
    for (int L = 1; L <= posa; L++) {
      for (int R = 1; R <= posa; R++) {
        long long value = (dp[i - 1][L] * dp[i - 1][R]) % mod;
        dp[i][L + R] = (dp[i][L + R] + value);
        dp[i][L + R + 1] = (dp[i][L + R + 1] + value) % mod;
        dp[i][L + R] = (dp[i][L + R] + value * L * 2);
        dp[i][L + R] = (dp[i][L + R] + value * R * 2) % mod;
        dp[i][L + R - 1] =
            (dp[i][L + R - 1] + value * (L + R) * (L + R - 1)) % mod;
      }
    }
    posa *= 2;
  }
  cout << dp[k][1];
  return 0;
}
