#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  if ((a + b) % 3 != 0) {
    cout << "NO" << endl;
    return;
  }
  long long mi = min(a, b);
  long long mx = max(a, b);
  long long d = mx - mi;
  if (d > 2 * mi) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
