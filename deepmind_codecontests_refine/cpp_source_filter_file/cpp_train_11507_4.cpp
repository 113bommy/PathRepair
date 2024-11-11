#include <bits/stdc++.h>
int main() {
  long long int i, j, k, l, m, n;
  scanf("%I64d", &i);
  j = i * (i - 1) * (i - 2) * (i - 3) * (i - 4) / (1 * 2 * 3 * 4 * 5);
  k = j * (i - 5) / 6;
  l = k * (k - 6) / 7;
  printf("%I64d", j + k + l);
  return 0;
}
