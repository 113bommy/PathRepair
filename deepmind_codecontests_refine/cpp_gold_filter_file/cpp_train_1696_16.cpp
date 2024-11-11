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
const int N = 2e5 + 10;
int n, x[N], y[N];
long long k;
double dis[N];
struct BIT {
  int n, c[N];
  inline void init(int _n) {
    n = _n;
    for (register int i = (1); i <= (n); i++) c[i] = 0;
  }
  inline void Add(int x, int y) {
    for (; x <= n; x += x & -x) c[x] += y;
  }
  inline int Query(int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += c[x];
    return ret;
  }
} t;
const double pi = acos(-1), eps = 1e-8;
int cnt, tot;
double p[N];
pair<double, double> b[N];
pair<int, int> c[N];
inline bool check(double d) {
  tot = cnt = 0;
  for (register int i = (1); i <= (n); i++) {
    if (dis[i] <= d) continue;
    double ang = atan2(y[i], x[i]), del = acos(d / dis[i]);
    double l = ang - del, r = ang + del;
    if (l < -pi) l += 2 * pi;
    if (r > pi) r -= 2 * pi;
    if (l > r) swap(l, r);
    b[++tot] = make_pair(l, r);
    p[++cnt] = l, p[++cnt] = r;
  }
  sort(p + 1, p + 1 + cnt), cnt = unique(p + 1, p + 1 + cnt) - p - 1;
  for (register int i = (1); i <= (tot); i++) {
    c[i].first = lower_bound(p + 1, p + 1 + cnt, b[i].first) - p;
    c[i].second = lower_bound(p + 1, p + 1 + cnt, b[i].second) - p;
  }
  t.init(cnt);
  long long ret = 0;
  sort(c + 1, c + 1 + tot);
  for (register int i = (1); i <= (tot); i++)
    ret += t.Query(c[i].second) - t.Query(c[i].first - 1),
        t.Add(c[i].second, 1);
  return 1ll * n * (n - 1) / 2 - ret < k;
}
int main() {
  n = read(), k = read();
  for (register int i = (1); i <= (n); i++) {
    x[i] = read(), y[i] = read();
    dis[i] = sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
  }
  double l = 0, r = 2e4;
  for (register int i = (1); i <= (50); i++) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%0.12lf\n", l);
}
