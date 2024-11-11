#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
inline int dcmp(double x) { return abs(x) < eps ? 0 : x < 0 ? -1 : 1; }
inline double zero(double x) { return dcmp(x) == 0 ? 0 : x; }
struct Point {
  double x, y;
  Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
  void read() {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    x = a / b, y = c / d;
    inv();
  }
  void inv() {
    double t = x * x + y * y;
    x /= t, y /= t;
    x *= 10, y *= 10;
  }
};
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
bool operator<(const Point &a, const Point &b) {
  return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}
bool operator==(const Point a, const Point b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double Length(Point A) { return sqrt(Dot(A, A)); }
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
double angle(Point v) { return atan2(v.y, v.x); }
Point P[1005];
struct Event {
  Point midp;
  double d;
  Point u;
  bool operator<(const Event &rhs) const {
    if (!(midp == rhs.midp)) return midp < rhs.midp;
    return dcmp(d - rhs.d) < 0;
  }
} E[1000005];
const long long mod = (int)1e9 + 7;
inline int add(long long x, long long y) {
  x += y;
  x %= mod;
  return x;
}
inline int mul(long long x, long long y) {
  x *= y;
  x %= mod;
  return x;
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); ++(i)) P[i].read();
  int Elen = 0;
  for (int(i) = 0; (i) < (int)(n); ++(i))
    for (int(j) = 0; (j) < (int)(i); ++(j))
      if (!(P[i] == P[j])) {
        Point m = (P[i] + P[j]);
        double d = dcmp(P[i].x - P[j].y) == 0
                       ? 1e20
                       : (P[i].y - P[j].y) / (P[i].x - P[j].x);
        E[Elen++] = (Event){m, d, P[i] - P[j]};
      }
  sort(E, E + Elen);
  int res = 0;
  for (int i = 0, j, k, cnt, sum; i < Elen;) {
    long long c = 1;
    for (j = i, cnt = 0, sum = 0; j < Elen && E[j].midp == E[i].midp; ++cnt) {
      for (k = j; k < Elen && E[k].midp == E[j].midp &&
                  dcmp(Cross(E[j].u, E[k].u)) == 0;
           ++k)
        ;
      sum = add(sum, k - j), c = mul(c, k - j + 1), j = k;
    }
    if (cnt > 1) c = add(c, -sum - 1 + mod), res = add(res, c);
    i = j;
  }
  printf("%d\n", res);
  return 0;
}
