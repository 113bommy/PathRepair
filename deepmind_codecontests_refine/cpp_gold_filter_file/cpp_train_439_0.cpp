#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
long long power(long long a, long long b, long long c) {
  long long res = 1;
  while (b) {
    if (b & 1LL) res = (res * a) % c;
    a = (a * a) % c;
    b /= 2;
  }
  return res;
}
void solve() {
  vector<long long> a(2);
  for (long long &x : a) cin >> x;
  sort(a.begin(), a.end());
  if (a[1] >= 2 * a[0]) {
    cout << a[0] << endl;
    return;
  }
  long long ans = a[1] / 2;
  a[1] = a[1] % 2;
  a[0] -= ans;
  ans += (a[0] + a[1]) / 3;
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
