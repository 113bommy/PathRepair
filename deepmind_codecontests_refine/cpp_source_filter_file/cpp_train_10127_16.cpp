#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long mx = v[0], mi = v[0], ans = 0;
  for (long long i = 1; i < n; i++) {
    if (v[i] >= mx) {
      ans += (mx - mi);
      mx = v[i];
      mi = v[i];
    } else {
      mi = min(v[i], mi);
    }
  }
  ans += mx;
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
