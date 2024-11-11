#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long dpf[N], dpb[N], dp[N];
long long a[N];
int32_t main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 1;
    dpf[i] = 1;
    dpb[i] = 1;
    long long prev = i - 1;
    if (a[i] - a[prev] > 1) continue;
    if (a[i] == a[prev])
      dp[i] += dp[prev], dpb[i] += dpb[prev], dpf[i] += dpf[prev];
    if (a[i] == a[prev] + 1) dp[i] += dpb[prev], dpf[i] += dpb[prev];
    if (a[i] == a[prev] - 1) dp[i] += dpf[prev], dpb[i] += dpf[prev];
  }
  for (long long i = 1; i <= n; i++) ans = max(ans, dp[i]);
  cout << ans;
}
