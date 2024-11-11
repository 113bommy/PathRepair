#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fixAngle(double A) { return A > 1 ? 1 : (A < -1 ? -1 : A); }
double dcmp(double a, double b) {
  return fabs(a - b) < 1e-6 ? 0 : a > b ? 1 : -1;
}
enum State { CONTAIN, INSIDE, INTERSECT, APART, SAME };
State check(int x, int y, int r1, int a, int b, int r2) {
  double D = (hypot(((complex<double>(x, y) - complex<double>(a, b)).real()),
                    ((complex<double>(x, y) - complex<double>(a, b)).imag())));
  if (dcmp(r1 + r2, D) != 1) {
    return APART;
  }
  if (r1 > r2) {
    if (dcmp(r1, D + r2) != -1) return CONTAIN;
    return INTERSECT;
  }
  if (r2 > r1) {
    if (dcmp(r1, D + r2) != -1) return INSIDE;
    return INTERSECT;
  }
  if (r2 == r1) {
    if (dcmp(D, 0) != 0) {
      return INTERSECT;
    }
    return SAME;
  }
}
struct Ring {
  int x;
  int y;
  int r[2];
} ring[2];
int main() {
  cin >> ring[0].x >> ring[0].y >> ring[0].r[0] >> ring[0].r[1] >> ring[1].x >>
      ring[1].y >> ring[1].r[0] >> ring[1].r[1];
  int ans = 0;
  if (check(ring[0].x, ring[0].y, ring[0].r[0], ring[1].x, ring[1].y,
            ring[1].r[1]) != INTERSECT &&
      check(ring[0].x, ring[0].y, ring[0].r[0], ring[1].x, ring[1].y,
            ring[1].r[0]) != INTERSECT) {
    if (!(check(ring[0].x, ring[0].y, ring[0].r[0], ring[1].x, ring[1].y,
                ring[1].r[1]) == INSIDE &&
          check(ring[0].x, ring[0].y, ring[0].r[0], ring[1].x, ring[1].y,
                ring[1].r[0]) != INSIDE)) {
      ans++;
    }
  }
  if (check(ring[0].x, ring[0].y, ring[0].r[1], ring[1].x, ring[1].y,
            ring[1].r[1]) != INTERSECT &&
      check(ring[0].x, ring[0].y, ring[0].r[1], ring[1].x, ring[1].y,
            ring[1].r[0]) != INTERSECT) {
    if (!(check(ring[0].x, ring[0].y, ring[0].r[1], ring[1].x, ring[1].y,
                ring[1].r[1]) == INSIDE &&
          check(ring[0].x, ring[0].y, ring[0].r[1], ring[1].x, ring[1].y,
                ring[1].r[0]) != INSIDE)) {
      ans++;
    }
  }
  if (check(ring[1].x, ring[1].y, ring[1].r[0], ring[0].x, ring[0].y,
            ring[0].r[1]) != INTERSECT &&
      check(ring[1].x, ring[1].y, ring[1].r[0], ring[0].x, ring[0].y,
            ring[0].r[0]) != INTERSECT) {
    if (!(check(ring[1].x, ring[1].y, ring[1].r[0], ring[0].x, ring[0].y,
                ring[0].r[1]) == INSIDE &&
          check(ring[1].x, ring[1].y, ring[1].r[0], ring[0].x, ring[0].y,
                ring[0].r[0]) != INSIDE)) {
      ans++;
    }
  }
  if (check(ring[1].x, ring[1].y, ring[1].r[1], ring[0].x, ring[0].y,
            ring[0].r[1]) != INTERSECT &&
      check(ring[1].x, ring[1].y, ring[1].r[1], ring[0].x, ring[0].y,
            ring[0].r[0]) != INTERSECT) {
    if (!(check(ring[1].x, ring[1].y, ring[1].r[1], ring[0].x, ring[0].y,
                ring[0].r[1]) == INSIDE &&
          check(ring[1].x, ring[1].y, ring[1].r[1], ring[0].x, ring[0].y,
                ring[0].r[0]) != INSIDE)) {
      ans++;
    }
  }
  cout << ans;
}
