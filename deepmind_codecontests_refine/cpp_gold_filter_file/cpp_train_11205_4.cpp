#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-11;
struct Vector {
  double x, y;
};
void read(Vector& v) { scanf("%lf%lf", &v.x, &v.y); }
Vector operator+(const Vector& a, const Vector& b) {
  return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector& a, const Vector& b) {
  return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector& a, const Vector& b) {
  return (Vector){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
Vector operator*(double a, const Vector& b) {
  return (Vector){a * b.x, a * b.y};
}
double cross(const Vector& a, const Vector& b) { return a.x * b.y - a.y - b.x; }
double abs(const Vector& a) { return sqrt(((a.x) * (a.x)) + ((a.y) * (a.y))); }
double dis(const Vector& a, const Vector& b) { return abs(a - b); }
double t, t2;
Vector o, p, p2;
bool inCircle(const Vector& p, const Vector& o, double r) {
  return dis(o, p) - r <= eps;
}
void print(const Vector& p) { cout << "(" << p.x << "," << p.y << ")" << endl; }
void print(double d) { printf("%.8lf\n", d); }
int judge(const Vector& o, double r, const Vector& o2, double r2) {
  double d = dis(o, o2);
  if (d + r2 - r <= eps || d + r - r2 <= eps)
    return 0;
  else if (r2 + r - d >= -eps)
    return 1;
  else
    return 2;
}
void get(const Vector& o, double r, const Vector& o2, double r2, Vector& p,
         Vector& p2) {
  Vector v = o2 - o;
  double d = abs(v);
  v.x /= d;
  v.y /= d;
  double co = (((r) * (r)) + ((d) * (d)) - ((r2) * (r2))) / (2 * r * d);
  if (co - 1 > -eps) co = 1;
  double si = sqrt(1 - ((co) * (co)));
  p = o + (Vector){co * r, si * r} * v;
  p2 = o + (Vector){co * r, -si * r} * v;
}
bool check(double s) {
  double d = t2 - s, d2 = t - s;
  int r = judge(o, s, p, d), r2 = judge(o, s, p2, d2), r3 = judge(p, d, p2, d2);
  if (!r && !r2 && !r3)
    return true;
  else if (r == 2 || r2 == 2 || r3 == 2)
    return false;
  else if ((!r || !r2 || !r3) && (r || r2 || r3))
    return true;
  Vector i, j;
  if (r) {
    get(o, s, p, d, i, j);
    if (inCircle(i, p2, d2) || inCircle(j, p2, d2)) return true;
  }
  if (r2) {
    get(o, s, p2, d2, i, j);
    if (inCircle(i, p, d) || inCircle(j, p, d)) return true;
  }
  if (r3) {
    get(p, d, p2, d2, i, j);
    if (inCircle(i, o, s) || inCircle(j, o, s)) return true;
  }
  return false;
}
int main() {
  scanf("%lf%lf", &t, &t2);
  read(o);
  read(p);
  read(p2);
  p = p - o;
  p2 = p2 - o;
  o = o - o;
  double tmp;
  if ((tmp = abs(p2) + dis(p, p2)) <= abs(p) + t2) {
    printf("%.8lf", min(t + tmp, t2 + abs(p)));
    return 0;
  }
  t += abs(p2);
  t2 += abs(p);
  double left = 0, mid, right = min(t2, t);
  for (int i = 60; i; --i) {
    mid = (left + right) * 0.5;
    if (check(mid))
      left = mid;
    else
      right = mid;
  }
  printf("%.8lf", mid);
  return 0;
}
