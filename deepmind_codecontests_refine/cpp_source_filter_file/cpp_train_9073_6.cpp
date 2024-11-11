#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const double PI = acos(-1);
struct Point {
  double x, y;
};
inline Point operator+(const Point &a, const Point &b) {
  return {a.x + b.x, a.y + b.y};
}
inline Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}
inline Point operator*(const Point &a, double b) { return {a.x * b, a.y * b}; }
inline Point operator/(const Point &a, double b) { return {a.x / b, a.y / b}; }
inline double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
inline double dis(const Point &a) { return sqrt(dot(a, a)); }
inline double angle(const Point &a, const Point &b) {
  return acos(dot(a, b) / dis(a) / dis(b));
}
inline double polar(const Point &a) { return atan2(a.y, a.x); }
inline double slope(const Point &a, const Point &b) {
  return (b.y - a.y) / (b.x - a.x);
}
int n, m, x[N], y[N], f[N][20];
Point a[N];
struct Seg {
  double l, r;
} s[N];
int lift(int pos, int tt) {
  for (int i = 19; i >= 0; --i)
    if (tt & (1 << i)) pos = f[pos][i];
  return pos;
}
bool check(double mid) {
  for (int i = 1; i <= n; i++) {
    double theta = polar(a[i]), delta = acos(mid / dis(a[i]));
    double l = theta - delta, r = theta + delta;
    if (l < 0) l += PI * 2, r += PI * 2;
    s[i] = {l, r};
    s[i + n] = {l + PI * 2, r + PI * 2};
  }
  int l = n * 2;
  sort(s + 1, s + l + 1, [](Seg a, Seg b) { return a.l < b.l; });
  int ptr = l;
  for (int i = l; i > 0; --i) {
    while (s[ptr].l > s[i].r) --ptr;
    f[i][0] = ptr + 1;
  }
  f[l + 1][0] = l + 1;
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= l + 1; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++)
    if (lift(i, m) >= i + n) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i], a[i] = {x[i] * 1.0, y[i] * 1.0};
  double l = 0, r = DBL_MAX;
  for (int i = 1; i <= n; i++) r = min(r, dis(a[i]));
  if (r < 1e-6) {
    cout << 0 << endl;
    return 0;
  }
  for (int _ = 1; _ <= 40; _++) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.8lf\n", l);
  return 0;
}
