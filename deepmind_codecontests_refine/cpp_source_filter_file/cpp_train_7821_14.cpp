#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
inline long long MAX2(long long a, long long b) {
  return (a) > (b) ? (a) : (b);
}
inline long long MAX3(long long a, long long b, long long c) {
  return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}
inline long long MIN2(long long a, long long b) {
  return (a) < (b) ? (a) : (b);
}
inline long long MIN3(long long a, long long b, long long c) {
  return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}
int mod = 1e9 + 7;
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  int64_t d = extGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline int addMod(int a, int b, int m = mod) { return ((int64_t)a + b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((int64_t)a * b) % m; }
inline int divMod(int a, int b, int m = mod) {
  int64_t x, y;
  int64_t g = extGcd(b, m, x, y);
  if (g != 1) {
    cerr << "Bad gcd!" << '\n';
    for (;;)
      ;
  }
  x = (x % m + m) % m;
  return mulMod(a, x, m);
}
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
inline long long exp(long long a, long long b) {
  if (a == 0) return 0ll;
  long long r = 1LL;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % mod);
      r = (r + mod) % mod;
    }
    b /= 2;
    a = (a % mod) * (a % mod);
    a = (a + mod) % mod;
  }
  return (r + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}
unsigned long int setbits(long long n) {
  unsigned long int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (long long i = (long long)(0); i < (long long)(n); i++) cin >> a[i];
  long long ans = 0;
  long long mx = a[n - 1];
  ans += a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < mx) {
      ans += a[i];
      mx = MIN2(mx, a[i]);
    } else {
      ans += mx - 1;
      mx = mx--;
      if (mx <= 0) break;
    }
  }
  cout << ans << '\n';
}
