#include <bits/stdc++.h>
long long a[1212121];
long long pow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long r = pow(a, b / 2, p);
  return r * r % p * (b % 2 ? a : 1) % p;
}
long long get3n(long long n, long long p) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  long long r = get3n(n / 2, p);
  return ((r + pow(3, n / 2, p) * r % p) % p + (n % 2 ? pow(3, n - 1, p) : 0)) %
         p;
}
struct M {
  long long a, b, c, d;
};
M gob(M a, M b, long long p) {
  return {(a.a * b.a + a.b * b.c) % p, (a.a * b.b + a.b * b.d) % p,
          (a.c * b.a + a.d * b.c) % p, (a.c * b.b + a.d * b.d) % p};
}
M pow(M a, long long b, long long p) {
  if (b == 0) return {1, 0, 0, 1};
  M r = pow(a, b / 2, p);
  if (b % 2 == 0)
    return gob(r, r, p);
  else
    return gob(gob(r, r, p), a, p);
}
int main() {
  long long n, x, y, p, i, j;
  scanf("%lld%lld%lld%lld", &n, &x, &y, &p);
  long long S = 0;
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    S += a[i];
    S %= p;
  }
  if (n == 1) {
    printf("%lld\n", a[i]);
    return 0;
  }
  auto F = gob({1, 1, 1, 0}, pow({1, 1, 1, 0}, x, p), p);
  long long mns_first = (a[0] + a[n - 1]) % p;
  long long v, nxtS;
  v = mns_first;
  nxtS = ((S * pow(3, x, p) - get3n(x, p) * v) % p + p) % p;
  S = nxtS;
  long long mns_second = (a[0] + (a[n - 2] * F.d + a[n - 1] * F.c) % p) % p;
  v = mns_second;
  x = y;
  nxtS = ((S * pow(3, x, p) - get3n(x, p) * v) % p + p) % p;
  S = nxtS;
  printf("%lld\n", S);
  return 0;
}
