#include <bits/stdc++.h>
const int LOG = 62;
long long w[LOG + 5];
long long pot(long long a, long long b) {
  long long res = 1;
  while (b--) res *= a;
  return res;
}
void init() {
  w[1] = 0;
  for (int i = 2; i <= LOG; i++)
    for (int j = 1; j < i; j++)
      if (i % j == 0) w[i] += pot(2, j - 1) - w[j];
}
int len(long long n) {
  if (n == 0) return 1;
  int res = 0;
  while (n > 0) res++, n /= 2;
  return res;
}
long long fooSmall(long long n) {
  int d = len(n);
  int good[5] = {3, 7, 10, 15, 31};
  long long res = 0;
  for (int i = 0; i < 5; i++)
    if ((1 << (d - 1)) <= good[i] && good[i] <= n) res++;
  return res;
}
long long multi(long long b, long long k) {
  int d = len(b);
  long long res = 0;
  while (k--) res = (res << d) + b;
  return res;
}
long long foo(long long n) {
  int d = len(n);
  if (d <= 5) return fooSmall(n);
  long long res = 0;
  for (int i = 1; i < d; i++)
    if (d % i == 0) {
      long long l = (n >> (d - i));
      long long p = (1 << (i - 1));
      if (multi(l, d / i) <= n) res++;
      if (l == p) continue;
      res += (l - p) - foo(l - 1);
    }
  return res;
}
long long solve(long long n) {
  int d = len(n);
  long long res = 0;
  for (int i = 1; i < d; i++) res += w[i];
  res += foo(n);
  return res;
}
int main() {
  init();
  long long x, y;
  (scanf("%lld %lld", &x, &y) ?: 0);
  printf("%lld\n", solve(y) - solve(x - 1));
  return 0;
}
