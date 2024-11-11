#include <bits/stdc++.h>
int main() {
  long long n;
  while (scanf("%lld", &n) != EOF) {
    if (n % 3 == 0) {
      for (long long i = 9; i < 1e17; i = i * 3) {
        if (n % i == 0)
          continue;
        else {
          printf("%lld\n", n / i + 1);
          break;
        }
      }
    } else {
      printf("%lld\n", n / 3 + 1);
    }
  }
  return 0;
}
