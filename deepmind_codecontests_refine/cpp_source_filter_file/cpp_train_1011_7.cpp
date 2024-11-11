#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, a[siz], h[siz], fav[siz], have[siz], dp[500][5000];
long long go(long long rest, long long lft) {
  if (rest == 0 or lft == 0) return 0;
  if (dp[rest][lft] != -1) return dp[rest][lft];
  long long ret = 0;
  for (long long i = 0; i <= min(lft, k); i++) {
    ret = max(ret, h[i] + go(rest - 1, lft - i));
  }
  return dp[rest][lft] = ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n * k; i++) {
    long long x;
    cin >> x;
    have[x]++;
  }
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    fav[x]++;
  }
  for (long long i = 1; i <= k; i++) cin >> h[i];
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (long long i = 1; i <= 1e5; i++) {
    if (fav[i] == 0) continue;
    ans += go(fav[i], have[i]);
  }
  cout << ans << endl;
}
