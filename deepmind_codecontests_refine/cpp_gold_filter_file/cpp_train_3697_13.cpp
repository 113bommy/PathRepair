#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
int cmp(double x) {
  if (fabs(x) < 1e-15) return 0;
  if (x > 0) return 1;
  return -1;
}
const double pi = acos(-1.0);
inline double sqr(double x) { return x * x; }
struct point {
  double x, y;
  double atan;
  int id;
  long long w;
  point() {}
  point(double a, double b) : x(a), y(b) {}
  void input() { scanf("%lf%lf", &x, &y); }
  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend bool operator==(const point &a, const point &b) {
    return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
  }
  friend point operator*(const point &a, const double &b) {
    return point(a.x * b, a.y * b);
  }
  friend point operator*(const double &a, const point &b) {
    return point(a * b.x, a * b.y);
  }
  friend point operator/(const point &a, const double &b) {
    return point(a.x / b, a.y / b);
  }
  double norm() { return sqrt(sqr(x) + sqr(y)); }
} a[2100], pt[2100], p0;
double det(const point &a, const point &b) { return a.x * b.y - a.y * b.x; }
double dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }
double dist(const point &a, const point &b) { return (a - b).norm(); }
struct line {
  point a, b;
  line() {}
  line(point x, point y) : a(x), b(y) {}
};
line point_make_line(const point a, const point b) { return line(a, b); }
void PointProjLine(const point p, const point s, const point t, point &cp) {
  double r = dot((t - s), (p - s)) / dot(t - s, t - s);
  cp = s + r * (t - s);
}
bool operator<(const point &a, const point &b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
int n, num;
int b, c, d;
long long ans;
long long w[2100];
double atan2(const point &a) { return atan2(a.y, a.x); }
bool cmp2(point a, point b) { return b.atan < a.atan; }
void work(int dd) {
  int x;
  for (int i = 1; i <= num; i++) {
    if (pt[i].id == dd) {
      x = i;
      break;
    }
  }
  p0 = pt[x];
  swap(pt[x], pt[num]);
  for (int i = 1; i < num; i++) {
    pt[i].atan = atan2(pt[i] - p0);
    if (pt[i].atan < -eps) pt[i].atan += pi;
  }
  sort(pt + 1, pt + num, cmp2);
  double now = pt[1].atan;
  long long nn = pt[1].w;
  for (int i = 2; i < num; i++) {
    if (abs(pt[i].atan - now) < eps) {
      nn += pt[i].w;
    } else {
      now = pt[i].atan;
      if (nn >= 2) ans += pt[num].w * nn * (nn - 1LL) / 2LL;
      if (pt[num].w >= 2) ans += pt[num].w * (pt[num].w - 1LL) * nn / 2LL;
      nn = pt[i].w;
    }
  }
  if (nn >= 2) ans += pt[num].w * nn * (nn - 1LL) / 2LL;
  if (pt[num].w >= 2) ans += pt[num].w * (pt[num].w - 1LL) * nn / 2LL;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b >> c >> d;
    if (b == 0)
      a[i] = point(0.000, (double)d / (double)c);
    else if (c == 0)
      a[i] = point((double)d / (double)b, 0.000);
    else
      PointProjLine(point(0.0, 0.0),
                    point(1.0, ((double)d - (double)b * 1.0) / (double)c),
                    point(2.0, ((double)d - (double)b * 2.0) / (double)c),
                    a[i]);
  }
  sort(a + 1, a + 1 + n);
  num = 1;
  pt[1] = a[1];
  w[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (abs(a[i].x - pt[num].x) < eps && abs(a[i].y - pt[num].y) < eps) {
      w[num]++;
    } else {
      w[++num] = 1;
      pt[num] = a[i];
    }
  }
  ans = 0;
  for (int i = 1; i <= num; i++) {
    pt[i].w = w[i];
    if (w[i] > 2) ans += w[i] * (w[i] - 1LL) * (w[i] - 2LL) / 6;
    pt[i].id = i;
  }
  if (num >= 1) {
    int pp = num;
    for (int i = 1; i <= pp; i++) {
      work(i);
      num--;
      if (num == 1) break;
    }
  }
  cout << ans << endl;
  return 0;
}
