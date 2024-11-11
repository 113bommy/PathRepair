#include <bits/stdc++.h>
int main() {
  long long k, b, n, t, z, s = 0, flag = 0, x = 1;
  scanf("%I64d%I64d%I64d%I64d", &k, &b, &n, &t);
  while (x <= t) {
    x = x * k + b;
    s++;
  }
  if (s > n)
    printf("0");
  else
    printf("%I64d", n - s + 1);
  return 0;
}
