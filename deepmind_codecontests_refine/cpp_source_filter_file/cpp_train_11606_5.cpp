#include <bits/stdc++.h>
int main() {
  int n, a[10], b[10], i = 0, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    a[i] = 1;
  }
  t = n;
  while (n - 1) {
    b[0] = 1;
    for (i = 1; i < t; i++) {
      b[i] = a[i] + b[i - 1];
    }
    for (i = 0; i < t; i++) {
      a[i] = b[i];
    }
    n--;
  }
  printf("%d", b[t - 1]);
}
