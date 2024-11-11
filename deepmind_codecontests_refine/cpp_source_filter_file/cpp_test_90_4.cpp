#include <bits/stdc++.h>
using namespace std;
long long x, y, n;
inline void solve() {
  cin >> x >> y;
  if (y % x == 0) {
    cout << x << endl;
    return;
  }
  if (x < y) {
    n = y % x * x;
    cout << (y + n) / 2 << endl;
  } else {
    cout << x + y << endl;
  }
}
int T;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
