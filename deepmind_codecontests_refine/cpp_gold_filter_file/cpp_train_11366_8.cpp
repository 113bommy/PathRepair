#include <bits/stdc++.h>
int gcd(int, int);
int main() {
  int a, b, n, s, an;
  scanf("%d%d%d", &a, &b, &n);
  while (1) {
    s = gcd(a, n);
    n = n - s;
    if (n > 0) {
      an = gcd(b, n);
      n = n - an;
      if (n <= 0) {
        printf("1");
        break;
      }
    } else if (n == 0) {
      printf("0");
      break;
    } else {
      printf("1");
      break;
    }
  }
  return 0;
}
int gcd(int n1, int n2) {
  int i, Gcd;
  for (i = 1; i <= n1 && i <= n2; ++i) {
    if (n1 % i == 0 && n2 % i == 0) {
      Gcd = i;
    }
  }
  return Gcd;
}
