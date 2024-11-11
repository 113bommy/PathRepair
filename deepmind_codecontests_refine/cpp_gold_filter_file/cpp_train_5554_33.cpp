#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
struct pnt {
  long double x, y;
  pnt(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
  inline pnt operator-() const { return pnt(-x, -y); }
  inline pnt operator+(const pnt &p) const { return pnt(x + p.x, y + p.y); }
  inline pnt operator-(const pnt &p) const { return pnt(x - p.x, y - p.y); }
  inline pnt operator*(const long double &k) const { return pnt(x * k, y * k); }
  inline pnt operator/(const long double &k) const { return pnt(x / k, y / k); }
  inline long double operator*(const pnt &p) const { return x * p.y - y * p.x; }
  inline long double operator^(const pnt &p) const { return x * p.x + y * p.y; }
  inline bool operator==(const pnt &p) const {
    return fabs(x - p.x) + fabs(y - p.y) < eps;
  }
  inline bool operator!=(const pnt &p) const {
    return fabs(x - p.x) + fabs(y - p.y) > eps;
  }
  inline long double d2() const { return x * x + y * y; }
  inline long double d() const { return sqrt(d2()); }
  inline pnt norm() const { return *this / d(); }
  inline pnt ort() const { return pnt(-y, x); }
  inline long double ang() const { return atan2(y, x); }
  pnt rot(long double a) {
    long double co = cos(a), si = sin(a);
    return pnt(x * co - y * si, x * si + y * co);
  }
};
inline pnt pntByAng(long double a) { return pnt(cos(a), sin(a)); }
int xp, yp, vp, x, y, v, r;
double R;
long double ans = 1e100;
pnt Tangent(pnt A, int sign) {
  long double d = A.d();
  long double ang = asin(r / d);
  return A + ((-A).rot(ang * sign) * cos(ang));
}
long double rDist(pnt a, pnt b) {
  long double x = b.ang() - a.ang();
  while (x < -M_PI) x += 2 * M_PI;
  while (x > M_PI) x -= 2 * M_PI;
  return fabs(x) * r;
}
long double F(long double ang) {
  pnt A(x, y), B = pntByAng(ang) * R;
  if (A == B) return 0;
  long double dist = (B - A).d();
  long double res = dist;
  if (((B - A) ^ -A) > 0 && ((A - B) ^ -B) > 0 &&
      fabs(A ^ (B - A).ort()) / dist < r) {
    res = 1e100;
    for (int s1 = -1; s1 <= 1; s1 += 2)
      for (int s2 = -1; s2 <= 1; s2 += 2) {
        pnt AA = Tangent(A, s1);
        pnt BB = Tangent(B, s2);
        res = min(res, (AA - A).d() + (BB - B).d() + rDist(AA, BB));
      }
  }
  long double t = res / v, w = vp / R, w2 = v / R, st = atan2(yp, xp);
  long double diff = ang - (st + w * t);
  diff -= floor(diff / (2 * M_PI)) * (2 * M_PI);
  while (diff < -eps) diff += 2 * M_PI;
  while (diff > 2 * M_PI - eps) diff -= 2 * M_PI;
  assert(w2 > w);
  long double T1 = diff / (w + w2);
  long double T2 = (2 * M_PI - diff) / (w2 - w);
  res = t + min(T1, T2);
  ans = min(ans, res);
  return res;
}
void Solve(double L, double R) {
  const int K = 100;
  for (int t = 0; t < (int)(K); t++) {
    double a = (4 * L + R) / 5;
    double b = (L + 4 * R) / 5;
    if (F(a) < F(b))
      R = b;
    else
      L = a;
  }
}
int main() {
  scanf("%d%d%d", &xp, &yp, &vp);
  scanf("%d%d%d%d", &x, &y, &v, &r);
  R = sqrt(xp * xp + yp * yp);
  int N = 100;
  for (int i = 0; i < (int)(N); i++)
    Solve(2 * M_PI * i / N, 2 * M_PI * (i + 1) / N);
  printf("%.20f\n", (double)ans);
  return 0;
}
