#include <bits/stdc++.h>
long long a, b, n;
long long pow(long long n, long long k) {
  long long res = 1;
  while (k--) res *= n;
  return res;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &n);
  if (b == 0) {
    printf("0\n");
    return 0;
  }
  for (int x = -1000; x <= 1000; ++x)
    if ((a * pow(x, n)) == b) {
      printf("%d\n", x);
      return 0;
    }
  printf("No solution\n");
  return 0;
}
