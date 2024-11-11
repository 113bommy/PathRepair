#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long M = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long m1 = 1e9 + 7;
const long long m2 = 1e9 + 9;
const long long p1 = 402653189;
const long long p2 = 1610612741;
const long long lN = 22;
long long powermodm(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long power(long long _a, long long _b) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
long long dx[4] = {-1, 1, 0, 0};
long long dy[4] = {0, 0, 1, -1};
long long pw[lN], fact[N], invfact[N];
void pre() {
  fact[0] = 1;
  for (long long i = 0; i < lN; i++) pw[i] = power(2, i);
  for (long long i = 1; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;
  for (long long i = 0; i < N; i++)
    invfact[i] = powermodm(fact[i], mod - 2, mod);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long i, j;
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  for (i = 0; i < 1e6; i++) {
    long long val = p - i * d;
    if (val < 0) {
      cout << "-1";
      return 0;
    }
    if (val % w == 0 && (val / w) + i <= n) {
      cout << (val / w) << " " << i << " " << n - i - (val / w);
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
