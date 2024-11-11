#include <bits/stdc++.h>
int main() {
  int n, i, j, t;
  scanf("%d", &n);
  int c[n + 1];
  for (i = 1; i < n + 1; i++) {
    scanf("%d", &c[i]);
  }
  for (i = 1; i <= ((n - i) + 1); i = i + 2) {
    t = c[i];
    c[i] = c[((n - i) + 1)];
    c[((n - i) + 1)] = t;
  }
  for (i = 1; i < n + 1; i++) {
    printf("%d", c[i]);
  }
  return 0;
}
