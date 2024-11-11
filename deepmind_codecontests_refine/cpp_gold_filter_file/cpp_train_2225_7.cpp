#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> isPrime(100001, 1);
  for (int i = 2; i <= 100000; i++) {
    if (isPrime[i])
      for (int j = i + i; j <= 100000; j += i) isPrime[j] = 0;
  }
  isPrime[1] = 0;
  vector<int> dp(100001, 0);
  for (int i = 0; i < n; i++) {
    int best = 1;
    double s = sqrt(v[i]);
    for (int j = 1; j <= s; j++) {
      if (v[i] % j == 0) {
        if (isPrime[j]) best = max(best, dp[j] + 1);
        if (isPrime[v[i] / j]) best = max(best, dp[v[i] / j] + 1);
      }
    }
    for (int j = 1; j <= s; j++) {
      if (v[i] % j == 0) {
        if (isPrime[j]) dp[j] = max(dp[j], best);
        if (isPrime[v[i] / j]) dp[v[i] / j] = max(dp[v[i] / j], best);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i <= 100000; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
