#include <bits/stdc++.h>
int main() {
  long long n;
  scanf("%lld", &n);
  long long maxi = sqrt(n);
  int is = 0;
  for (long long i = maxi; i >= 0; i--) {
    if (3 * (i + i * i) % 2 == 0) {
      if (3 * (i + i * i) / 2 + 2 * (i + 1) <= n) {
        if ((n - (3 * (i + i * i) / 2 + 2 * (i + 1))) % 3 == 0) {
          is++;
        }
      }
    }
  }
  printf("%d", is);
}
