#include <bits/stdc++.h>
int a, b, n, i;
int main() {
  scanf("%d\n%d", &n, &a);
  for (i = 1; i < n; i++) {
    scanf("%d", &b);
    printf("%d ", a + b);
    a = b;
  }
  printf("%d", b);
  return 0;
}
