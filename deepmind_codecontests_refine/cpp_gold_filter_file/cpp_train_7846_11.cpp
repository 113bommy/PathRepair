#include <bits/stdc++.h>
long long divs[100001];
int main() {
  long long i = 0, n, sum = 0, zz = 0, a, b, c;
  int j = 0, ij = 0, m = 0;
  scanf("%lld", &n);
  if (n % 3 != 0) {
    printf("%d\n", 0);
    return 0;
  }
  n /= 3;
  for (i = 1; i * i < n; i++) {
    if (n % i == 0) {
      divs[m] = i;
      m++;
    }
  }
  for (i = 0; i <= m; i++) {
    ij = m - 1, j = 0;
    while (j < m && ij >= 0) {
      zz = divs[i] * divs[j] * divs[ij];
      if (zz > n)
        ij--;
      else if (zz < n)
        j++;
      else {
        a = divs[i] + divs[j] - divs[ij];
        b = divs[i] + divs[ij] - divs[j];
        c = divs[j] + divs[ij] - divs[i];
        if (a > 0 && b > 0 && c > 0 && a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
          sum++;
        }
        ij--, j++;
      }
    }
  }
  printf("%lld\n", sum);
  return 0;
}
