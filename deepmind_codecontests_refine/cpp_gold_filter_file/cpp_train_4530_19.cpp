#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int n, r, v;
bool solve(double t, double R, double V, double L) {
  double a = (t * V) / (2.0 * R);
  double A = 2.0 * sin(-a);
  double B = (L - t * V) / R;
  if (fabs(a) < 1e-16) {
    return L <= t * V;
  }
  if (A >= 0) {
    return (L - t * V) / R / A <= 1.0;
  }
  return (L - t * V) / R / A >= -1.0;
}
void solve() {
  int f, s;
  scanf("%d%d", &s, &f);
  double l = 0.0, r = 1e12;
  for (int i = 0; i < 60; ++i) {
    double m = (l + r) / 2.0;
    if (solve(m, ::r, ::v, f - s)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%.10lf\n", (l + r) / 2.0);
}
int main() {
  scanf("%d%d%d", &n, &r, &v);
  for (int i = 0; i < n; ++i) {
    solve();
  }
  cerr << clock() << endl;
  return 0;
}
