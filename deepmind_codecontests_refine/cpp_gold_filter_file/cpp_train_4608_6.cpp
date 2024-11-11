#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
void solve() {
  long long v, c, vv, cc;
  cin >> v >> c >> vv >> cc;
  long long f = 0;
  if (cc > min(v, c)) {
    cout << "NO\n";
    return;
  }
  v += c;
  vv += cc;
  if (vv > v) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (f == 1) {
  } else {
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
