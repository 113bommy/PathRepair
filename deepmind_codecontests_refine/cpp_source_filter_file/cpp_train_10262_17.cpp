#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-' ? -1 : f, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int N = 1005;
const int V = N << 1;
const long double EPS = 1e-4;
const long double INF = 1e+9;
const long double pi = acosl(-1);
const int ERROR = -100000;
inline bool equ(long double x, long double y) { return fabs(x - y) <= EPS; }
inline int sgn(long double x) { return equ(x, 0.) ? 0 : (x < 0 ? -1 : 1); }
struct P {
  long double x, y;
  inline P(long double x_ = 0., long double y_ = 0.) { x = x_, y = y_; }
  inline P operator+(P const p) const { return P(x + p.x, y + p.y); }
  inline P operator-(P const p) const { return P(x - p.x, y - p.y); }
  inline P operator*(long double const k) const { return P(x * k, y * k); }
  inline long double operator*(P const p) const { return x * p.x + y * p.y; }
  inline long double operator^(P const p) const { return x * p.y - y * p.x; }
  inline long double mod2() const { return (*this) * (*this); }
  inline long double mod() const { return sqrt(fabs(mod2())); }
  inline long double arg() { return atan2(y, x); }
} pts[N];
int n, m;
long double ans;
pair<long double, int> evt[V << 1];
long double dist[N][N];
inline bool cmp(pair<long double, int> p, pair<long double, int> q) {
  return p.first < q.first;
}
inline void adjust(long double &x) {
  x = x > pi ? x - pi * 2 : x < -pi ? x + pi * 2 : x;
}
inline bool judge(int id, long double r) {
  int cur = id <= n, cnt = 0, ret = 0;
  for (int i = 1; i <= n + m; ++i)
    if (i != id) {
      long double d = dist[i][id];
      if (sgn(d - 2. * r) > 0) continue;
      long double alpha = acosl(d / (2. * r)) - 1e-30 * (i > n),
                  mid = (pts[i] - pts[id]).arg();
      long double st = mid - alpha, en = mid + alpha;
      adjust(st), adjust(en);
      int cst = i <= n ? 1 : ERROR;
      cur += (sgn(en - st) < 0) * cst, evt[++cnt] = make_pair(st, cst),
                                       evt[++cnt] = make_pair(en, -cst);
    }
  ret = cur, sort(evt + 1, evt + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; ++i) ret = max(ret, cur += evt[i].second);
  return ret >= 1;
}
inline void binary_search(int id) {
  long double l = ans, r = ans + 1.;
  for (; judge(id, r) && r <= INF; r *= 2)
    ;
  for (long double mid; sgn(r - l) >= 0;) {
    mid = (l + r) * .5;
    if (judge(id, mid))
      l = (ans = mid) + EPS;
    else
      r = mid - EPS;
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1, x, y; i <= n + m; ++i)
    x = read(), y = read(), pts[i] = P(x, y);
  random_shuffle(pts + 1, pts + 1 + n),
      random_shuffle(pts + 1 + n, pts + 1 + n + m);
  for (int i = 1; i <= n + m; ++i)
    for (int j = 1; j <= n + m; ++j) dist[i][j] = (pts[i] - pts[j]).mod();
  ans = 0.;
  for (int i = 1; i <= n; ++i) {
    if (!judge(i, ans)) continue;
    binary_search(i);
  }
  for (int i = n + 1; i <= n + m; ++i) {
    if (!judge(i, ans)) continue;
    binary_search(i);
  }
  if (ans < INF * .5)
    printf("%.10lf\n", (double)ans);
  else
    printf("-1\n");
  return 0;
}
