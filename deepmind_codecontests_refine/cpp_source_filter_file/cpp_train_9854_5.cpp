#include <bits/stdc++.h>
using namespace std;
long long n, c, a[100005], dp[100005];
void solve() {
  cin >> n >> c;
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  if (c == 1) {
    cout << 0;
    return;
  }
  dp[0] = 0;
  multiset<long long> s;
  long long sum = 0;
  for (long long i = 1; i < n + 1; i++) {
    dp[i] = 100000000000000007LL;
    if (i - c > 0) s.erase(a[i - c]), sum -= a[i - c];
    s.insert(a[i]), sum += a[i];
    if (i >= c) dp[i] = dp[i - c] + sum - *s.begin();
    dp[i] = min(dp[i], dp[i - 1] + a[i]);
  }
  cout << dp[n] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
