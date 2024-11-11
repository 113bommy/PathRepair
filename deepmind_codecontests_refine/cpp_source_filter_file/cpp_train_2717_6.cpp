#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, f = 0, a, s = 0, m = -1e9, o = 1e9, x = 0, y = 0, z = 0;
  cin >> n;
  if (n == 1) {
    cin >> a;
    cout << a;
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    cin >> a;
    s = s + abs(a);
    if (a > 0) x = 1;
    if (a == 0) y = 1;
    if (a < 0) z = 1;
    if (a < 0) m = max(m, a);
    if (a > 0) o = min(o, a);
  }
  if (x + y + z >= 2 || y == 1)
    cout << s;
  else {
    if (z == 1)
      cout << s - 2 * m;
    else
      cout << s - 2 * o;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
