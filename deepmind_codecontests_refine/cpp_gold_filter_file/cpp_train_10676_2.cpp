#include <bits/stdc++.h>
int main() {
  long long i, n, t;
  scanf("%I64d", &n);
  printf("2\n");
  if (n == 1) return 0;
  for (i = 2; i <= n; i++) {
    t = (i + 1) * (i + 1) * i;
    t -= i - 1;
    printf("%I64d\n", t);
  }
  return 0;
}
