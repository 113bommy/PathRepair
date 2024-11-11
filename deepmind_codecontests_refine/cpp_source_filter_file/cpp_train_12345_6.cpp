#include <bits/stdc++.h>
int main() {
  long long a[500000], n, n2 = 0, i, d = 0;
  scanf("%lli", &n);
  n2 = n;
  if (n % 2 == 0) {
    for (i = 0; i < (n / 2); i++) a[i] = 1;
    d = 1;
  } else if (n % 3 == 0 && d == 0) {
    a[0] = 7;
    for (i = 1; i <= (n - 3) / 2; i++) {
      a[i] = 1;
    }
  } else if (n % 2 != 0 && n % 3 != 0) {
    n2 = n2 - 3;
    for (i = 1; i <= (n / 2); i++) {
      a[i] = 1;
    }
    a[0] = 7;
  }
  for (i = 0; a[i] != 0; i++) {
    printf("%lli", a[i]);
  }
}
