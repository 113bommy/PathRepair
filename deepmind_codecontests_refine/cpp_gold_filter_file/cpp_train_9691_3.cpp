#include <bits/stdc++.h>
int main() {
  long long int n, d, i;
  scanf("%I64d %I64d", &n, &d);
  long long int a[1000];
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  }
  long long int j, k, x, y, z, g, count = 0;
  for (j = 0, k = 1; k < n; j++, k++) {
    x = a[j];
    y = a[k];
    z = x + d;
    g = y - d;
    if (z < g) {
      count = count + 2;
    } else if (z == g) {
      count++;
    }
  }
  printf("%I64d", count + 2);
  return 0;
}
