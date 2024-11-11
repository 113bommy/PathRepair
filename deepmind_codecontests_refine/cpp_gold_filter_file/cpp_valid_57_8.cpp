#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long normalize(long long x, long long mod) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
string abc = "abcdefghijklmnopqrstuvwxyz";
const double PI = acosl(-1);
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1e18 + 5;
inline long long add(long long a, long long b, long long p = mod) {
  long long c = a + b;
  if (c >= p) c -= p;
  return c;
}
inline long long sub(long long a, long long b, long long p = mod) {
  long long c = a - b;
  if (c < 0) c += p;
  return c;
}
inline long long mul(long long a, long long b, long long p = mod) {
  return (a * 1LL * b) % p;
}
long long floor1(long long n, long long k) {
  if (n % k == 0 || n >= 0) return n / k;
  return (n / k) - 1;
}
long long ceil1(long long n, long long k) { return floor1(n + k - 1, k); }
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
const long long N = 2021 + 5;
long long n;
long long a[N], f[N];
vector<long long> ans;
void op(long long l, long long r) {
  ans.push_back(r);
  while (l <= r) {
    swap(f[a[l]], f[a[r]]);
    swap(a[l], a[r]);
    ++l;
    --r;
  }
}
void solve() {
  cin >> n;
  for (long long i = (1); i < (n + 1); ++i) cin >> a[i];
  for (long long i = (1); i < (n + 1); ++i) f[a[i]] = i;
  ans.clear();
  for (long long i = n; i > 1; i -= 2) {
    long long p = f[i];
    if (p == i and i - 1 == f[i - 1]) continue;
    if (p % 2 == 0 or f[i - 1] % 2 == 1) {
      cout << -1 << "\n";
      return;
    }
    op(1, f[i]);
    op(1, f[i - 1] - 1);
    op(1, f[i - 1] + 1);
    op(1, 3);
    op(1, i);
  }
  cout << ((long long)ans.size()) << "\n";
  for (long long i : ans) cout << i << " ";
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long t = 1;
  cin >> t;
  for (long long i = (1); i < (t + 1); ++i) {
    solve();
  }
  return 0;
}
