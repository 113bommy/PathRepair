#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n, k;
  cin >> n >> k;
  ll lo = 0, hi = 5;
  ll mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if ((n - mid) * (n - mid + 1) > 2 * (k + mid)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << hi << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _;
  _ = 1;
  while (_--) {
    solve();
  }
  return 0;
}
