#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-15;
struct Point {
  long double x, y;
} o1, o2, o3;
long double t1, t2, Ax, Ay, Bx, By, Cx, Cy;
long double r1, r2, r3;
int dcmp(long double x) {
  if (fabs(x) < eps) return 0;
  return x > 0.0 ? 1 : -1;
}
long double sqr(long double t) { return t * t; }
long double GetDist(long double x1, long double y1, long double x2,
                    long double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y2 - y1));
}
long double GetSqrDist(long double x1, long double y1, long double x2,
                       long double y2) {
  return sqr(x1 - x2) + sqr(y2 - y1);
}
bool Seperated(Point o1, long double r1, Point o2, long double r2) {
  if (dcmp(GetSqrDist(o1.x, o1.y, o2.x, o2.y) - sqr(r1 + r2)) == 1) return true;
  return false;
}
long double Include(Point o1, long double r1, Point o2, long double r2) {
  if (dcmp(GetSqrDist(o1.x, o1.y, o2.x, o2.y) - sqr(fabs(r1 - r2))) <= 0)
    return true;
  return false;
}
bool InCircle(Point o) {
  if (dcmp(GetSqrDist(o.x, o.y, o1.x, o1.y) - sqr(r1)) == 1) return false;
  if (dcmp(GetSqrDist(o.x, o.y, o2.x, o2.y) - sqr(r2)) == 1) return false;
  if (dcmp(GetSqrDist(o.x, o.y, o3.x, o3.y) - sqr(r3)) == 1) return false;
  return true;
}
void GetInterval(Point o1, long double r1, Point o2, long double r2, Point &A1,
                 Point &A2) {
  long double d, a, b, c, p, q, r;
  long double cos_value[2], sin_value[2];
  d = GetDist(o1.x, o1.y, o2.x, o2.y);
  a = 2.0 * r1 * (o1.x - o2.x);
  b = 2.0 * r1 * (o1.y - o2.y);
  c = r2 * r2 - r1 * r1 - GetSqrDist(o1.x, o1.y, o2.x, o2.y);
  p = a * a + b * b;
  q = -2.0 * a * c;
  if (dcmp(d - (r1 + r2)) == 0 || dcmp(d - fabs(r1 - r2)) == 0) {
    cos_value[0] = -q / p / 2.0;
    sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);
    A1.x = r1 * cos_value[0] + o1.x;
    A1.y = r1 * sin_value[0] + o1.y;
    if (dcmp(GetSqrDist(A1.x, A1.y, o2.x, o2.y) - sqr(r2)) != 0) {
      A1.y = o1.y - r1 * sin_value[0];
    }
    A2 = A1;
    return;
  }
  r = c * c - b * b;
  cos_value[0] = (sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
  cos_value[1] = (-sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
  sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);
  sin_value[1] = sqrt(1 - cos_value[1] * cos_value[1]);
  A1.x = r1 * cos_value[0] + o1.x;
  A2.x = r1 * cos_value[1] + o1.x;
  A1.y = r1 * sin_value[0] + o1.y;
  A2.y = r1 * sin_value[1] + o1.y;
  if (dcmp(GetSqrDist(A1.x, A1.y, o2.x, o2.y) - r2 * r2) != 0)
    A1.y = o1.y - r1 * sin_value[0];
  if (dcmp(GetSqrDist(A2.x, A2.y, o2.x, o2.y) - r2 * r2) != 0)
    A2.y = o1.y - r1 * sin_value[1];
  if (dcmp(A1.y - A2.y) == 0 && dcmp(A1.x - A2.x) == 0) {
    if (A1.y > 0)
      A2.y = -A2.y;
    else
      A1.y = -A1.y;
  }
}
bool Judge(void) {
  if (Seperated(o1, r1, o2, r2)) return false;
  if (Seperated(o2, r2, o3, r3)) return false;
  if (Seperated(o1, r1, o3, r3)) return false;
  if (Include(o1, r1, o2, r2)) return true;
  if (Include(o2, r2, o3, r3)) return true;
  if (Include(o1, r1, o3, r3)) return true;
  Point A1, A2, A3, A4, A5, A6;
  GetInterval(o1, r1, o2, r2, A1, A2);
  GetInterval(o2, r2, o3, r3, A3, A4);
  GetInterval(o1, r1, o3, r3, A5, A6);
  if (InCircle(A1)) return true;
  if (InCircle(A2)) return true;
  if (InCircle(A3)) return true;
  if (InCircle(A4)) return true;
  if (InCircle(A5)) return true;
  if (InCircle(A6)) return true;
  return false;
}
int main() {
  cout << fixed << setprecision(10);
  Point A, B, C;
  cin >> t2 >> t1 >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  long double AB = GetDist(A.x, A.y, B.x, B.y);
  long double AC = GetDist(A.x, A.y, C.x, C.y);
  long double CB = GetDist(C.x, C.y, B.x, B.y);
  t1 += AB;
  t2 += AC + CB;
  if (t1 >= AC + CB) {
    cout << min(t1, t2) << endl;
    return 0;
  }
  long double L = 0.0, R = min(t1, t2 - CB);
  while (R - L > eps) {
    long double M = (R + L) / 2.0;
    o1 = A, o2 = B, o3 = C;
    r1 = M, r2 = t1 - M, r3 = t2 - CB - M;
    if (Judge())
      L = M;
    else
      R = M;
  }
  cout << L << endl;
  return 0;
}
