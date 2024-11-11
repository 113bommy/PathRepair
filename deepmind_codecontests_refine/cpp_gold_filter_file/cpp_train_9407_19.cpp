#include <bits/stdc++.h>
using namespace std;
void preprocess() {}
long double cross(long double A[], long double B[], long double C[]) {
  long double AB[2], AC[2];
  AB[0] = B[0] - A[0];
  AB[1] = B[1] - A[1];
  AC[0] = C[0] - A[0];
  AC[1] = C[1] - A[1];
  long double cross = AB[0] * AC[1] - AB[1] * AC[0];
  return cross;
}
long double distance(long double A[], long double B[]) {
  long double d1 = A[0] - B[0];
  long double d2 = A[1] - B[1];
  return sqrt(d1 * d1 + d2 * d2);
}
int main() {
  long double C[2], B[2], Y1[2], Y2[2];
  preprocess();
  long double test, y1, y2, yw, xb, yb, r, xc;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  long double hi = xb, lo = 0.0;
  long double yc = yw - r;
  int flag = 0;
  while (hi - lo >= 0.00000000001) {
    xc = (lo + hi) / 2;
    long double m = (yc - yb) / (xc - xb);
    m *= -1;
    yw = (-m * xc) + yc;
    if (yw >= y2) {
      lo = xc;
      continue;
    } else if (yw <= y1) {
      hi = xc;
      continue;
    }
    C[0] = xc;
    C[1] = yc;
    B[0] = 0;
    B[1] = yw;
    Y1[0] = 0;
    Y2[0] = 0;
    Y2[1] = y2;
    Y1[1] = y1;
    long double dist1 = cross(B, C, Y1) / distance(C, B);
    long double dist2 = cross(B, C, Y2) / distance(C, B);
    if ((yw - y1) <= r) {
      hi = xc;
      continue;
    } else if (dist2 <= r) {
      lo = xc;
      continue;
    }
    cout.precision(10);
    cout << xc << endl;
    return 0;
  }
  printf("-1\n");
  return 0;
}
