#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
const double eps = 1e-8, pi = acos(-1.);
struct node {
  double x, y;
  node() {}
  node(double _x, double _y) : x(_x), y(_y) {}
  node operator+(const node &A) { return node(x + A.x, y + A.y); }
  node operator-(const node &A) { return node(x - A.x, y - A.y); }
  node operator*(const double &A) { return node(x * A, y * A); }
  node operator/(const double &A) { return node(x / A, y / A); }
  double operator*(const node &A) { return x * A.x + y * A.y; }
  double operator/(const node &A) {
    return fabs(A.x) < eps ? y / A.y : x / A.x;
  }
  double operator%(const node &A) { return x * A.y - y * A.x; }
  bool operator<(const node &A) const {
    return fabs(x - A.x) < eps ? y < A.y : x < A.x;
  }
  double angle() { return atan2(y, x); }
  double norm() { return x * x + y * y; }
  double len() { return sqrt(x * x + y * y); }
  void prt() { printf("%lf %lf\n", x, y); }
} O;
int n, m, d, sum, ans;
pair<double, int> a[3000005];
void add(double L, double R) {
  if (R > pi)
    add(L, pi), add(-pi, R - 2 * pi);
  else if (L < -pi)
    add(-pi, R), add(L + 2 * pi, pi);
  else
    a[m++] = make_pair(L, -1), a[m++] = make_pair(R, 1);
}
void cross(node &A, double r, double R) {
  double L = A.len(), a = A.angle(),
         theta = acos((A.norm() + R * R - r * r) / 2 / R / L);
  add(a - theta - eps, a + theta + eps);
}
int main() {
  n = read(), d = read();
  for (int i = 0; i < n; ++i) {
    int x = read(), y = read(), r = read();
    node A = node(x, y);
    int Low = int(ceil((A.len() - r) / d)), Up = int(floor((A.len() + r) / d));
    for (int i = Low; i <= Up; ++i) cross(A, r, d * i);
  }
  sort(a, a + m);
  for (int i = 0; i < m; ++i) ans = max(ans, sum -= a[i].second);
  printf("%d\n", ans);
  return 0;
}
