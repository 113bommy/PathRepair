#include <bits/stdc++.h>
int main() {
  long long n, k, i, ans;
  scanf("%I64d", &n);
  scanf("%ld", &k);
  long long r;
  for (i = 1; i <= n; i++) {
    r = i * (i + 1);
    if (r / 2 + i - k == n) break;
  }
  ans = r / 2 - k;
  printf("%I64d", ans);
  return 0;
}
