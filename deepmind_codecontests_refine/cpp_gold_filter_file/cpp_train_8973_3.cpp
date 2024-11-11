#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
void solve() {
  long long n;
  cin >> n;
  long long a[2 * n];
  for (long long i = 0; i < 2 * n; ++i) cin >> a[i];
  map<long long, long long> mp;
  mp[0] = 2 * n;
  long long bal = 0;
  for (long long i = 2 * n - 1; i >= n; --i) {
    if (a[i] == 2)
      bal++;
    else
      bal--;
    mp[bal] = i;
  }
  bal = 0;
  long long ans = 2 * n;
  if (mp.count(0)) {
    ans = std::min(ans, n + (n - (2 * n - mp[0])));
  }
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 2)
      bal++;
    else
      bal--;
    if (mp.count(-bal)) {
      ans = std::min(ans, (n - i - 1) + (n - (2 * n - mp[-bal])));
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
