#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long n, ans = 0;
long long a[N], dp[N], nxt[N];
map<long long, long long> mp[N];
void init() {
  ans = 0;
  for (long long i = 1; i <= n + 1; ++i) {
    dp[i] = 0;
    nxt[i] = -1;
    mp[i].clear();
  }
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  init();
  for (long long i = n; i >= 1; --i) {
    if (mp[i + 1].count(a[i])) {
      long long pos = mp[i + 1][a[i]];
      nxt[i] = pos;
      swap(mp[i], mp[pos + 1]);
      if (pos < n) mp[i][a[pos + 1]] = pos + 1;
    }
    mp[i][a[i]] = i;
  }
  for (long long i = n; i >= 1; --i) {
    if (nxt[i] == -1) continue;
    dp[i] = dp[nxt[i] + 1] + 1;
    ans += dp[i];
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
