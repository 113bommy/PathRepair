#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int t, n, x, a, b, da, db, cnt, p, res, l, s, i;
  cin >> x >> t >> a >> b >> da >> db;
  bool flag = false;
  for (i = 0; i <= t; i++) {
    p = a - (i * da);
    l = x - p;
    if (l <= b) {
      s = b - l;
      if (s % db == 0 && s / db <= t) flag = true;
    }
    if (flag) break;
  }
  if (x <= a) {
    s = a - x;
    if (s % da == 0 && s / da <= t) flag = true;
  }
  if (x <= b) {
    s = b - x;
    if (s % db == 0 && s / db <= t) flag = true;
  }
  if (flag || x == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
