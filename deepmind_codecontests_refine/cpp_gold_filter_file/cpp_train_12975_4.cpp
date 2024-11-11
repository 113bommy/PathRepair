#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
const int N = 1005;
int n, rad;
long double xi[N], ans[N];
long double sqr(long double x) { return x * x; }
int dcmp(long double a) {
  if (fabs(a) < eps) return 0;
  return a < 0 ? -1 : 1;
}
int inter(long double xa, long double ya, long double xb, long double yb) {
  return dcmp(sqr(xa - xb) + sqr(ya - yb) - 4 * sqr(rad)) < 0;
}
int main() {
  scanf("%d%d", &n, &rad);
  for (int i = 1; i <= n; ++i) cin >> xi[i];
  for (int i = 1; i <= n; ++i) {
    long double l = rad, r = 1e7;
    for (int _ = 1; _ <= 60; ++_) {
      long double mid = (l + r) / 2;
      int flag = 0;
      for (int j = 1; j <= i - 1; ++j)
        if (inter(xi[j], ans[j], xi[i], mid) ||
            (dcmp(xi[j] - 2 * rad - xi[i]) <= 0 &&
             dcmp(xi[i] - (xi[j] + 2 * rad)) <= 0 && dcmp(mid - ans[j]) <= 0)) {
          flag = 1;
          break;
        }
      if (flag)
        l = mid;
      else
        r = mid;
    }
    ans[i] = l;
  }
  for (int i = 1; i <= n; ++i) printf("%.8lf ", (double)ans[i]);
  return 0;
}
