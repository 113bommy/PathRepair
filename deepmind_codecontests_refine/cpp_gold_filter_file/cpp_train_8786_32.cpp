#include <bits/stdc++.h>
bool check(int a, int b, int x, int y) {
  if (x <= a and a <= y and x <= b and b <= y)
    return true;
  else
    return false;
}
int main() {
  int m, c[1014], sum = 0, i, re = 0, x, y;
  scanf("%d", &m);
  c[0] = 0;
  for (i = 1; i <= m; ++i) {
    scanf("%d", &c[i]);
    sum += c[i];
  }
  scanf("%d %d", &x, &y);
  for (i = 0; i <= m; ++i) {
    re += c[i];
    if (check(re, sum - re, x, y)) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  printf("0\n");
}
