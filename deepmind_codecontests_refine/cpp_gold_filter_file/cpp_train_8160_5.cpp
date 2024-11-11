#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
long long n, M, a[N], c[N], m[N];
int k;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long ksmul(long long a, long long b, long long p) {
  long long res = 0;
  if (b < 0) b = -b, a = -a;
  while (b) {
    if (b & 1) (res += a) %= p;
    a <<= 1;
    a %= p;
    b >>= 1;
  }
  return res;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long tmp = exgcd(b, a % b, x, y);
  long long c = x;
  x = y;
  y = c - a / b * y;
  return tmp;
}
long long inv(long long a, long long b) {
  long long x, y;
  exgcd(a, b, x, y);
  x = (x % b + b) % b;
  if (!x) x += b;
  return x;
}
long long work2() {
  long long m1 = m[1], c1 = a[1];
  for (int i = 2; i <= k; i++) {
    long long m2 = m[i], c2 = a[i];
    long long tmp = gcd(m1, m2);
    if ((c2 - c1) % tmp) {
      printf("NO\n");
      return 0;
    }
    long long m3 = m1 / tmp * m2, c3 = inv(m1 / tmp, m2 / tmp);
    c3 = ksmul(c3, (c2 - c1) / tmp, m2 / tmp);
    c3 = ksmul(c3, m1, m3);
    c3 = ((c3 + c1) % m3 + m3) % m3;
    m1 = m3;
    c1 = c3;
  }
  return c1;
}
int main() {
  scanf("%lld%lld%d", &n, &M, &k);
  for (int i = 1; i <= k; i++) scanf("%lld", &c[i]);
  long long lcm = c[1];
  for (int i = 2; i <= k; i++) {
    lcm = lcm / gcd(lcm, c[i]) * c[i];
    if (lcm > n) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 1; i <= k; i++) m[i] = c[i], a[i] = c[i] - i + 1LL;
  long long rr = m[1], aa = a[1];
  long long x = work2();
  if (!x) x += rr;
  if (x > M - k + 1) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    long long t = gcd(lcm, x + i - 1);
    if (t != c[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
