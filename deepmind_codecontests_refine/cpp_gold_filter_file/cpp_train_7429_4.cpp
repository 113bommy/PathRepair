#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
using namespace std;
using LL = long long;
constexpr LL mod = 1e9 + 7;
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long ret = ex_gcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}
LL mul(LL u, LL v, LL p) {
  return (u * v - LL((long double)u * v / p) * p + p) % p;
}
LL bin(LL x, LL n, LL MOD) {
  LL ret = MOD != 1;
  for (x %= MOD; n; n >>= 1, x = x * x % MOD)
    if (n & 1) ret = ret * x % MOD;
  return ret;
}
LL norm(LL x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline long long get_inv(long long a) {
  long long x, y;
  ex_gcd(a, mod, x, y);
  return norm(x + mod);
}
clock_t startTime;
void getCurrentTime() {
  cerr << "Time : " << (double)(clock() - startTime) / CLOCKS_PER_SEC << " s\n";
}
template <class T>
inline void umin(T &x, T y) {
  x = x > y ? y : x;
}
template <class T>
inline void umax(T &x, T y) {
  x = x < y ? y : x;
}
template <class T>
inline void dec(T &x, T y) {
  x -= y;
  if (x < 0) x += mod;
}
template <class T>
inline void add(T &x, T y) {
  x += y;
  if (x >= mod) x -= mod;
}
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename... Args>
void read(T &first, Args &...args) {
  read(first);
  read(args...);
}
template <class T>
LL ctz(T a) {
  return sizeof(T) > 2 ? __builtin_ctzll(a) : __builtin_ctz(a);
}
template <class T>
inline T gcd(T _a, T _b) {
  T a = abs(_a), b = abs(_b);
  LL shift = ctz(a | b);
  for (b >>= ctz(b), a >>= ctz(a); a; a -= b, a >>= ctz(a))
    if (a < b) swap(a, b);
  return b << shift;
}
const double PI = acos(-1.0);
constexpr LL INF = 0x3f3f3f3f;
constexpr long long linf = 0x3f3f3f3f3f3f3f3f;
constexpr unsigned long long base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr LL maxn = 1005;
double c[maxn][maxn], f[100 * maxn][200], ans;
LL n, q, a[maxn * 100], u, v, k, d[maxn * 100];
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr),
      cout << fixed << setprecision(10);
  for (LL i = (0), _i = (maxn); i < _i; ++i) {
    c[i][0] = 1;
    for (LL j = (1), _j = (i + 1); j < _j; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = a[i];
    f[i][a[i]] = 1;
    ans += f[i][0];
  }
  cin >> q;
  while (q--) {
    cin >> u >> v >> k;
    ans -= f[u][0];
    for (LL i = 0; i <= a[u]; i++) {
      double s = 0;
      for (LL j = i; j <= min(d[u], k + i); j++) {
        s += f[u][j] * c[j][j - i] * c[d[u] - j][k - (j - i)];
      }
      f[u][i] = s / c[d[u]][k];
    }
    ans += f[u][0], d[u] -= k, d[v] += k;
    cout << ans << '\12';
  }
  return 0;
}
