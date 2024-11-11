#include <bits/stdc++.h>
using namespace std;
long double a, b, c, d, ans = 1.0e10, l[4], r[4], p[2], P[2];
bool isPos(long double a, long double b, long double c, long double d,
           long double mid) {
  l[0] = a, r[0] = a;
  l[1] = b - mid, r[1] = b + mid;
  l[2] = c - mid, r[2] = c + mid;
  l[3] = d - mid, r[3] = d + mid;
  p[0] = min(min(l[0] * l[3], l[0] * r[3]), min(r[0] * l[3], r[0] * r[3]));
  p[1] = max(max(l[0] * l[3], l[0] * r[3]), max(r[0] * l[3], r[0] * r[3]));
  P[0] = min(min(l[1] * l[2], l[1] * r[2]), min(r[1] * l[2], r[1] * r[2]));
  P[1] = max(max(l[1] * l[2], l[1] * r[2]), max(r[1] * l[2], r[1] * r[2]));
  if (p[0] > P[1] || P[0] > p[1]) return false;
  return true;
}
void binSearch(long double a, long double b, long double c, long double d) {
  int iter = 100;
  long double l = 0.0, h = 1.0e10, mid;
  while (iter--) {
    mid = (l + h) / 2.0;
    if (isPos(a - mid, b, c, d, mid) || isPos(a + mid, b, c, d, mid))
      h = mid, ans = min(ans, mid);
    else
      l = mid;
  }
}
int main() {
  cin >> a >> b >> c >> d;
  binSearch(a, b, c, d);
  binSearch(d, b, c, a);
  binSearch(c, a, d, b);
  binSearch(b, a, d, c);
  cout << setprecision(16) << ans;
  return 0;
}
