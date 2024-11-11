#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int l[N], r[N], a[N];
const long long INF64 = 9e18;
long long dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) dp[i] = INF64;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> a[i];
  long long ans = INF64;
  for (int i = 1; i <= n; i++) {
    long long rem = k, total = (long long)dp[i - 1];
    for (int j = i; j <= n; j++) {
      long long cntReloads = (max(0LL, a[j] - rem) + k - 1) / k;
      if (cntReloads > r[j] - l[j]) break;
      long long newrem = (rem + cntReloads * k) - a[j];
      total += a[j];
      if (j < n) {
        if (l[j - 1] + cntReloads < l[j]) dp[j] = min(dp[j], total + newrem);
      } else {
        ans = min(ans, total);
      }
      rem = newrem;
    }
  }
  if (ans == INF64) ans = -1;
  cout << ans << endl;
  return 0;
}
