#include <bits/stdc++.h>
using namespace std;
const long long MN = 201234, MOD = 998244353;
void solve() {
  long long a, b, ans = 0, n;
  cin >> a >> b >> n;
  if (a < b) swap(a, b);
  while (b < n && a < n) {
    if (a < b) swap(a, b);
    b += a;
    ans++;
  }
  cout << ans << '\n';
}
int32_t main() {
  long long q;
  cin >> q;
  while (q--) solve();
}
