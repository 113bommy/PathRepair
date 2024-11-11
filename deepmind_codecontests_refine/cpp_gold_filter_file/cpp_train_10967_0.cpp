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
    if (k > 0 && ((a + 1 < b) && (b > c + 1))) {
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
