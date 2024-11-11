#include <bits/stdc++.h>
int main() {
  long long int t, n, a, i;
  scanf("%lld", &t);
  double c;
  while (t--) {
    scanf("%lld", &n);
    for (i = 2; i < 30; i++) {
      c = pow(2, i);
      a = c;
      a = a - 1;
      if (n % a == 0) {
        printf("%lld", n / a);
        i = 30;
      }
    }
  }
  return 0;
}
