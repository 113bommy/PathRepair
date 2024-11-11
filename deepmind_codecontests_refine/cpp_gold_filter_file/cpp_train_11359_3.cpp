#include <bits/stdc++.h>
int main() {
  long long int n, x, f, j, count = 0;
  scanf("%I64d", &n);
  long int c[n];
  for (j = 0; j < n; j++) {
    scanf("%I64d", &c[j]);
  }
  scanf("%I64d %I64d", &x, &f);
  for (j = 0; j < n; j++) {
    if (c[j] > x) {
      count += c[j] / (x + f);
      if (c[j] % (x + f) > x) count += 1;
    }
  }
  long long int price = count * f;
  printf("%I64d", price);
  return 0;
}
