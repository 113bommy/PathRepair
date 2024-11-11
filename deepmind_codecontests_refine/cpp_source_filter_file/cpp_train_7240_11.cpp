#include <bits/stdc++.h>
int a, b, n, i;
int main() {
  scanf("%d\n%d", &n, &a);
  for (i = 1; i < n; i++) {
    scanf("%d", &b);
    printf("%d ", b - a);
    a = b;
  }
  printf("%d", b);
  return 0;
}
