#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1.0);
int sgn(double x) { return (x > eps) - (x < -eps); }
int cmp(double x, double y) { return sgn(x - y); }
struct P {
  double x, y;
  P() : x(0), y(0) {}
  P(double a, double b) : x(a), y(b) {}
  void in() { scanf("%lf%lf", &x, &y); }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  P operator*(const double &a) const { return P(x * a, y * a); }
  P operator/(const double &a) const { return P(x / a, y / a); }
  double norm() { return sqrt(x * x + y * y); }
};
P p[200000 + 5];
double myacos(double x) {
  if (x > 1.0) return acos(1.0);
  if (x < -1.0) return acos(-1.0);
  return acos(x);
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<pair<double, int>> A;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    P p;
    p.in();
    int r;
    scanf("%d", &r);
    double L = p.norm();
    double alpha = atan2(p.y, p.x);
    for (int i = ceil((L - r - eps) / d); i <= floor((L + r + eps) / d); i++) {
      double a = i * d;
      double theta = myacos((L * L + a * a - r * r) / (2.0 * L * a));
      double s1 = alpha - theta, s2 = alpha + theta;
      if (s1 <= -pi) s1 += pi;
      if (s2 > pi) s2 -= pi;
      A.push_back(make_pair(s1, -1));
      A.push_back(make_pair(s2, 1));
      if (s1 > s2) cnt++;
    }
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for (auto [s, b] : A) {
    cnt -= b;
    chmax(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
