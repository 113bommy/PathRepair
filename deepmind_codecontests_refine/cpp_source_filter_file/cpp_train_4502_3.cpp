#include <bits/stdc++.h>
int main() {
  long long i, a, b, c = 0, d = 0, n;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a);
    if (a == 1) {
      printf("%lld\n", 0);
    } else if (a % 2 == 0) {
      printf("%lld\n", a / 2 - 1);
    } else if (a % 2 != 0) {
      printf("%lld\n", a / 2);
    }
  }
}
