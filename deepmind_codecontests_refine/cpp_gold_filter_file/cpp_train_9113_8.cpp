#include <bits/stdc++.h>
const int p = 1000003;
long long m, n, q, r, s, t;
inline long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long t = power(x, y / 2);
  t = t * t % p;
  if (y & 1) t = t * x % p;
  return t;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  if ((n < 63) && (m > (1LL << n))) {
    printf("1 1\n");
    return 0;
  }
  for (t = 2; t < m; t = t << 1) r = r + (m - 1) / t;
  r = power(2, r % (p - 1));
  s = power(2, n % (p - 1));
  t = 1;
  if (m - 1 < p)
    for (q = 1; q < m; q++) t = t * (s + p - q) % p;
  r = power(r, p - 2);
  s = power(s, (m - 1) % (p - 1));
  s = s * r % p;
  t = t * r % p;
  if (m - 1 < p)
    printf("%I64d %I64d\n", (s - t + p) % p, s);
  else
    printf("%I64d %I64d\n", s, s);
  return 0;
}
