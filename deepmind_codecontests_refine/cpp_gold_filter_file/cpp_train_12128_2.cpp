#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
struct Point {
  double x, y;
} p[N << 1], p0;
int n;
const double pi = 3.14159265358;
double cross(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double dot(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}
long long solve() {
  long long res = 0;
  int j = 1, i = 1;
  for (; i <= n; ++i) {
    if (j < i) j = i;
    while (j + 1 < i + n && cross(p[i], p[j + 1], p0) > 1e-6) ++j;
    long long tem = j - i;
    res += tem * (tem - 1) / 2;
  }
  return res;
}
int sgn(double x) {
  if (fabs(x) < 1e-6) return 0;
  if (x < 0) return -1;
  return 1;
}
double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double angle(Point a, Point b, Point c) {
  double tem = dot(a, b, c);
  double deta = 1.0 * tem / (dis(a, b) * dis(a, c));
  return acos(deta);
}
bool judge() {
  double res = 0;
  for (int i = 1; i <= n; ++i) {
    res += angle(p0, p[i], p[i + 1]);
  }
  return sgn(res - 2 * pi);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
  reverse(p + 1, p + 1 + n);
  for (int i = 1; i <= n; ++i) p[i + n] = p[i];
  long long all = 1ll * n * (n - 1) * (n - 2) / 6;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf %lf", &p0.x, &p0.y);
    if (judge()) {
      puts("0");
      continue;
    }
    long long ans = all - solve();
    printf("%lld\n", ans);
  }
  return 0;
}
