#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323;
long long mod = 1000000000 + 7;
long long modu = 998244353;
const long double pii = acos(-1.0);
const long long INF = 1e18;
const long long inf = 1e9;
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
void fun() {}
const long long N = 1e6 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long tttt = 1;
  cin >> tttt;
  while (tttt--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a -= b;
    if (a <= 0) {
      cout << b << "\n";
      continue;
    }
    long long sleep = c - d;
    if (sleep <= 0) {
      cout << -1 << "\n";
      continue;
    }
    long long req = ceil((long double)a / (long double)sleep);
    long long ans = req * c + b;
    cout << ans << "\n";
  }
  return 0;
}
