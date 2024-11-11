#include <bits/stdc++.h>
using namespace std;
const int64_t M1 = 998244353;
const int64_t M2 = 1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int64_t l, r;
  cin >> l >> r;
  if (l + l <= r + 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t t;
  cin >> t;
  while (t--) solve();
}
