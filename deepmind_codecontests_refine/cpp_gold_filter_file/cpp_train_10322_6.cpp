#include <bits/stdc++.h>
int main() {
  long int a[1000020], i, n, co = 0, c1 = 0;
  scanf("%ld", &n);
  for (i = 0; i < n; ++i) {
    scanf("%ld ", &a[i]);
    if (a[i] == 1) {
      c1++;
    } else {
      co++;
    }
  }
  for (i = 0; i < n; ++i) {
    if (a[i] == 1) {
      c1--;
    } else
      co--;
    if (co == 0 || c1 == 0) break;
  }
  printf("%ld", i + 1);
}
