#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int check(int *aa, int n, long long k, int h) {
  int i;
  long long x, sum;
  x = 1, sum = aa[n - 1];
  for (i = n - 2; i >= 0; i--) {
    long long p = n - 1 - i + h - 1;
    int q = n - 1 - i;
    int d = gcd(p, q);
    p /= d, q /= d;
    x /= q;
    if (p >= (k + x - 1) / x) {
      while (i >= 0) {
        if (aa[i] > 0) return 1;
        i--;
      }
      return 0;
    }
    x *= p;
    if (aa[i] >= (k - sum + x - 1) / x) return 1;
    sum += aa[i] * x;
    if (sum >= k) return 1;
  }
  return 0;
}
int main() {
  static int aa[200000];
  int n, i, zero;
  long long lower, upper, k;
  scanf("%d%lld", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &aa[i]);
    if (aa[i] >= k) {
      printf("0\n");
      return 0;
    }
  }
  zero = 1;
  for (i = 0; i < n - i; i++)
    if (aa[i] != 0) {
      zero = 0;
      break;
    }
  if (zero) {
    printf("%lld\n", (k - aa[n - 1] + aa[n - 2] - 1) / aa[n - 2]);
    return 0;
  }
  lower = 0, upper = 1500000000;
  while (upper - lower > 1) {
    int h = (lower + upper) / 2;
    if (check(aa, n, k, h))
      upper = h;
    else
      lower = h;
  }
  printf("%lld\n", upper);
  return 0;
}
