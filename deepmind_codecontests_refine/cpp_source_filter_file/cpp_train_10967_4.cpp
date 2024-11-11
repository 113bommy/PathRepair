#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int i, a, b, c;
  scanf("%d", &a);
  printf("%d ", a);
  for (i = 0; i < n; i++) {
    scanf("%d", &b);
    scanf("%d", &c);
    if (k > 0 && ((a < b + 1) && (b + 1 > c))) {
      b--;
      k--;
      printf("%d %d ", b, c);
    } else {
      printf("%d %d ", b, c);
    }
    a = c;
  }
  return 0;
}
