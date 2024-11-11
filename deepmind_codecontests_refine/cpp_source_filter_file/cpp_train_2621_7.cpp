#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A convert(B x) {
  stringstream ss;
  ss << x;
  A ret;
  ss >> ret;
  return ret;
}
const int oo = ~0u >> 2;
const double eps = 1e-6;
const int mn = 1000, mo = 100000007;
const int fx[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                      {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
struct po {
  double x, y, z;
  po() {}
  po(double X, double Y) { x = X, y = Y, z = 0; }
  po(double X, double Y, double Z) { x = X, y = Y, z = Z; }
  po operator/(double a) { return po(x / a, y / a, z / a); }
  po operator+(po p) { return po(x + p.x, y + p.y, z + p.z); }
  po operator-(po p) { return po(x - p.x, y - p.y, z - p.z); }
} a[mn], p[mn];
int n, m;
int sgn(double x) {
  if (fabs(x) <= eps) return 0;
  if (x > -eps) return 1;
  return -1;
}
double dis(po a, po b) {
  return sqrt(((double)(a.x - b.x) * (a.x - b.x)) +
              ((double)(a.y - b.y) * (a.y - b.y)) +
              ((double)(a.z - b.z) * (a.z - b.z)));
}
po Project(po p, int A, int B, int C) {
  if (!A && !B) return po(p.x, p.y);
  if (!B && !C) return po(p.y, p.z);
  if (!A && !C) return po(p.z, p.x);
  double alpha =
      (double)(A * p.x + B * p.y + C * p.z) /
      (((double)(A) * (A)) + ((double)(B) * (B)) + ((double)(C) * (C)));
  po pA = po(p.x - alpha * A, p.y - alpha * B, p.z - alpha * C);
  po pO = po(0, 0), pB = po(0, -C, B);
  double a = dis(pO, pA), b = dis(pO, pB), c = dis(pA, pB);
  if (!sgn(a)) return po(0, 0);
  double t = (((double)(a) * (a)) + ((double)(b) * (b)) - ((double)(c) * (c))) /
             (2 * a * b),
         Ang;
  if (!sgn(t - 1))
    Ang = acos(1);
  else if (!sgn(t + 1))
    Ang = acos(-1);
  else
    Ang = acos(t);
  if (sgn(pA.x) < 0) Ang *= -1;
  return po(a * cos(Ang), a * sin(Ang));
}
po calc(po A, po B, po C) {
  double a, b, c, d, e, f;
  a = B.x - A.x, b = B.y - A.y,
  c = (((double)(B.x) * (B.x)) + ((double)(B.y) * (B.y)) -
       ((double)(A.x) * (A.x)) - ((double)(A.y) * (A.y))) /
      2.0;
  d = C.x - A.x, e = C.y - A.y,
  f = (((double)(C.x) * (C.x)) + ((double)(C.y) * (C.y)) -
       ((double)(A.x) * (A.x)) - ((double)(A.y) * (A.y))) /
      2.0;
  return po((c * e - f * b) / (a * e - b * d),
            (c * d - f * a) / (b * d - e * a));
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].z;
  random_shuffle(a + 1, a + n + 1);
  while (m--) {
    int A, B, C;
    cin >> A >> B >> C;
    for (int i = 1; i <= n; ++i) p[i] = Project(a[i], A, B, C);
    po o = po(0, 0, 0);
    double R = 0;
    for (int i = 1; i <= n; ++i)
      if (sgn(dis(o, p[i]) - R) > 0) {
        o = p[i], R = 0;
        for (int j = 1; j <= i - 1; ++j)
          if (sgn(dis(o, p[j]) - R) > 0) {
            o = (p[i] + p[j]) / 2, R = dis(o, p[i]);
            for (int k = 1; k <= j - 1; ++k)
              if (sgn(dis(o, p[k]) - R) > 0)
                o = calc(p[i], p[j], p[k]), R = dis(o, p[i]);
          }
      }
    printf("%.10f\n", R);
  }
}
