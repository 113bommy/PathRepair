#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
double calc(double val) {
  double minres = 200010 * 30010, maxres = -200010 * 30010, smin = 0, smax = 0,
         cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur += a[i] - val;
    minres = min(minres, cur - smax);
    maxres = max(maxres, cur - smin);
    smin = min(cur, smin);
    smax = max(cur, smax);
  }
  return max(abs(minres), abs(maxres));
}
double ans() {
  double l = -20000.0, r = 20000.0;
  while (r - l > 1e-11) {
    double tl = (2 * l + r) / 3, tr = (2 * r + l) / 3;
    double res_tl = calc(tl), res_tr = calc(tr);
    if (res_tl - res_tr > 1e-11)
      l = tl;
    else if (res_tl - res_tr < 1e-11)
      r = tr;
    else if (res_tl - res_tr <= 1e-11)
      return res_tl;
  }
  return (l + r) / 2;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  printf("%0.6lf", calc(ans()));
}
