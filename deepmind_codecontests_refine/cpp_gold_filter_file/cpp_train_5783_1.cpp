#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
int main() {
  long long n, a, b, p, q;
  while (scanf("%I64d%I64d%I64d%I64d%I64d", &n, &a, &b, &p, &q) != EOF) {
    long long sum = 0, k, t;
    sum += (n / a * p + n / b * q);
    k = gcd(a, b);
    t = p > q ? q : p;
    sum -= (n / (a * b / k) * t);
    printf("%I64d\n", sum);
  }
  return 0;
}
