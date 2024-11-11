#include <bits/stdc++.h>
using namespace std;
unsigned long long fib(unsigned long long n, unsigned long long m) {
  if (n == 0) return 0;
  n -= 2;
  unsigned long long a1, b1, c1, d1, a2, b2, c2, d2, ta1, tb1, tc1, td1, ta2,
      tb2, tc2, td2;
  a1 = 1;
  b1 = 1;
  c1 = 1;
  d1 = 1;
  a2 = 1;
  b2 = 1;
  c2 = 1;
  d2 = 0;
  while (n > 0) {
    if (n % 2 == 1) {
      ta1 = a1;
      tb1 = b1;
      tc1 = c1;
      td1 = d1;
      a1 = ta1 * a2 + tb1 * c2;
      b1 = ta1 * b2 + tb1 * d2;
      c1 = tc1 * a2 + td1 * c2;
      d1 = tc1 * b2 + td1 * d2;
      a1 %= m;
      b1 %= m;
      c1 %= m;
      d1 %= m;
    }
    ta2 = a2;
    tb2 = b2;
    tc2 = c2;
    td2 = d2;
    a2 = ta2 * ta2 + tb2 * tc2;
    b2 = ta2 * tb2 + tb2 * td2;
    c2 = tc2 * ta2 + td2 * tc2;
    d2 = tc2 * tb2 + td2 * td2;
    a2 %= m;
    b2 %= m;
    c2 %= m;
    d2 %= m;
    n /= 2;
  }
  return a1;
}
unsigned long long power(unsigned long long a, unsigned long long b,
                         unsigned long long m) {
  unsigned long long x = 1;
  a %= m;
  while (b) {
    if ((1 & b)) x = x * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return x;
}
int main() {
  unsigned long long base = 1;
  unsigned long long n, k, l, m;
  scanf("%llu%llu%llu%llu", &n, &k, &l, &m);
  bool flag = 0;
  if (l != 64) {
    unsigned long long a = base << l;
    if (k >= a) flag = 1;
  }
  if (flag)
    printf("0\n");
  else {
    unsigned long long ans = 1;
    unsigned long long qt2 = fib(n + 2, m);
    unsigned long long qt1 = (power(2, n, m) - qt2 + m) % m;
    for (int i = 0; i < l; i++) {
      if (k & (base << i))
        ans = (ans * qt1) % m;
      else
        ans = (ans * qt2) % m;
    }
    printf("%llu\n", ans);
  }
}
