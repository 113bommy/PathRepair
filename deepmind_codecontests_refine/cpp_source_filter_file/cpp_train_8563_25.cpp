#include <bits/stdc++.h>
int main() {
  int n, i, sum = 0;
  scanf("%d", &n);
  int x = n;
  for (i = 2; i < n; i++) {
    while (x >= i) {
      sum += x % i;
      x /= i;
    }
    sum += x;
    x = n;
  }
  int z = n - 2;
  for (i = 2; i <= z; i++) {
    if (sum % i == 0 && z % i == 0) {
      sum /= i;
      z /= i;
    }
  }
  printf("%d", sum);
  printf("/%d", z);
  return 0;
}
