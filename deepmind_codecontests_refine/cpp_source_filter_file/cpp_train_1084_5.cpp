#include <bits/stdc++.h>
using namespace std;
void init() {}
void solve() {
  int n;
  cin >> n;
  vector<int> x(2 * n), y(2 * n);
  int res = 0;
  for (int _n(n), i(0); i < _n; i++) {
    cin >> x[2 * i] >> y[2 * i] >> x[2 * i + 1] >> y[2 * i + 1];
    if (x[2 * i] > x[2 * i + 1]) swap(x[2 * i], x[2 * i + 1]);
    if (y[2 * i] > y[2 * i + 1]) swap(y[2 * i], y[2 * i + 1]);
    double xn = 0, xd = 0, yn = 0, yd = 0;
    for (int _n(i), j(0); j < _n; j++) {
      double xm = (x[2 * (i - j)] + x[2 * (i - j) + 1]) / 2.;
      double ym = (y[2 * (i - j)] + y[2 * (i - j) + 1]) / 2.;
      double v = pow(x[2 * (i - j)] - x[2 * (i - j) + 1], 3);
      xn += xm * v, xd += v;
      yn += ym * v, yd += v;
      xm = xn / xd, ym = yn / yd;
      if (xm - x[2 * (i - j - 1)] < 0.0000000001 ||
          xm - x[2 * (i - j - 1) + 1] > 0.0000000001) {
        cout << res << endl;
        return;
      }
      if (ym - y[2 * (i - j - 1)] < 0.0000000001 ||
          ym - y[2 * (i - j - 1) + 1] > 0.0000000001) {
        cout << res << endl;
        return;
      }
    }
    ++res;
  }
  cout << res << endl;
}
int main() {
  init();
  solve();
  return 0;
}
