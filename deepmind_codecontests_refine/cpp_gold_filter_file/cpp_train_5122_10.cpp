#include <bits/stdc++.h>
const long long maxn = 50;
long long read() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
long long n, k, a[maxn];
void cut(long long p) {
  memset(a, 0, sizeof(a));
  for (long long i = 1; i <= 32; i++)
    if (((1 << (i - 1)) & p) > 0) a[i] = 1;
}
signed main() {
  n = read(), k = read();
  long long ans = -1;
  for (long long m = 1; m <= 32; m++) {
    long long p = n - k * m, cnt = 0;
    if (p <= 0) break;
    cut(p);
    for (long long i = 1; i <= 32; i++) cnt += a[i];
    if (cnt <= m && p >= m) {
      ans = m;
      break;
    }
  }
  printf("%I64d\n", ans);
}
