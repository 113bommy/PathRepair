#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, v;
  cin >> a >> v;
  double l, d, w;
  cin >> l >> d >> w;
  w = min(w, v);
  double s = w / a;
  double t = a * s * s / 2;
  double thead = 0;
  double vhead = 0;
  if (t < d) {
    double t1 = v / a;
    double t2 = (v - w) / a;
    double dd = t1 * v / 2 + t2 * (v + w) / 2;
    if (dd < d) {
      double t3 = (d - dd) / v;
      thead = t1 + t2 + t3;
      vhead = w;
    } else {
      double vv = sqrt((2 * a * d + w * w) / 2);
      thead = vv / a + (vv - w) / a;
      vhead = w;
    }
  } else {
    thead = sqrt(2 * d / a);
    vhead = a * thead;
  }
  double ttail = 0;
  double tt = (-vhead + sqrt(vhead * vhead + 2 * a * (l - d))) / a;
  if (vhead + tt * a < v)
    ttail = tt;
  else {
    double t1 = (v - vhead) / a;
    double rest = (l - w) - (vhead + v) * t1 / 2;
    double t2 = rest / v;
    ttail = t1 + t2;
  }
  cout << setiosflags(ios::fixed) << setprecision(12);
  cout << thead + ttail << endl;
  return 0;
}
