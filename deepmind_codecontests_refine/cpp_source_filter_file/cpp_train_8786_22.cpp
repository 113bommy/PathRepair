#include <bits/stdc++.h>
int main() {
  int m, a[101], i, sum, a_sum, b_sum, x, y;
  int flag = 0;
  int check(int a, int x, int y);
  scanf("%d", &m);
  sum = 0;
  a_sum = 0;
  b_sum = 0;
  for (i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  scanf("%d%d", &x, &y);
  for (i = 0; i < m; i++) {
    a_sum += a[i];
    sum -= a[i];
    if (check(a_sum, x, y) && check(sum, x, y)) {
      printf("%d\n", i + 1);
      flag = 1;
      break;
    }
  }
  if (flag == 0) printf("0\n");
  return 0;
}
int check(int a, int x, int y) {
  if ((a >= x) && (a <= y)) return 1;
  return 0;
}
