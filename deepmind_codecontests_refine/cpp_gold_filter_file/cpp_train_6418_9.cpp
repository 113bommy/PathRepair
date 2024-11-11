#include <bits/stdc++.h>
int main() {
  int n, i, B = 0, C = 0, sum = 0, a;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    if (a < 0)
      B = B + a;
    else
      C = C + a;
  }
  sum = C - B;
  printf("%d", sum);
  return 0;
}
