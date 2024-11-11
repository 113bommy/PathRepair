#include <bits/stdc++.h>
using namespace std;
int n;
int x[300005], y[300005];
const int inf = 1e8;
int cx, cy;
bool ok(int w) {
  int xl = 0, xr = inf;
  int yl = 0, yr = inf;
  int zl = -inf, zr = inf;
  for (int i = 0; i < n; i++) {
    xl = max(xl, x[i] - w);
    yl = max(yl, y[i] - w);
    zl = max(zl, y[i] - x[i] - w);
    xr = min(xr, x[i] + w);
    yr = min(yr, y[i] + w);
    zr = min(zr, y[i] - x[i] + w);
  }
  for (int x = xl; x <= xr; x++) {
    int y = x + zl;
    y = max(y, yl);
    if (yl <= y && y <= xr && zl <= y - x && y - x <= zr) {
      if (x == 0 && y == 0) {
        cx = w;
        cy = w;
      } else {
        cx = x;
        cy = y;
      }
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(!cin.tie(0));
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    x[i] = count(begin(s), end(s), 'B');
    y[i] = count(begin(s), end(s), 'N');
  }
  int l = 0, r = 1000005, o = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      o = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  ok(o);
  cout << o << '\n';
  cout << string(cx, 'B');
  cout << string(cy, 'N');
  cout << '\n';
}
