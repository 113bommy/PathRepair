#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, size = 1 << 20, mod = 998244353, inf = 2e9;
const long long INF = 1e15;
template <class o>
void qr(o& x) {
  char c = getchar();
  x = 0;
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + '0');
}
template <class o>
void pr1(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar('\n');
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long power(long long a, long long b = mod - 2, long long p = mod) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % p;
    b /= 2;
    a = a * a % p;
  }
  return c;
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  long long d = exgcd(b % a, a, y, x);
  x -= b / a * y;
  return d;
}
long long INV(long long n, long long p = mod) {
  long long x, y;
  exgcd(n, p, x, y);
  return (x % p + p) % p;
}
template <class o>
void cmax(o& x, o y) {
  if (x < y) x = y;
}
template <class o>
void cmin(o& x, o y) {
  if (x > y) x = y;
}
template <typename t1, typename t2>
void ad(t1& x, t2 y) {
  x += y;
  if (x >= mod) x -= mod;
}
template <typename t1, typename t2>
void dl(t1& x, t2 y) {
  x -= y;
  if (x < 0) x += mod;
}
template <typename T>
struct BIT {
  T* c;
  int n;
  BIT(int _n) : n(_n) {
    c = new T[n];
    c--;
    for (int i = 1; i <= n; i++) c[i] = T(0);
  }
  void add(int x, T y) {
    for (; x <= n; x += x & -x) c[x] = c[x] + y;
  }
  T sum(int x) {
    T y = T(0);
    for (; x; x &= x - 1) y = y + c[x];
    return y;
  }
};
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int, int> x) const {
    return operator()(uint64_t(x.first) << 32 | x.second);
  }
};
template <long long mod>
struct dbinom {
  int *jc, *inv;
  dbinom(int n) {
    jc = new int[n + 5];
    inv = new int[n + 5];
    jc_init(n);
  }
  void jc_init(int n) {
    jc[0] = 1;
    for (int i = 1; i <= n; i++) jc[i] = (long long)jc[i - 1] * i % mod;
    inv[n] = power(jc[n], mod - 2, mod);
    for (int i = n; i; i--) inv[i - 1] = (long long)inv[i] * i % mod;
  }
  long long C(int x, int y) {
    if (x < y || y < 0) return 0;
    return (long long)jc[x] * inv[y] % mod * inv[x - y] % mod;
  }
};
struct dsu {
  int *fa, *sz;
  dsu(int n) {
    fa = new int[n + 5];
    sz = new int[n + 5];
    for (int i = 0; i <= n; i++) fa[i] = i, sz[i] = 1;
  }
  int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return 0;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
    return 1;
  }
  bool same(int x, int y) { return get(x) == get(y); }
};
int n;
double dis[N], ang[N];
long long k;
const double PI = acos(-1.0), eps = 1e-8;
int c[N], num = 0;
void add(int x, int y) {
  for (; x <= num; x += x & -x) c[x] += y;
}
int ask(int x) {
  int y = 0;
  for (; x; x &= x - 1) y += c[x];
  return y;
}
bool check(double r) {
  long long sum = 0;
  static double L[N], R[N], val[N];
  int tot = 0;
  num = 0;
  for (int i = 1; i <= n; i++)
    if (dis[i] > r) {
      double a = acos(r / dis[i]);
      L[++tot] = ang[i] - a;
      R[tot] = ang[i] + a;
      if (L[tot] < -PI) L[tot] += 2 * PI;
      if (R[tot] > PI) R[tot] -= 2 * PI;
      if (L[tot] > R[tot]) swap(L[tot], R[tot]);
      val[++num] = L[tot];
      val[++num] = R[tot];
    }
  if (tot) {
    sort(val + 1, val + num + 1);
    num = unique(val + 1, val + num + 1) - (val + 1);
    static pair<int, int> id[N];
    for (int i = 1; i <= tot; i++) {
      id[i].first = lower_bound(val + 1, val + num + 1, L[i]) - val;
      id[i].second = lower_bound(val + 1, val + num + 1, R[i]) - val;
    }
    sort(id + 1, id + tot + 1);
    memset(c, 0, sizeof c);
    for (int i = tot; i >= 1; i--) {
      sum += ask(id[i].second);
      add(id[i].first, 1);
      add(id[i].second, -1);
    }
  }
  sum = 1LL * n * (n - 1) / 2 - sum;
  return sum >= k;
}
int main() {
  qr(n);
  qr(k);
  for (int i = 1; i <= n; i++) {
    int x, y;
    qr(x);
    qr(y);
    dis[i] = sqrt(x * x + y * y);
    ang[i] = atan2(y, x);
  }
  double l = 0, r = sqrt(2e8), mid;
  while (l + eps < r) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", l);
  return 0;
}
