#include <bits/stdc++.h>
using namespace std;
int n;
double a[10100];
double f(double x) {
  double mn = 0, mx = 0, sm = 0, ret = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i] - x;
    if (sm < 0) {
      ret = max(ret, fabs(sm - mx));
    } else
      ret = max(ret, fabs(sm - mn));
    mn = min(mn, sm);
    mx = max(mx, sm);
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  double l = -1e5, r = 1e5;
  for (int i = 0; i < 300; i++) {
    double g = (r - l) / 3 + l;
    double h = 2 * (r - l) / 3 + l;
    if (f(g) < f(h)) {
      r = h;
    } else {
      l = g;
    }
  }
  cout << fixed << setprecision(10) << f(l) << endl;
}
