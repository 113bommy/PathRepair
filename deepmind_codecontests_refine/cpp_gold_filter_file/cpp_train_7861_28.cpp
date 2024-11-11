#include <bits/stdc++.h>
using namespace std;
const double ep = 1e-12;
const double pi = acos(-1);
struct pnt {
  double x, y;
  pnt(double x = 0, double y = 0) : x(x), y(y) {}
  inline pnt operator-(const pnt &a) const { return pnt(x - a.x, y - a.y); }
  inline pnt operator+(const pnt &a) const { return pnt(x + a.x, y + a.y); }
  inline pnt operator*(const double &a) const { return pnt(x * a, y * a); }
  inline pnt operator/(const double &a) const { return pnt(x / a, y / a); }
  inline double operator&(const pnt &a) const { return x * a.x + y * a.y; }
  inline double operator^(const pnt &a) const { return x * a.y - y * a.x; }
  inline void input() { x = y = 0, scanf("%lf %lf", &x, &y); }
  void FastInput() {
    int a, b;
    scanf("%d %d", &a, &b);
    x = 1.0 * a;
    y = 1.0 * b;
  }
  inline void print() { printf("%lf %lf\n", x, y); }
  inline bool operator<(const pnt &a) const {
    if (fabs(x - a.x) > ep) return x < a.x;
    return y < a.y;
  }
  inline bool operator==(const pnt &a) const {
    return fabs(x - a.x) < ep && fabs(y - a.y) < ep;
  }
  inline pnt Rotate(const double &angle) {
    pnt R = pnt(sin(angle), cos(angle)), C = *this;
    return pnt(C ^ R, C & R);
  }
  inline double dist() { return sqrt(x * x + y * y); }
  inline pnt norm() { return (*this) / dist(); }
} p[4000001];
inline double dist(pnt a) { return sqrt(a & a); }
inline pnt rot(pnt p) { return pnt(-p.y, p.x); }
int intersect_circles(pnt c, double r, pnt cc, double rr, pnt p[]) {
  double d = dist(c - cc);
  if (r + rr < d || r + d < rr || rr + d < r) return 0;
  double x = (r * r - rr * rr + d * d) / (d * 2);
  pnt cp = (c * (d - x) + cc * x) / d;
  if (r + rr == d || r + d == rr || rr + d == r) {
    p[0] = cp;
    return 1;
  }
  double h = sqrt(r * r - x * x);
  pnt dv = rot(cc - c) * h / d;
  p[0] = cp - dv;
  p[1] = cp + dv;
  return 2;
}
double a[4000001], b[4000001], sto[4000001];
int id[4000001], bit[4000001];
bool cmp(int x, int y) {
  if (b[x] - a[x] != b[y] - a[y]) return b[x] - a[x] < b[y] - a[y];
  return 0;
}
bool common(double a, double b, double c, double d) {
  if (a <= c && c <= b) return 1;
  if (a <= d && d <= b) return 1;
  if (c <= a && a <= d) return 1;
  if (c <= b && b <= d) return 1;
  a += 2 * pi, b += 2 * pi;
  if (a <= c && c <= b) return 1;
  if (a <= d && d <= b) return 1;
  if (c <= a && a <= d) return 1;
  if (c <= b && b <= d) return 1;
  a -= 2 * pi, b -= 2 * pi;
  c += 2 * pi, d += 2 * pi;
  if (a <= c && c <= b) return 1;
  if (a <= d && d <= b) return 1;
  if (c <= a && a <= d) return 1;
  if (c <= b && b <= d) return 1;
  return 0;
}
void add(int x, int val) {
  while (x < 4000001) {
    bit[x] += val;
    x += x & -x;
  }
}
int calc(int x) {
  int sum = 0;
  while (x) {
    sum += bit[x];
    x -= x & -x;
  }
  return sum;
}
bool cmpequal(double a, double b) { return fabs(a - b) < ep; }
int main() {
  int n, A;
  scanf("%d %d", &n, &A);
  for (int i = 0; i < n; i++) p[i].input();
  pnt P = pnt(A, 0), Q = pnt(-A, 0);
  double ans = dist(P - Q);
  double st = 0, en = ans;
  for (int step = 0; step < 50; step++) {
    double mid = (en + st) / 2;
    int gas = 0, num = 0;
    for (int i = 0; i < n; i++) {
      double r = dist(p[i] - Q);
      pnt res[10];
      int x = intersect_circles(P, mid, p[i], r, res);
      if (x != 2) continue;
      a[gas] = atan2(res[0].y - P.y, res[0].x - P.x);
      b[gas] = atan2(res[1].y - P.y, res[1].x - P.x);
      if (a[gas] < 0) a[gas] += 2 * pi;
      if (b[gas] < 0) b[gas] += 2 * pi;
      if (a[gas] > b[gas]) swap(a[gas], b[gas]);
      sto[num++] = a[gas], sto[num++] = b[gas];
      gas++;
    }
    for (int i = 0; i < gas; i++) id[i] = i;
    sort(id, id + gas, cmp);
    sort(sto, sto + num);
    for (int i = 0; i < 4000001; i++) bit[i] = 0;
    num = unique(sto, sto + num, cmpequal) - sto;
    int ok = 0;
    for (int i = 0; i < gas; i++) {
      int x = lower_bound(sto, sto + num, a[id[i]] - ep) - sto + 1;
      int y = lower_bound(sto, sto + num, b[id[i]] - ep) - sto + 1;
      x++;
      y++;
      if (calc(y) > 0) ok = 1;
      if (calc(x) > 0) ok = 1;
      add(y + 1, -1);
      add(x, 1);
    }
    if (ok)
      en = mid;
    else
      st = mid;
  }
  printf("%.10lf\n", en);
}
