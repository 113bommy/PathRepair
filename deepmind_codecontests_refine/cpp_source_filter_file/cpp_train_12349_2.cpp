#include <bits/stdc++.h>
template <typename tp>
inline tp abs(const tp& x) {
  return (x > 0) ? x : -x;
}
template <typename tp>
inline tp max(const tp& x, const tp& y) {
  return (x > y) ? x : y;
}
template <typename tp>
inline tp min(const tp& x, const tp& y) {
  return (x < y) ? x : y;
}
template <typename tp>
inline bool chkmax(tp& x, const tp& y) {
  return (x >= y) ? (false) : (x = y, true);
}
template <typename tp>
inline bool chkmin(tp& x, const tp& y) {
  return (x <= y) ? (false) : (x = y, true);
}
template <typename tp>
inline tp scanf(tp& in) {
  in = 0;
  char ch = getchar();
  tp f = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) in = in * 10 + ch - '0';
  return in *= f;
}
static const int maxn = 50 + 11;
static const int maxm = 6e3 + 11;
static const double inf = 1e15;
static const double eps = 1e-11;
int n;
int R;
int fi[maxn];
int si[maxn];
int pi[maxn];
double f[maxn][maxm];
inline int cmp(const double& x, const double& y) {
  return (abs(x - y) < eps) ? 0 : (x > y) ? 1 : -1;
}
inline double min(const double& x, const double& y) {
  return (cmp(x, y) == -1) ? x : y;
}
inline bool chkmin(double& x, const double& y) {
  return (cmp(x, y) != 1) ? (false) : (x = y, true);
}
inline bool chk(const double& ept) {
  for (int i = (n), iend = (1); i >= (iend); --i) {
    for (register int j = (R + 1), jend = (R + si[i]); j <= (jend); ++j)
      f[i + 1][j] = ept;
    for (register int j = (0), jend = (R); j <= (jend); ++j) {
      double t1 = (f[i + 1][j + fi[i]] + fi[i]) * pi[i];
      double t2 = (f[i + 1][j + si[i]] + si[i]) * (100 - pi[i]);
      f[i][j] = min((t1 + t2) / 100.0, ept);
    }
  }
  return cmp(f[1][0], ept) == -1;
}
int main() {
  scanf(n);
  scanf(R);
  for (register int i = (1), iend = (n); i <= (iend); ++i)
    scanf(fi[i]), scanf(si[i]), scanf(pi[i]);
  double l = 0.0, r = inf, ans;
  while ((r - l) > eps) {
    double mid = (l + r) / 2.0;
    if (chk(mid))
      ans = mid, r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", ans);
  return 0;
}
