#include <bits/stdc++.h>
using namespace std;
int n, m;
double p, q;
struct line {
  double k, b;
} l[100020], t[100020];
bool cmp(const line &a, const line &b) {
  if (a.k != b.k) return a.k > b.k;
  return a.b < b.b;
}
double xx(const line &a, const line &b) { return (a.b - b.b) / (b.k - a.k); }
double yy(const line &a, const line &b) { return a.k * xx(a, b) + a.b; }
int main() {
  scanf("%d%lf%lf", &n, &p, &q);
  double ansx = 1e100, ansy = 1e100;
  for (int i = 1; i <= n; ++i) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    ansx = min(ansx, p / a);
    ansy = min(ansy, q / b);
    l[i].k = -a / b;
    l[i].b = 1. / b;
  }
  double ans = max(ansx, ansy);
  sort(l + 1, l + n + 1, cmp);
  m = 0;
  for (int i = 1; i <= n; ++i) {
    if (i >= 2 && l[i].k == l[i - 1].k) continue;
    while (m >= 2 && xx(t[m - 1], t[m]) >= xx(t[m], l[i])) --m;
    t[++m] = l[i];
  }
  for (int i = 1; i < n; ++i)
    if (xx(t[i], t[i + 1]) >= 0 && yy(t[i], t[i + 1]) >= 0)
      ans = max(ans, p * xx(t[i], t[i + 1]) + q * yy(t[i], t[i + 1]));
  printf("%.10lf\n", ans);
}
