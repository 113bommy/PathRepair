#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int sx, sy;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cin >> sx >> sy;
  int l = 0, r = 0, u = 0, d = 0;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    if (x < sx) ++l;
    if (x > sx) ++r;
    if (y > sy) ++u;
    if (y < sy) ++d;
  }
  int mx = max(l, max(r, max(u, l)));
  cout << mx << endl;
  if (l == mx) {
    cout << sx - 1 << " " << sy << endl;
  } else if (r == mx) {
    cout << sx + 1 << " " << sy << endl;
  } else if (u == mx) {
    cout << sx << " " << sy + 1 << endl;
  } else {
    cout << sx << " " << sy - 1 << endl;
  }
  return 0;
}
