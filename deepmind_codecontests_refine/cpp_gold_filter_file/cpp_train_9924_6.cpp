#include <bits/stdc++.h>
using namespace std;
const int mn = 101000;
struct node {
  double x, y;
} p[mn];
int le[mn], ri[mn], q[mn * 3];
int n;
double R;
double sqr(double x) { return x * x; }
double dis(node a, node b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }
double area(node a, node b, node c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
bool cmp(node a, node b) {
  double t = area(p[1], a, b);
  if (t == 0.0) return dis(p[1], a) < dis(p[1], b);
  return t > 0;
}
void convex_hull() {
  int i, top = 0;
  for (i = 1; i <= n; ++i)
    if (p[i].x < p[1].x || (p[i].x == p[1].x && p[i].y < p[1].y))
      swap(p[1], p[i]);
  sort(p + 2, p + 1 + n, cmp);
  for (i = 1; i <= n; ++i) {
    while (top >= 2 && area(p[top - 1], p[top], p[i]) <= 0) --top;
    p[++top] = p[i];
  }
  n = top;
}
node cross(node a, node b, node c, node d) {
  double s1 = area(a, c, b), s2 = area(a, b, d);
  node k;
  k.x = (c.x * s2 + d.x * s1) / (s1 + s2);
  k.y = (c.y * s2 + d.y * s1) / (s1 + s2);
  return k;
}
double radius(node a, node b, node c) {
  node p1, p2, p3, p4, k;
  p1.x = (a.x + b.x) / 2, p1.y = (a.y + b.y) / 2;
  p2.x = p1.x - (b.y - a.y), p2.y = p1.y + (b.x - a.x);
  p3.x = (b.x + c.x) * 0.5, p3.y = (b.y + c.y) / 2;
  p4.x = p3.x - (c.y - b.y), p4.y = p3.y + (c.x - b.x);
  k = cross(p1, p2, p3, p4);
  return dis(a, k);
}
int calc(node a, node b, node c) {
  double s1 = dis(a, b), s2 = dis(a, c), s3 = dis(b, c);
  if (s1 + s2 < s3) return 1;
  if (s1 + s3 < s2) return 2;
  if (s2 + s3 < s1) return 3;
}
void solve() {
  int i, x, l = 1, r = n, id;
  for (i = 1; i <= n; ++i) le[i] = i - 1, ri[i] = i + 1;
  le[1] = n, ri[n] = 1;
  for (i = 1; i <= n; ++i) q[i] = i;
  while (l <= r) {
    x = q[l++];
    if (le[x] != ri[x] && radius(p[le[x]], p[x], p[ri[x]]) > sqr(R)) {
      id = calc(p[le[x]], p[x], p[ri[x]]);
      if (id == 1) x = le[x];
      if (id == 3) x = ri[x];
      ri[le[x]] = ri[x], le[ri[x]] = le[x];
      q[++r] = le[x], q[++r] = ri[x];
      le[x] = ri[x] = 0;
    }
  }
}
void count() {
  double ans = 0, t, co;
  node k;
  int i;
  k.x = k.y = 0;
  for (i = 1; i <= n; ++i)
    if (ri[i] > 0) {
      ans += area(k, p[i], p[ri[i]]) * 0.5;
      t = sqrt(dis(p[i], p[ri[i]]));
      co = 1 - sqr(t) / (2 * sqr(R));
      co = acos(co);
      ans += (co * sqr(R) - t * sqrt(sqr(R) - sqr(t) * 0.25)) * 0.5;
    }
  printf("%.8lf\n", ans);
}
int main() {
  scanf("%d%lf", &n, &R);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  int i;
  for (i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  convex_hull();
  solve();
  count();
  return 0;
}
