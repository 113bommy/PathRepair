#include <bits/stdc++.h>
using namespace std;
long long T;
long long n, mod;
long long C[4000005];
long long dp[4000005];
long long sum = 0;
signed main() {
  cin >> n >> mod;
  dp[n] = 1;
  C[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    dp[i] = C[i + 1];
    for (long long j = 2; j * i <= n; j++) {
      long long dn = i * j, up = min(n, (i + 1) * j - 1);
      dp[i] = (dp[i] + (C[dn] - C[up + 1] + mod) % mod) % mod;
    }
    C[i] = C[i + 1] + dp[i];
  }
  cout << dp[1] << endl;
  return 0;
}
