#include <bits/stdc++.h>
int main() {
  int n, a, b, x;
  scanf("%d%d%d", &n, &a, &b);
  while (n-- > 0) {
    int y;
    scanf("%d", &x);
    y = (long long)x * a % b;
    printf("%d ", y / a);
  }
  printf("\n");
  return 0;
}
