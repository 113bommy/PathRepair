#include <bits/stdc++.h>
int main(void) {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a, &b);
    printf("%d", a + b);
  }
  return 0;
}
