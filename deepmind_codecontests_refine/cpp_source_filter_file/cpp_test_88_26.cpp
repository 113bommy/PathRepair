#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
vector<long long> fact(1);
int gcdExtended(int a, int b, int* x, int* y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return 0;
  else {
    int res = (x % m + m) % m;
    return res;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long n, long long p) { return power(n, p - 2, p); }
long long ncr(long long n, long long r) {
  return (n >= r ? (fact[n] * modInv(fact[r], mod)) % mod *
                       modInv(fact[n - r], mod) % mod
                 : 0);
}
long long add(long long a, long long b) {
  long long z = a + b;
  if (z >= mod) z -= mod;
  return z;
}
long long mul(long long a, long long b) { return (a * b) % mod; }
long long sub(long long a, long long b) { return (a - b + mod) % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1, p, i, j, n, x;
  cin >> tt;
  for (p = 1; p <= tt; p++) {
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0)
      cout << "YES\n";
    else {
      long long f = 0;
      for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          f = 1;
          break;
        }
      }
      if (f)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
