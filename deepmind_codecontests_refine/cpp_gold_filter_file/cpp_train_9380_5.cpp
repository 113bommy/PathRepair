#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1);
int sign(double k) {
  if (k > eps)
    return 1;
  else if (k < -eps)
    return -1;
  return 0;
}
int cmp(double k1, double k2) { return sign(k1 - k2); }
int inmid(double k1, double k2, double k3) {
  return sign(k1 - k3) * sign(k2 - k3) <= 0;
}
struct point {
  double x, y;
  point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
  point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
  point operator*(double k1) const { return (point){x * k1, y * k1}; }
  point operator/(double k1) const { return (point){x / k1, y / k1}; }
  int operator==(const point &k1) const {
    return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0;
  }
  double abs() { return sqrt(x * x + y * y); }
  double abs2() { return x * x + y * y; }
  double dis(point k1) { return ((*this) - k1).abs(); }
} a[100005], b[100005];
int inmid(point k1, point k2, point k3) {
  return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
}
double cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
double dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
double rad(point k1, point k2) { return atan2(cross(k1, k2), dot(k1, k2)); }
point proj(point k1, point k2, point q) {
  point k = k2 - k1;
  return k1 + k * (dot(q - k1, k) / k.abs2());
}
int intersect(double l1, double r1, double l2, double r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);
  return cmp(r1, l2) != -1 && cmp(r2, l1) != -1;
}
int checkSS(point k1, point k2, point k3, point k4) {
  return intersect(k1.x, k2.x, k3.x, k4.x) &&
         intersect(k1.y, k2.y, k3.y, k4.y) &&
         sign(cross(k3 - k1, k4 - k1)) * sign(cross(k3 - k2, k4 - k2)) <= 0 &&
         sign(cross(k1 - k3, k2 - k3)) * sign(cross(k1 - k4, k2 - k4)) <= 0;
}
double disSP(point k1, point k2, point q) {
  if (k1 == k2) return q.dis(k1);
  point k3 = proj(k1, k2, q);
  if (inmid(k1, k2, k3))
    return q.dis(k3);
  else
    return min(q.dis(k1), q.dis(k2));
}
double disSS(point k1, point k2, point k3, point k4) {
  if (checkSS(k1, k2, k3, k4))
    return 0;
  else
    return min(min(disSP(k1, k2, k3), disSP(k1, k2, k4)),
               min(disSP(k3, k4, k1), disSP(k3, k4, k2)));
}
double d[100005];
int n, d1, d2;
double slove(int x) {
  point px = a[x + 1] - a[x], py = b[x + 1] - b[x];
  double l = 0, r = 1;
  while (l + 0.000001 < r) {
    double mid = (l + r) / 2, lm = (l + mid) / 2, rm = (r + mid) / 2;
    double dlm = (a[x] + px * lm).dis(b[x] + py * lm);
    double rlm = (a[x] + px * rm).dis(b[x] + py * rm);
    if (dlm <= rlm) {
      r = rm;
    } else {
      l = lm;
    }
  }
  return (a[x] + px * l).dis(b[x] + py * l);
}
int main() {
  scanf("%d%d%d", &n, &d1, &d2);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y),
        d[i] = a[i].dis(b[i]);
  int cnt = 0;
  bool f = cmp(d[1], d1) <= 0 ? 1 : 0;
  if (f) cnt++;
  for (int i = 1; i < n; i++) {
    double mn = slove(i);
    if (!f) {
      if (cmp(mn, d1) <= 0) {
        cnt++;
        if (cmp(d[i + 1], d2) <= 0) f = 1;
      }
    } else {
      if (cmp(d[i + 1], d2) == 1) f = 0;
    }
  }
  printf("%d\n", cnt);
}
