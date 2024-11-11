#include <bits/stdc++.h>
int main() {
  long long n, i, sum = 1, k = 100, m;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    sum = sum * 2;
  }
  if (n > 12) {
    m = n - 12;
    for (i = 1; i <= m; i++) {
      k = k * 2;
    }
    sum = sum - k;
  }
  printf("%I64d", sum);
  return 0;
}
