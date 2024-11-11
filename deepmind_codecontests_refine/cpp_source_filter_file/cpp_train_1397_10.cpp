#include <bits/stdc++.h>
using namespace std;
long long a[101], b[101];
long long n, k;
long long dp[101][20005];
long long fun(long long idx, long long cur) {
  if (idx == n) {
    if (!cur) return 0;
    return -1e9;
  }
  long long &ret = dp[idx][cur + 10000];
  if (~ret) return ret;
  return ret = max(a[idx] + fun(idx + 1, cur + a[idx] - b[idx] * k),
                   fun(idx + 1, cur));
}
signed main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long ans = fun(0, 0);
  if (ans == 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
