#include <bits/stdc++.h>
int main() {
  long int m, n, min, max, k, l;
  scanf("%ld%ld", &n, &m);
  max = ((n - m + 1) * (n - m)) / 2;
  k = n / m;
  l = n % m;
  min = ((k * (k - 1)) / 2) * (m - l);
  min += ((k + 1) * (k) / 2) * l;
  printf("%ld %ld", min, max);
  return 0;
}
