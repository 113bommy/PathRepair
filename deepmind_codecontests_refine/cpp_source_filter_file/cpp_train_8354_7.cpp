#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 2010, M = N * N;
int n, xl[N], xr[N], y[N], cnt, cnt2;
pair<double, double> a[M], b[M];
const double inf = 1e15;
inline double calc(double x) {
  double l = inf, r = -inf;
  for (register int i = (1); i <= (n); i++)
    l = min(l, xl[i] + x * y[i]), r = max(r, xr[i] + x * y[i]);
  return r - l;
}
inline double solve() {
  int l = 1, r = cnt2;
  double ans = inf;
  while (l <= r) {
    int mid = l + r >> 1;
    double ret1 = calc(b[mid].first), ret2 = calc(b[mid].second);
    if (ret1 < ans) ans = ret1;
    if (ret2 < ans) ans = ret2;
    if (ret1 > ret2)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
int main() {
  n = read();
  for (register int i = (1); i <= (n); i++)
    xl[i] = read(), xr[i] = read(), y[i] = read();
  for (register int i = (1); i <= (n); i++)
    for (register int j = (1); j <= (n); j++) {
      if (y[i] <= y[j]) continue;
      double l = 1.0 * (xl[j] - xr[i]) / (y[i] - y[j]),
             r = 1.0 * (xr[j] - xl[i]) / (y[i] - y[j]);
      a[++cnt] = make_pair(l, r);
    }
  sort(a + 1, a + 1 + cnt);
  double l = a[1].first, r = a[1].second;
  for (register int i = (2); i <= (cnt); i++)
    if (a[i].first > r) {
      b[++cnt2] = make_pair(l, r);
      l = a[i].first, r = a[i].second;
    } else
      r = max(r, a[i].second);
  b[++cnt2] = make_pair(l, r);
  printf("%0.12lf\n", solve());
}
