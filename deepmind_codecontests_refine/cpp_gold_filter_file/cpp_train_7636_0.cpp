#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double PI = acos((double)-1);
int ts, ts2, ts3, ts4;
int n, m;
long long gcd(long long x, long long y) {
  long long t;
  for (; y != 0;) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
class point {
 public:
  double x, y;
  point() { x = y = 0; }
  point(double a, double b) { x = a, y = b; }
  inline friend point operator+(const point &A, const point &B) {
    return point(A.x + B.x, A.y + B.y);
  }
  inline friend point operator-(const point &A, const point &B) {
    return point(A.x - B.x, A.y - B.y);
  }
  inline friend point operator*(const point &A, double p) {
    return point(A.x * p, A.y * p);
  }
  inline friend point operator/(const point &A, double p) {
    return point(A.x / p, A.y / p);
  }
  inline friend void operator+=(point &A, const point &B) { A = A + B; }
  inline friend void operator-=(point &A, const point &B) { A = A - B; }
  inline friend void operator*=(point &A, double B) { A = A * B; }
  inline friend void operator/=(point &A, double B) { A = A / B; }
  inline friend bool operator<(const point &A, const point &B) {
    return A.x < B.x - 1E-10 || fabs(A.x - B.x) < 1E-10 && A.y + 1E-10 < B.y;
  }
  inline friend bool operator==(const point &A, const point &B) {
    return !(A < B || B < A);
  }
  inline friend bool operator>(const point &A, const point &B) { return B < A; }
};
class XL {
 public:
  point a, b;
  XL() {}
  XL(point x, point y) {
    a = x;
    b = y;
  }
  XL(double t1, double t2, double t3, double t4) {
    a.x = t1;
    a.y = t2;
    b.x = t3;
    b.y = t4;
  }
};
inline double gag(double x) {
  if (x < -PI - 1E-10) return gag(x + 2 * PI);
  if (x > PI - 1E-10) return gag(x - 2 * PI);
  return x;
}
inline double gag2(double x) {
  if (x < -1E-10) return gag2(x + 2 * PI);
  if (x > 2 * PI - 1E-10) return gag2(x - 2 * PI);
  return x;
}
inline double sqr(double x) { return x * x; }
inline double chaji(const point &A, const point &B) {
  return A.x * B.y - B.x * A.y;
}
inline double dianji(const point &A, const point &B) {
  return A.x * B.x + A.y * B.y;
}
inline double dis(const point &A, const point &B) {
  return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}
inline double dis(const XL &A) { return dis(A.a, A.b); }
inline double dis(const point &A) { return sqrt(sqr(A.x) + sqr(A.y)); }
inline double atan2(const point &A) { return gag(atan2(A.y, A.x)); }
inline point shengcheng(double JD, double CD = 1.0) {
  return point(cos(JD) * CD, sin(JD) * CD);
}
inline short sgn(double x) {
  if (fabs(x) < 1E-10)
    return 0;
  else if (x < 0)
    return -1;
  else
    return 1;
}
point ref(point a, point b) { return point(b.x * 2 - a.x, b.y * 2 - a.y); }
point s[5];
double sqr(point a) { return sqr(a.x) + sqr(a.y); }
int getcan;
point getwjy(point a, point b, point c) {
  double d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
  getcan = 1;
  if (d == 0) {
    getcan = 0;
    return point(0, 0);
  }
  return point(
      (sqr(a) * (b.y - c.y) + sqr(c) * (a.y - b.y) + sqr(b) * (c.y - a.y)) / d,
      (sqr(a) * (c.x - b.x) + sqr(b) * (a.x - c.x) + sqr(c) * (b.x - a.x)) / d);
}
bool jud(point a, point b, point c) {
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  s[2] = getwjy(a, ref(c, b), b);
  if (getcan == 0) return 0;
  s[3] = getwjy(ref(a, b), b, c);
  if (getcan == 0) return 0;
  s[1] = ref(s[2], a);
  s[4] = ref(s[3], c);
  int i;
  for (i = 1; i <= 4; i++)
    if ((u1 = chaji(s[i % 4 + 1] - s[i], s[(i + 1) % 4 + 1] - s[i % 4 + 1])) *
            (u2 = chaji(s[(i + 1) % 4 + 1] - s[(i % 4 + 1)],
                        s[((i + 1) + 1) % 4 + 1] - s[(i + 1) % 4 + 1])) <=
        0)
      break;
  if (i <= 4) return 0;
  cout << "YES\n";
  for (int i = 1; i <= 4; i++)
    printf("%.9lf %.9lf%c", s[i].x, s[i].y, i == 4 ? '\n' : ' ');
  return 1;
}
int main() {
  long long i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  int _;
  point a, b, c;
  for (cin >> _; _--;) {
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (jud(c, a, b)) continue;
    if (jud(a, b, c)) continue;
    if (jud(b, c, a)) continue;
    cout << "NO\n\n";
  }
  return 0;
}
