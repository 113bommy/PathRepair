#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 100000007;
const double eps = 1e-10;
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
bool chk(long long cost) {}
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
long long lg(long long x) { return (long long)log2(x) + 1; }
bool smleql(double a, double b) {
  if (a < b || fabs(a - b) <= eps) return true;
  return false;
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
long long n, p, k, a[maxn];
long long ans = 0;
map<long long, long long> mp;
long long cal(long long x) {
  return (((x * x) % p * ((x * x) % p)) % p - k * x % p + p) % p;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> p >> k;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += mp[cal(a[i])];
    mp[cal(a[i])]++;
  }
  cout << ans;
  return 0;
}
