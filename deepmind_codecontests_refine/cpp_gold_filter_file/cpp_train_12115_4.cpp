#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1;
template <class T>
inline T _sq(T a) {
  return a * a;
}
template <class T, class X>
inline T _pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T, class X, class Y>
inline T _bigmod(T n, X m, Y mod) {
  unsigned long long ret = 1, a = n % mod;
  while (m) {
    if (m & 1) ret = (ret * a) % mod;
    m >>= 1;
    a = (a * a) % mod;
  }
  ret %= mod;
  return (T)ret;
}
template <class T, class Y>
inline T _modinv(T n, Y mod) {
  return _bigmod(n, mod - 2, mod);
}
long long a, b, k, base, dp[400000];
long long go(long long num) {
  if (num == base) return 0;
  if (num < base) return 1000000000000000000LL;
  long long &ret = dp[num];
  if (ret == -1) {
    ret = 1 + go(num - 1);
    for (int i = 2; i <= k; i++) {
      long long v = num - num % i;
      ret = min(ret, 1 + go(v));
    }
  }
  return ret;
}
int main() {
  cin >> a >> b >> k;
  if (a == b) {
    puts("0");
    return 0;
  }
  long long L = 1;
  for (int i = 1; i <= k; i++) {
    L = _lcm((long long)i, L);
  }
  long long lft = (b + L - 1) / L, rgt = (a - 1) / L;
  long long ans = 0;
  if (a % L == 0) {
    ans++;
    a--;
  }
  memset(dp, -1, sizeof dp);
  if (lft <= rgt) {
    base = 0;
    ans += go(a % L) + (rgt - lft) * (1 + go(L - 1));
    if (b % L != 0) {
      memset(dp, -1, sizeof dp);
      base = b % L;
      ans += 1 + go(L - 1);
    }
  } else {
    base = b % L;
    ans += go(a % L);
  }
  cout << ans << endl;
  return 0;
}
