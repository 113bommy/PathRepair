#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
bool okok(double v1, double l2, double r2, double l3, double r3, double l4,
          double r4) {
  double mini = fmin(fmin(l3 * l4, l3 * r4), fmin(r3 * l4, r3 * r4));
  double maxi = fmax(fmax(l3 * l4, l3 * r4), fmax(r3 * l4, r3 * r4));
  double tmini = fmin(v1 * l2, v1 * r2);
  double tmaxi = fmax(v1 * l2, v1 * r2);
  if (tmaxi <= mini || maxi <= tmini)
    return false;
  else
    return true;
}
int main() {
  cin >> a >> c >> d >> b;
  double l = 0, r = 1e18, mid;
  int T = 1e5;
  while (l < r && T--) {
    mid = (l + r) * 0.5;
    bool ok = 0;
    if (!ok)
      ok = okok(a - mid, b - mid, b + mid, c - mid, c + mid, d - mid, d + mid);
    if (!ok)
      ok = okok(a + mid, b - mid, b + mid, c - mid, c + mid, d - mid, d + mid);
    if (!ok)
      ok = okok(b - mid, a - mid, a + mid, c - mid, c + mid, d - mid, d + mid);
    if (!ok)
      ok = okok(b + mid, a - mid, a + mid, c - mid, c + mid, d - mid, d + mid);
    if (!ok)
      ok = okok(c - mid, d - mid, d + mid, a - mid, a + mid, b - mid, b + mid);
    if (!ok)
      ok = okok(c + mid, d - mid, d + mid, a - mid, a + mid, b - mid, b + mid);
    if (!ok)
      ok = okok(d - mid, c - mid, c + mid, a - mid, a + mid, b - mid, b + mid);
    if (!ok)
      ok = okok(d + mid, c - mid, c + mid, a - mid, a + mid, b - mid, b + mid);
    if (ok)
      r = mid;
    else
      l = mid;
  }
  mid = (l + r) * 0.5;
  printf("%.12f\n", mid);
  return 0;
}
