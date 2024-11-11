#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
long long inv(long long a, long long m) {
  if (a == 1) return 1;
  return inv(m % a, m) * (m - m / a) % m;
}
long long Pow(long long x, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * x % P;
    m >>= 1;
    x = x * x % P;
  }
  return ret;
}
long long sum(long long lim, int k) {
  if (k == 0)
    return 2 * lim + 1;
  else if (k == 2)
    return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P * inv(6, P) % P;
  else if (k == 4)
    return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P *
           (3 * Pow(lim, 2) + 3 * lim - 1) % P * inv(30, P) % P;
  else
    return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P *
           (3 * Pow(lim, 4) + 6 * Pow(lim, 3) - 3 * lim + 1) % P * inv(42, P) %
           P;
}
int main() {
  long long M, ans = 0, n, m;
  scanf("%lld", &M);
  n = sqrt(M), m = M % P;
  while ((n + 1) * (n + 1) <= M) n++;
  while (n * n > M) n--;
  for (long long x = -n; x <= n; x++) {
    long long y = sqrt(M - x * x);
    while ((y + 1) * (y + 1) <= M - x * x) y++;
    while (y * y > M - x * x) y--;
    ans += 2 * sum(y, 6) % P;
    ans += (6 * Pow(x, 2) % P - (3 * m + 6) % P) % P * sum(y, 4) % P;
    ans += (6 * Pow(x, 4) % P - (6 * m + 12) % P * Pow(x, 2) % P +
            (3 * m + 4) % P) %
           P * sum(y, 2) % P;
    ans += (2 * Pow(x, 6) % P - (3 * m + 6) % P * Pow(x, 4) % P +
            (3 * m + 4) % P * Pow(x, 2) % P + m * (m + 1) % P * (m + 2) % P) %
           P * sum(y, 0) % P;
    ans %= P;
  }
  ans = (ans % P + P) % P;
  ans = ans * inv(6, P) % P;
  printf("%lld\n", ans);
}
