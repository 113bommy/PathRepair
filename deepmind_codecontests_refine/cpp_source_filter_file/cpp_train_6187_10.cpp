#include <bits/stdc++.h>
using namespace std;
long long n, ans, l, r;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline bool check(long long x, long long y) { return x * x + y * y <= n * n; }
signed main() {
  n = read();
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  l = 1, r = n;
  while (l < r) {
    long long mid = l + ((r - l + 1) >> 1);
    if (check(1, mid))
      l = mid;
    else
      r = mid - 1;
  }
  r = l;
  for (long long i = 1; i <= n; i++) {
    while (l >= 0 && !check(i + 1, l)) l--;
    while (!check(i, r)) r--;
    if (l == r)
      ans++;
    else
      ans += r - l;
  }
  ans *= 4;
  printf("%lld\n", ans);
}
