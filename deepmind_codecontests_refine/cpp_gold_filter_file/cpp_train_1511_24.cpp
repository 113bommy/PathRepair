#include <bits/stdc++.h>
long long int a[10000005];
int main() {
  long long int i, j, m, n, sum;
  while (~scanf("%lld", &n)) {
    for (i = 0; i < 10000005; i++) a[i] = 0;
    sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%lld", &j);
      a[j] += 1;
    }
    for (i = 0; i < 10000005; i++) {
      if (a[i] > 1) {
        a[i + 1] += a[i] / 2;
        a[i] = a[i] % 2;
      }
    }
    for (i = 0; i < 10000005; i++) sum += a[i];
    printf("%lld\n", sum);
  }
  return 0;
}
