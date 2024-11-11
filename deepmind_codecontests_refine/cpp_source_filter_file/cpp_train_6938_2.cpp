#include <bits/stdc++.h>
long long min(long long a, long long b) { return (a < b ? a : b); }
long long max(long long a, long long b) { return (a > b ? a : b); }
int main() {
  int T;
  scanf("%d", &T);
  ;
  while (T--) {
    int x;
    scanf("%d", &x);
    ;
    if (x == 0) {
      puts("1 1");
      continue;
    }
    int N = (int)sqrt(x);
    bool found = 0;
    for (long long n = N + 100; n >= 1; n--) {
      if (n * n < x) break;
      long long lo = 1, hi = n;
      while (lo <= hi) {
        long long q = (lo + hi) / 2;
        long long ones = n * n - (n / q) * (n / q);
        if (ones == x) {
          found = 1;
          printf("%I64d %I64d\n", n, q);
          break;
        } else if (ones > x)
          hi = q - 1;
        else
          lo = q + 1;
      }
      if (found) break;
    }
    if (!found) puts("-1");
  }
  return 0;
}
