#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long n, k;
long long t[2002];
long long dp[4002];
long long ch[4002];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> t[i];
  }
  t[n + 1] = t[1];
  dp[2000] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= 4000; j++) {
      if (t[i] == t[i + 1]) {
        ch[j] = dp[j] * k;
      } else {
        ch[j - 1] += dp[j], ch[j + 1] += dp[j], ch[j] += dp[j] * (k - 2);
      }
    }
    for (long long i = 1; i <= 4000; i++) {
      ch[i] %= mod;
      dp[i] = ch[i];
      ch[i] = 0;
    }
  }
  long long sum = 0;
  for (long long i = 2001; i <= 4000; i++) {
    sum += dp[i];
  }
  cout << sum % mod << "\n";
  return 0;
}
