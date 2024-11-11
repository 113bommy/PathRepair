#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long p[5005], a[5005], dp[5005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      p[i]++;
      a[i] /= 2;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    dp[i] = 1;
    for (long long j = 1; j < i; j++) {
      if (a[j] % a[i] == 0 && (p[i] - p[j] == i - j || p[i] < i - j))
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans;
  return 0;
}
