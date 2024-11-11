#include <bits/stdc++.h>
int prime(long long int n) {
  long long int i, c = 0;
  if (n < 2)
    return 1;
  else {
    for (i = 2; i * i <= n; i++) {
      if (n % i == 0) c++;
    }
  }
  return c;
}
int main() {
  long long int a, b, d;
  scanf("%lld", &a);
  b = prime(a);
  d = prime(a - 1);
  if (b == 0)
    printf("1");
  else if (b != 0 && a % 2 == 0)
    printf("2");
  else if (a % 2 == 1 && d == 0)
    printf("2");
  else if (a % 2 == 1 && d != 0)
    printf("3");
  return 0;
}
