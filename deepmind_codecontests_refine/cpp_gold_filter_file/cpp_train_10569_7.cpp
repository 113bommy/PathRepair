#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int N = 200010;
int n;
long long t, st[N];
struct P {
  int p, t;
  long long tmn, tmx, st;
  inline bool operator<(const P &yy) const { return p > yy.p; }
};
P a[N];
void gi(int &x) {
  x = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
}
bool cmp(const P &x, const P &y) { return 1ll * x.p * y.t > 1ll * y.p * x.t; }
bool check(double x) {
  double mn = 1e18, tmp;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    j = i;
    for (; j < n && a[j + 1].p == a[i].p; ++j)
      ;
    tmp = 0;
    for (int k = (i); k <= (j); k++)
      tmp = max(tmp, a[k].p * (1.0 - x * a[k].tmn / t));
    if (tmp > mn) return 0;
    for (int k = (i); k <= (j); k++)
      mn = min(mn, a[k].p * (1.0 - x * a[k].tmx / t));
  }
  return 1;
}
int main() {
  gi(n);
  for (int i = (1); i <= (n); i++) gi(a[i].p);
  for (int i = (1); i <= (n); i++) gi(a[i].t), t += a[i].t;
  sort(a + 1, a + n + 1, cmp);
  for (int i = (1); i <= (n); i++) st[i] = st[i - 1] + a[i].t;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    j = i;
    for (; j < n && 1ll * a[i].p * a[j + 1].t == 1ll * a[j + 1].p * a[i].t; ++j)
      ;
    for (int k = (i); k <= (j); k++)
      a[k].tmn = st[i - 1] + a[k].t, a[k].tmx = st[j];
  }
  sort(a + 1, a + n + 1);
  double l = 0, r = 1, mid;
  for (; r - l > eps;) {
    mid = (l + r) / 2.0;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%0.7lf\n", l);
  return 0;
}
