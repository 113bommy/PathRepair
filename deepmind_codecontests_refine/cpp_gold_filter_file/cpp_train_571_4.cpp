#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  double PI = asin(1.0) * 2.0;
  int i;
  double nMin = 10e20, nMax = -10e20;
  double px, py, ax, ay, bx, by, fx, fy;
  scanf("%lf %lf", &px, &py);
  scanf("%lf %lf", &fx, &fy);
  ax = fx;
  ay = fy;
  double d1, d2, d, pa, pb, ab, s, r;
  for (i = 1; i < n; i++) {
    scanf("%lf %lf", &bx, &by);
    d1 = (px - ax) * (bx - ax) + (py - ay) * (by - ay);
    d2 = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    pb = (px - bx) * (px - bx) + (py - by) * (py - by);
    pa = (px - ax) * (px - ax) + (py - ay) * (py - ay);
    ab = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    pb = sqrt(pb);
    pa = sqrt(pa);
    ab = sqrt(ab);
    if (d1 * d2 > 0 && d1 < d2) {
      r = (pa + pb + ab) / 2.0;
      s = r * (r - pa) * (r - pb) * (r - ab) * 4;
      d = s / ab / ab;
    } else if (d1 * d2 >= 1) {
      d = pb * pb;
    } else {
      d = pa * pa;
    }
    if (pb * pb > nMax) {
      nMax = pb * pb;
    }
    if (d < nMin) {
      nMin = d;
    }
    ax = bx;
    ay = by;
  }
  bx = fx;
  by = fy;
  d1 = (px - ax) * (bx - ax) + (py - ay) * (by - ay);
  d2 = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
  pb = (px - bx) * (px - bx) + (py - by) * (py - by);
  pa = (px - ax) * (px - ax) + (py - ay) * (py - ay);
  ab = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
  pb = sqrt(pb);
  pa = sqrt(pa);
  ab = sqrt(ab);
  if (d1 * d2 > 0 && d1 < d2) {
    r = (pa + pb + ab) / 2.0;
    s = r * (r - pa) * (r - pb) * (r - ab) * 4;
    d = s / ab / ab;
  } else if (d1 * d2 >= 1) {
    d = pb * pb;
  } else {
    d = pa * pa;
  }
  if (pb * pb > nMax) {
    nMax = pb * pb;
  }
  if (d < nMin) {
    nMin = d;
  }
  d = (nMax - nMin) * PI;
  printf("%.10lf\n", d);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
