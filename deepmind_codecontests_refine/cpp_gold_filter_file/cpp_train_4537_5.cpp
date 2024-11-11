#include <bits/stdc++.h>
int main() {
  long long int n, b = 2, k, r;
  scanf("%I64d%I64d", &n, &k);
  printf("2 ");
  if (k > n / 2) k = n - k;
  r = k;
  for (long long int i = 1; i < 2 * k; ++i) {
    if (i != 1) {
      b += i;
      printf("%I64d ", b);
      ++i;
    }
    for (long long int j = 0; j < (n - r) / k; ++j) {
      b += i;
      printf("%I64d ", b);
    }
    r = ((n - r) / k * k + r + k) % n;
  }
}
