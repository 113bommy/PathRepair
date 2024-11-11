#include <bits/stdc++.h>
using namespace std;
namespace jyy {
const int mod = 998244353, N = 200010;
const double eps = 1e-10;
inline long long read() {
  static long long x = 0, f = 1;
  x = 0, f = 1;
  static char ch = getchar();
  while (ch < '0' || ch > '9') {
    (ch == '-') ? f *= -1 : f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + int(ch - 48), ch = getchar();
  return x * f;
}
inline void fw(int x) {
  if (x < 0) putchar('-'), x = -x;
  x >= 10 ? fw(x / 10), 1 : 0;
  putchar(char(x % 10 + 48));
}
int qmo(int x) { return x + ((x >> 31) & mod); }
int ksm(int x, int y) {
  int tmp = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) tmp = 1ll * tmp * x % mod;
  return tmp;
}
int inv(int x) { return ksm(x, mod - 2); }
int tot, head[N], fa[N];
struct edge {
  int to, next;
} dat[N * 2];
void add_edge(int x, int y) { dat[++tot] = (edge){y, head[x]}, head[x] = tot; }
int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
int merge(int x, int y) {
  return find(x) != find(y) ? fa[find(x)] = find(y), 0 : 1;
}
int low(int x) { return x & -x; }
int ifac[N], fac[N];
void init(int x) {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= x; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[x] = inv(fac[x]);
  for (int i = x - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int C(int x, int y) {
  return (x < y || y < 0 || x < 0)
             ? 0
             : 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
}  // namespace jyy
using namespace jyy;
int n, cnt;
long long k, tr[N * 2];
double val[N * 2], dis[N], L[N], R[N], pi = 3.14159265358979;
struct node {
  double x, y;
  node(double X = 0, double Y = 0) { x = X, y = Y; }
} a[N], b[N];
bool operator<(node A, node B) {
  if (A.y != B.y) return A.y < B.y;
  return A.x < B.x;
}
long long query(int x) {
  long long res = 0;
  for (int i = x; i; i -= low(i)) res += tr[i];
  return res;
}
void add(int x, long long V) {
  for (int i = x; i <= cnt; i += low(i)) tr[i] += V;
}
long long check(double d) {
  cnt = 0;
  int m = 0;
  for (int i = 1; i <= n; i++)
    if (dis[i] > d) {
      double other = acos(d / dis[i]), now = atan2(a[i].y, a[i].x),
             l = now - other, r = now + other;
      l += (l < 0) * 2.0 * pi, r += (r < 0) * 2.0 * pi;
      if (l > r) swap(l, r);
      L[++m] = l, R[m] = r, val[++cnt] = l, val[++cnt] = r;
    }
  sort(val + 1, val + 1 + cnt);
  cnt = unique(val + 1, val + 1 + cnt) - val - 1;
  for (int i = 1; i <= m; i++)
    L[i] = lower_bound(val + 1, val + 1 + cnt, L[i]) - val;
  for (int i = 1; i <= m; i++)
    R[i] = lower_bound(val + 1, val + 1 + cnt, R[i]) - val,
    b[i] = node(L[i], R[i]);
  sort(b + 1, b + 1 + m);
  long long ans = 0;
  for (int i = 1; i <= m; i++)
    ans += query(b[i].y) - query(b[i].x - 1), add(b[i].y, 1), add(b[i].x, -1);
  for (int i = 1; i <= cnt; i++) tr[i] = 0;
  return 1ll * n * (n - 1) / 2 - ans;
}
int main() {
  n = read(), k = read();
  for (int i = 1, x, y; i <= n; i++)
    x = read(), y = read(), a[i] = node(x, y), dis[i] = sqrt(x * x + y * y);
  double l = 0, r = (int)1e5;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid) >= k)
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", l);
}
