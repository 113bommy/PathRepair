#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline long long read() {
  bool sign = 0;
  char ch = getchar();
  long long x = 0;
  for (; blank(ch); ch = getchar())
    ;
  if (IOerror) return 0;
  if (ch == '-') sign = 1, ch = getchar();
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return x;
}
};  // namespace fastIO
using namespace fastIO;
struct node {
  long double x;
  long long v, f;
} e[1000010];
long long x[1000010], y[1000010], n, m, now = 0;
bool cmp(node e1, node e2) { return e1.x < e2.x; }
bool check(long long id, long double r) {
  now = 0;
  if (id <= n)
    e[++now] = {0, 1, 1}, e[++now] = {2 * acos(-1.0), -1, 1};
  else {
    for (long long i = 1; i <= n; i++) {
      if (sqrt((y[i] - y[id]) * (y[i] - y[id]) +
               (x[i] - x[id]) * (x[i] - x[id])) > 2 * r - 1e-8)
        continue;
      long double pos = atan2(y[i] - y[id], x[i] - x[id]),
                  len = acos(sqrt((y[i] - y[id]) * (y[i] - y[id]) +
                                  (x[i] - x[id]) * (x[i] - x[id])) /
                             r / 2);
      long double l = pos - len, r = pos + len;
      while (l < 0) l += 2 * acos(-1.0);
      while (l > 2 * acos(-1.0)) l -= 2 * acos(-1.0);
      while (r < 0) r += 2 * acos(-1.0);
      while (r > 2 * acos(-1.0)) r -= 2 * acos(-1.0);
      if (l < r)
        e[++now] = {l, 1, 1}, e[++now] = {r, -1, 1};
      else
        e[++now] = {l, 1, 1}, e[++now] = {2 * acos(-1.0), -1, 1},
        e[++now] = {0, 1, 1}, e[++now] = {r, -1, 1};
    }
  }
  for (long long i = n + 1; i <= n + m; i++) {
    if (i != id) {
      if (sqrt((y[i] - y[id]) * (y[i] - y[id]) +
               (x[i] - x[id]) * (x[i] - x[id])) > 2 * r - 1e-8)
        continue;
      long double pos = atan2(y[i] - y[id], x[i] - x[id]),
                  len = acos(sqrt((y[i] - y[id]) * (y[i] - y[id]) +
                                  (x[i] - x[id]) * (x[i] - x[id])) /
                             r / 2);
      long double l = pos - len, r = pos + len;
      while (l < 0) l += 2 * acos(-1.0);
      while (l > 2 * acos(-1.0)) l -= 2 * acos(-1.0);
      while (r < 0) r += 2 * acos(-1.0);
      while (r > 2 * acos(-1.0)) r -= 2 * acos(-1.0);
      if (l < r)
        e[++now] = {l, 1, 2}, e[++now] = {r, -1, 2};
      else
        e[++now] = {l, 1, 2}, e[++now] = {2 * acos(-1.0), -1, 2},
        e[++now] = {0, 1, 2}, e[++now] = {r, -1, 2};
    }
  }
  sort(e + 1, e + 1 + now, cmp);
  long long cnt1 = 0, cnt2 = 0;
  for (long long i = 1; i <= now; i++) {
    if (e[i].f == 1)
      cnt1 += e[i].v;
    else
      cnt2 += e[i].v;
    if (cnt2 == 0 && cnt1 > 0 && (i == now || e[i + 1].x - e[i].x > 1e-12))
      return 1;
  }
  return 0;
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (long long i = 1; i <= m; i++) x[i + n] = read(), y[i + n] = read();
  long double ans = 0;
  long double l = 0, r = 1e9, mid;
  for (long long i = 1; i <= n + m; i++) {
    if (!check(i, l)) continue;
    r = 1e9;
    while (r - l > 1e-6) {
      mid = (l + r) / 2;
      if (check(i, mid))
        l = mid;
      else
        r = mid;
    }
  }
  if (l > 2e8)
    puts("-1");
  else
    printf("%.10Lf", l);
  return 0;
}
