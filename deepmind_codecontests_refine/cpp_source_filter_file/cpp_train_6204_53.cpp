#include <bits/stdc++.h>
using namespace std;
const long double inf = 1e7;
void fail() {
  cout << -1 << endl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  long double mn = 0, mx = inf;
  for (int _ = 0; _ < (n); ++_) {
    int rx, ry, vx, vy;
    cin >> rx >> ry >> vx >> vy;
    if (vx == 0) {
      if (x1 >= rx || x2 <= rx) fail();
    } else {
      long double lo = x1 - rx, hi = x2 - rx;
      if (vx < 0) {
        vx *= -1;
        lo *= -1;
        hi *= -1;
        swap(lo, hi);
      }
      lo /= vx, hi /= vx;
      mn = max(mn, lo);
      mx = min(mx, hi);
    }
    if (vy == 0) {
      if (y1 >= ry || y2 <= ry) fail();
    } else {
      long double lo = y1 - ry, hi = y2 - ry;
      if (vy < 0) {
        vy *= -1;
        lo *= -1;
        hi *= -1;
        swap(lo, hi);
      }
      lo /= vy, hi /= vy;
      mn = max(mn, lo);
      mx = min(mx, hi);
    }
  }
  if (mx <= mn + 1e-8) fail();
  cout.precision(8);
  cout << mn << endl;
}
