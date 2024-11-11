#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = (1ll << 61);
const int MX = 70;
int n, k;
long long ans = 0, dp[MX][MX], a[MX];
long long DP(long long x, long long y) {
  if (x == n + 1 && y == k + 1) return 1;
  if (n - x + 1 < k - y + 1) return 0;
  long long &ret = dp[x][y];
  if (ret != -1) return ret;
  long long sum = 0;
  ret = 0;
  for (int i = x; i <= n; i++) {
    sum += a[i];
    if ((sum & ans) == ans) {
      ret = max(ret, DP(i + 1, y + 1));
    }
  }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 62; i >= 0; i--) {
    memset(dp, -1, sizeof(dp));
    ans ^= (1ll << i);
    if (DP(1, 1) == 0) ans ^= (1ll << i);
  }
  cout << ans << endl;
}
