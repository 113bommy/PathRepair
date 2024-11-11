#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 30;
const long long mod = 1e9 + 7;
const long long base = 1e18;
long double t, v;
long double x, y, x1, y2, ax, ay, wx, wy;
bool chk(long double p) {
  long double xnw = x, ynw = y;
  if (p >= t) {
    xnw = xnw + t * ax + (p - t) * wx;
    ynw = ynw + t * ay + (p - t) * wy;
  } else {
    xnw = xnw + p * ax;
    ynw = ynw + p * ay;
  }
  return ((p * p * v * v) >=
          ((xnw - x1) * (xnw - x1) + (ynw - y2) * (ynw - y2)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> x >> y >> x1 >> y2;
  cin >> v >> t;
  cin >> ax >> ay >> wx >> wy;
  long double l = 0, h = 1000000000;
  long long p = 10000;
  cout << fixed << setprecision(20);
  while (p--) {
    long double mid = (l + h) / 2.0;
    if (chk(mid))
      h = mid;
    else
      l = mid;
  }
  cout << h;
}
