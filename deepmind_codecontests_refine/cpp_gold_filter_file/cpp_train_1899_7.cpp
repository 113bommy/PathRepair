#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long d, m, b, k;
    cin >> d >> m;
    if (d == 1) {
      cout << 1 % m << '\n';
      continue;
    }
    long long n = log2(d);
    vector<long long> dp(n + 1);
    dp[0] = 2 % m;
    for (b = 1, k = 2; b < n; ++b, k <<= 1) {
      dp[b] = (dp[b - 1] * k) % m;
      dp[b] = (dp[b] + dp[b - 1]) % m;
    }
    dp[n] = ((d + 1 - k) * dp[n - 1]) % m;
    dp[n] = (dp[n] + dp[n - 1]) % m;
    cout << (dp[n] - 1 + m) % m << '\n';
  }
}
