#include <bits/stdc++.h>
int main() {
  int n, sum = 0, i, mod, a, nu, de;
  scanf("%d", &n);
  for (i = 2; i <= (n - 1); i++) {
    a = n;
    while (a != 0) {
      mod = a % i;
      a = (int)(a / i);
      sum = sum + mod;
    }
  }
  nu = sum;
  de = n - 2;
  for (i = (n - 2); i >= 2; i--) {
    if (sum % i == 0 && (n - 2) % i == 0) {
      nu = sum / i;
      de = (n - 2) / i;
    }
  }
  printf("%d/%d", nu, de);
  return 0;
}
