#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long inl() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
inline double ind() {
  double x;
  scanf("%lf", &x);
  return x;
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    int y = power(x, n / 2);
    return y * y;
  } else
    return x * power(x, n - 1);
}
long long fact[21], a[21], rfact[21];
long long C(long long n, long long k) {
  long long ret = 1;
  for (long long i = n; i >= n - k + 1; i--) {
    ret = modMul(ret, i);
  }
  ret = modMul(ret, rfact[k]);
  return ret;
}
int main() {
  int n = in();
  long long s = inl();
  for (int i = 0; i < n; i++) a[i] = inl();
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = modMul(fact[i - 1], i);
  for (int i = 0; i <= n; i++) rfact[i] = modInverse(fact[i]);
  int cnt = 0;
  long long tmp, tmp2;
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    cnt = 0;
    tmp = s;
    tmp2 = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        tmp -= (a[j] + 1);
        cnt++;
      }
    }
    if (tmp >= 0) {
      tmp2 = C(tmp + n - 1, n - 1);
    }
    if (cnt & 1) {
      ans = modSub(ans, tmp2);
    } else {
      ans = modAdd(ans, tmp2);
    }
  }
  printf("%I64d\n", ans);
}
