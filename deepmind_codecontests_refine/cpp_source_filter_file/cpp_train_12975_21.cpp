#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const long double MAXY = 100000, MAXX = 100000, null = 0;
int main() {
  int n, r;
  cin >> n >> r;
  long double x[MAXN + 1];
  long double yx[MAXN + 1];
  vector<long double> y;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < MAXN; ++i) yx[i] = 0;
  bool t;
  long double mxy, mxx, delt, temp;
  for (int i = 0; i < n; ++i) {
    t = true;
    mxy = 0;
    for (int ix = max(null, x[i] - 2 * r); ix <= min(MAXX, x[i] + 2 * r);
         ++ix) {
      delt = x[i] - ix;
      if (yx[ix] == 0) continue;
      temp = sqrt(4 * r * r - delt * delt) + yx[ix];
      if (temp > mxy) {
        mxy = temp;
      }
    }
    if (mxy == 0) {
      yx[int(x[i])] = r;
    } else {
      yx[int(x[i])] = mxy;
    }
    y.push_back(yx[int(x[i])]);
  }
  for (int i = 0; i < n; ++i) cout << fixed << setprecision(10) << y[i] << ' ';
}
