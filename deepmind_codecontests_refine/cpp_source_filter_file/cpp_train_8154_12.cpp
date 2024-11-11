#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 35;
const long long MOD = 1e9 + 7;
long long n, u, r, ans = -inf;
long long a[N], b[N], k[N], p[N], dp[N][N];
void go(long long pos, long long lst) {
  if ((u - pos) % 2 == 0) {
    long long cur = 0;
    for (long long i = 1; i <= n; i++) cur += dp[pos][i] * k[i];
    ans = max(ans, cur);
    if (pos == u) return;
  }
  if (!lst) {
    for (long long i = 1; i <= n; i++) dp[pos + 1][i] = dp[pos][i] ^ b[i];
    go(pos + 1, 1);
  }
  for (long long i = 1; i <= n; i++) dp[pos + 1][i] = dp[pos][i] + r;
  go(pos + 1, 0);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> u >> r;
  for (long long i = 1; i <= n; i++) cin >> a[i], dp[0][i] = a[i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) cin >> k[i];
  for (long long i = 1; i <= n; i++) cin >> p[i];
  go(0, 0);
  cout << ans;
  return 0;
}
