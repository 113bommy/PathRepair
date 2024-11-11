#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
long double pi = 3.1415926535897932384626433832795;
const int N = 3e5 + 10, lg = 31, MAXN = 1111;
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long _gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long _x1, _y1;
  long long d = _gcd(b % a, a, _x1, _y1);
  x = _y1 - (b / a) * _x1;
  y = _x1;
  return d;
}
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
    a %= mod;
    res %= mod;
  }
  return res;
}
long long dp[20000007];
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i <= 2 * n; i++) dp[i] = 2e18;
  dp[1] = x;
  for (int i = 1; i <= n; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + x);
    dp[i * 2] = min(dp[i * 2], dp[i] + y);
    dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i] + x + y);
  }
  cout << dp[n];
  return 0;
}
