#include <bits/stdc++.h>
using namespace std;
double x[100010], y[100010], r[100010], L;
struct node {
  double l, r;
} a[100010];
struct P {
  double x, y;
} A, B, M, s, O, p[100010];
int n;
inline double dis(P a, P b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline P operator-(P a, P b) { return (P){a.x - b.x, a.y - b.y}; }
inline double operator*(P a, P b) { return a.x * b.y - a.y * b.x; }
inline bool cmp(node a, node b) { return a.l < b.l; }
int main() {
  cin >> A.x >> A.y >> B.x >> B.y;
  if (A.x > B.x) swap(A, B);
  L = dis(A, B);
  M = (P){(A.x + B.x) / 2, (A.y + B.y) / 2};
  s = (P){1.0 * (A.x - B.x) / L, 1.0 * (A.y - B.y) / L};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf%lf", &p[i].x, &p[i].y, &r[i]);
    if ((p[i] - A) * (B - A) <= 0) {
      double l = -1e12, r = 1e12;
      while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        O = (P){M.x + s.y * mid, M.y - s.x * mid};
        if (dis(O, p[i]) >= ::r[i] + dis(O, A))
          l = mid;
        else
          r = mid;
      }
      a[i].l = r;
      l = -1e12;
      r = 1e12;
      while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        O = (P){M.x + s.y * mid, M.y - s.x * mid};
        if (dis(O, p[i]) <= dis(O, A) - ::r[i])
          r = mid;
        else
          l = mid;
      }
      a[i].r = l;
    } else {
      double l = -1e12, r = 1e12;
      while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        O = (P){M.x + s.y * mid, M.y - s.x * mid};
        if (dis(O, p[i]) >= ::r[i] + dis(O, A))
          r = mid;
        else
          l = mid;
      }
      a[i].r = r;
      l = -1e12;
      r = 1e12;
      while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        O = (P){M.x + s.y * mid, M.y - s.x * mid};
        if (dis(O, p[i]) <= dis(O, A) - ::r[i])
          l = mid;
        else
          r = mid;
      }
      a[i].l = l;
    }
  }
  sort(a + 1, a + n + 1, cmp);
  double last = -1e12, ans = 1e12;
  for (int i = 1; i <= n; i++) {
    if (last <= 0 && a[i].l >= 0) {
      printf("%0.10lf\n", L / 2);
      return 0;
    }
    if (a[i].r <= last) continue;
    if (a[i].l > last + 1e-7) ans = min(ans, min(fabs(last), fabs(a[i].l)));
    last = max(last, a[i].r);
  }
  ans = min(ans, fabs(last));
  printf("%0.10lf\n", sqrt(ans * ans + L * L / 4));
  return 0;
}
