#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 100000007;
const double eps = 1e-10;
const double pi = 3.1415926535;
long long qpow(long long a, long long b) {
  long long tmp = a % MOD, ans = 1;
  while (b) {
    if (b & 1) {
      ans *= tmp, ans %= MOD;
    }
    tmp *= tmp, tmp %= MOD, b >>= 1;
  }
  return ans;
}
long long lowbit(long long x) { return x & -x; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long mmax(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long mmin(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
void mod(long long &a) {
  a += MOD;
  a %= MOD;
}
bool chk(long long now) {}
long long half(long long l, long long r) {
  while (l <= r) {
    long long m = (l + r) / 2;
    if (chk(m))
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}
long long ll(long long p) { return p << 1; }
long long rr(long long p) { return p << 1 | 1; }
long long mm(long long l, long long r) { return (l + r) / 2; }
long long lg(long long x) {
  if (x == 0) return 1;
  return (long long)log2(x) + 1;
}
bool smleql(double a, double b) {
  if (a < b || fabs(a - b) <= eps) return true;
  return false;
}
bool bigeql(double a, double b) {
  if (a > b || fabs(a - b) <= eps) return true;
  return false;
}
bool eql(double a, double b) {
  if (fabs(a - b) < eps) return 1;
  return 0;
}
double len(double a, double b, double c, double d) {
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
bool isp(long long x) {
  if (x == 1) return false;
  if (x == 2) return true;
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < 48 || ch > 57) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) {
    s = (s << 1) + (s << 3) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (!(a & 1) && !(b & 1))
    return gcd(a >> 1, b >> 1) << 1;
  else if (!(b & 1))
    return gcd(a, b >> 1);
  else if (!(a & 1))
    return gcd(a >> 1, b);
  else
    return gcd(abs(a - b), min(a, b));
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
long long n;
void gao1() {
  if (n == 4 || n == 5) {
    cout << -1;
    return;
  }
  cout << 1 << ' ' << 2 << endl;
  cout << 1 << ' ' << 3 << endl;
  cout << 1 << ' ' << 4 << endl;
  for (long long i = 5; i <= n; ++i) cout << 4 << ' ' << i << endl;
}
void gao2() {
  for (long long i = 2; i <= n; ++i) cout << 1 << ' ' << i << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
    cout << 1 << ' ' << 2;
    return 0;
  } else if (n == 3) {
    cout << -1 << endl;
    cout << 1 << ' ' << 2 << endl;
    cout << 2 << ' ' << 3;
    return 0;
  }
  gao1();
  gao2();
  return 0;
}
