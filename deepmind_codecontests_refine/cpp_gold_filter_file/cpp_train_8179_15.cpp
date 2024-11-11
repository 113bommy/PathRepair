#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const double eps = 1e-7;
int n, m, cnt, pan, dao;
double sum[N], C;
inline double sqr(double x) { return x * x; }
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
struct pigu {
  double x, y;
  friend pigu operator-(pigu x, pigu y) { return pigu{x.x - y.x, x.y - y.y}; }
  friend pigu operator*(pigu x, double y) { return pigu{x.x * y, x.y * y}; }
  friend pigu operator+(pigu x, pigu y) { return pigu{x.x + y.x, x.y + y.y}; }
  double len() { return sqrt(sqr(x) + sqr(y)); }
} a[N], kai, dir[N];
struct gouzi {
  double l, r;
} qj[N];
inline bool cmp(gouzi x, gouzi y) { return x.l < y.l; }
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
inline double div(double x) { return floor(x / C); }
inline double dmod(double x) { return x - C * floor(x / C); }
inline void insert(double l, double r) {
  if (r < l) return;
  if (dcmp(div(r) - div(l)) == 1) {
    if (dcmp(div(r) - div(l) - 1) == 1 || dcmp(dmod(r) - dmod(l)) == 1)
      pan = 1;
    else {
      qj[++cnt] = {dmod(l), C};
      qj[++cnt] = {0, dmod(r)};
    }
  } else
    qj[++cnt] = {dmod(l), dmod(r)};
}
inline bool check(double x) {
  double t = 0;
  cnt = pan = 0;
  pigu st1 = a[1], st2 = kai;
  for (int d1 = 2, d2 = dao; d1 <= n + 1 && d2 <= dao + n;) {
    double lim1 = sum[d1], lim2 = sum[d2] - C;
    pigu hu1 = st1 - st2, hu2 = dir[d1 - 1] - dir[d2 - 1];
    double A = sqr(hu2.x) + sqr(hu2.y),
           B = 2.0 * hu1.x * hu2.x + 2.0 * hu1.y * hu2.y,
           C = sqr(hu1.x) + sqr(hu1.y) - sqr(x);
    double del = B * B - 4.0 * A * C;
    if (dcmp(del) == -1)
      insert(t, min(lim1, lim2));
    else {
      del = sqrt(del);
      if (dcmp(A) != 0) {
        double ga1 = (-B - del) / (2.0 * A), ga2 = (-B + del) / (2.0 * A);
        if (ga1 > 0) insert(t, min(min(lim1, lim2), t + ga1));
        if (ga2 + t < min(lim1, lim2)) insert(max(ga2 + t, t), min(lim1, lim2));
      } else {
        if (dcmp(B) == 0) {
          if (dcmp(C) == 1) insert(t, min(lim1, lim2));
        } else {
          if (dcmp(B) == 1) {
            double ga = -C / B;
            insert(max(t, t + ga), min(lim1, lim2));
          } else {
            double ga = -C / B;
            insert(t, min(min(lim1, lim2), t + ga));
          }
        }
      }
    }
    double hu = t;
    t = min(lim1, lim2);
    if (dcmp(lim1 - t) != 1)
      st1 = a[d1++];
    else
      st1 = st1 + dir[d1 - 1] * (t - hu);
    if (dcmp(lim2 - t) != 1)
      st2 = a[d2++];
    else
      st2 = st2 + dir[d2 - 1] * (t - hu);
  }
  if (pan) return 0;
  double ma = 0;
  sort(qj + 1, qj + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    if (dcmp(qj[i].l - ma - eps) == 1) return 1;
    ma = max(ma, qj[i].r);
  }
  if (dcmp(C - ma) == 1) return 1;
  return 0;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i + n].x = a[i].x = read(), a[i + n].y = a[i].y = read();
  C = (a[1] - a[n]).len();
  for (int i = 1; i <= n - 1; i++) C += (a[i + 1] - a[i]).len();
  for (int i = 1; i <= n; i++) {
    sum[i + 1] = sum[i] + (a[i + 1] - a[i]).len();
    dir[i] = (a[i + 1] - a[i]) * (1.0 / (a[i + 1] - a[i]).len());
  }
  for (int i = 1; i <= n; i++)
    sum[i + n + 1] = sum[i + 1] + C, dir[i + n] = dir[i];
  C /= m;
  int now = 1;
  double hu = C;
  while (dcmp(hu - sum[now + 1]) >= 0) now++;
  kai = a[now] + dir[now] * (hu - sum[now]);
  dao = now + 1;
  double l = 0, r = 10000;
  while (r - l > eps) {
    double mid = (l + r) * 0.5;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.6lf", l);
  return 0;
}
