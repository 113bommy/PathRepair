#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
struct point {
  double x, y, z;
  point &operator-=(const point &p) {
    x -= p.x;
    y -= p.y;
    z -= p.z;
    return *this;
  }
  point &operator*=(double k) {
    x *= k;
    y *= k;
    z *= k;
    return *this;
  }
  point &operator/=(double k) {
    x /= k;
    y /= k;
    z /= k;
    return *this;
  }
  point &operator+=(const point &p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
  }
  point(double x0 = 0, double y0 = 0, double z0 = 0) {
    x = x0;
    y = y0;
    z = z0;
  };
};
struct place {
  double a, b, c;
};
double GetK(const point &p, const place &pl) {
  return (pl.a * p.x + pl.b * p.y + pl.c * p.z + 0.0) /
         (pl.a * pl.a + pl.b * pl.b + pl.c * pl.c);
}
point transtoPL(const point &p, const place &pl) {
  point ans = p, normal(pl.a, pl.b, pl.c);
  double K = GetK(p, pl);
  normal *= K;
  return (ans -= normal);
}
double distanc(const point &s, const point &f) {
  return sqrt((s.x - f.x) * (s.x - f.x) + (s.y - f.y) * (s.y - f.y) +
              (s.z - f.z) * (s.z - f.z));
}
point transtoOXY(const point &p, const place &pl) {
  if (pl.a == 0 && pl.b == 0) return point(p.x, p.y, 0);
  if (pl.b == 0 && pl.c == 0) return point(p.y, p.z, 0);
  if (pl.c == 0 && pl.a == 0) return point(p.z, p.x, 0);
  point ans = transtoPL(p, pl);
  point O(0, 0, 0);
  double aa = distanc(O, ans), bb = sqrt(pl.b * pl.b + pl.c * pl.c),
         cc = sqrt(ans.x * ans.x + (pl.c + ans.y) * (pl.c + ans.y) +
                   (ans.z - pl.b) * (ans.z - pl.b));
  if (abs(aa) < eps)
    return point(0, 0, 0);
  else {
    double ang = acos((aa * aa + bb * bb - cc * cc) / (2 * aa * bb));
    if (ans.x < eps) ang = -ang;
    return point(aa * cos(ang), aa * sin(ang), 0);
  }
}
bool outside(const point cent, const point p, const double r) {
  return distanc(p, cent) > r + eps;
}
point GetC(const point &A, const point &B, const point &C) {
  double a = A.x - B.x, b = A.y - B.y,
         c = A.x * A.x + A.y * A.y - B.x * B.x - B.y * B.y;
  c /= 2;
  double d = A.x - C.x, e = A.y - C.y,
         f = A.x * A.x + A.y * A.y - C.x * C.x - C.y * C.y;
  f /= 2;
  return point((c * e - b * f) / (a * e - d * b),
               (a * f - d * c) / (a * e - b * d));
}
void createCirc3(const point &a, const point &b, const point &c, point &cent,
                 double &r) {
  cent = GetC(a, b, c);
  r = distanc(cent, a);
}
void createCirc2(const point &a, const point &b, const vector<point> &tp, int n,
                 point &cent, double &r) {
  cent = a;
  cent += b;
  cent /= 2;
  r = distanc(cent, a);
  for (int i = 0; i < n; i++)
    if (outside(cent, tp[i], r)) createCirc3(a, b, tp[i], cent, r);
}
void createCirc1(const point &a, const vector<point> &tp, int n, point &cent,
                 double &r) {
  cent = a;
  r = 0;
  for (int i = 0; i < n; i++)
    if (outside(cent, tp[i], r)) createCirc2(a, tp[i], tp, i, cent, r);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<point> p(n);
  place pl;
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> p[i].z;
  vector<point> tp(n);
  for (int i = 0; i < m; i++) {
    cin >> pl.a >> pl.b >> pl.c;
    for (int j = 0; j < n; j++) {
      tp[j] = transtoOXY(p[j], pl);
    }
    if (n == 1) {
      cout << fixed << setprecision(12) << 0.00000000 << endl;
      continue;
    }
    double curr = 0;
    random_shuffle(tp.begin(), tp.end());
    point currcent = tp[0];
    for (int j = 1; j < n; j++)
      if (outside(currcent, tp[j], curr)) {
        currcent = tp[j];
        curr = 0;
        for (int k = 0; k < j; k++)
          if (outside(currcent, tp[k], curr)) {
            currcent = point((tp[j].x + tp[k].x) / 2, (tp[j].y + tp[k].y) / 2);
            curr = distanc(currcent, tp[k]);
            for (int l = 0; l < k; l++)
              if (outside(currcent, tp[l], curr)) {
                currcent = GetC(tp[j], tp[k], tp[l]);
                curr = distanc(currcent, tp[j]);
              }
          }
      }
    cout << fixed << setprecision(12) << curr << endl;
  }
  return 0;
}
