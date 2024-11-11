#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y, z;
  point() {}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
  void input() { scanf("%lf %lf %lf", &x, &y, &z); }
  void output() { printf("%.10f %.10f %.10f\n", x, y, z); }
} p[100010], C, ans;
int N;
double sum, vp, vs;
const double eps = 1e-9;
int sgn(double x) { return x < -eps ? -1 : x > eps; }
double operator&(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
point operator-(const point &a, const point &b) {
  return point(a.x - b.x, a.y - b.y, a.z - b.z);
}
point operator+(const point &a, const point &b) {
  return point(a.x + b.x, a.y + b.y, a.z + b.z);
}
point operator*(double a, const point &b) {
  return point(a * b.x, a * b.y, a * b.z);
}
double vlen(const point &a) { return sqrt(a & a); }
double dist(const point &a, const point &b) { return vlen(a - b); }
bool check(point s, point t) {
  bool flag = 0;
  if (sgn(dist(t, C) / vp - sum - dist(s, t) / vs) <= 0) flag = 1;
  if (!flag) return 0;
  point v = vs / vlen(t - s) * (t - s);
  double low = 0.0, high = vlen(t - s) / vs, mid;
  for (int tim = 0; tim < 300; tim++) {
    mid = (low + high) / 2.0;
    point a = s + mid * v;
    if (sgn(dist(a, C) / vp - sum - dist(s, a) / vs) <= 0)
      high = mid;
    else
      low = mid;
  }
  sum += high;
  ans = s + high * v;
  return 1;
}
int main() {
  while (cin >> N) {
    sum = 0.0;
    for (int i = 0; i <= N; i++) {
      p[i].input();
    }
    cin >> vp >> vs;
    C.input();
    bool flag = 0;
    for (int i = 0; i < N; i++) {
      if (check(p[i], p[i + 1])) {
        flag = 1;
        break;
      }
      sum += dist(p[i], p[i + 1]) / vs;
    }
    if (!flag)
      puts("NO");
    else {
      puts("YES");
      printf("%.8f\n", sum);
      ans.output();
    }
  }
  return 0;
}
