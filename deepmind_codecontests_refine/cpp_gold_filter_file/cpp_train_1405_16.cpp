#include <bits/stdc++.h>
int main() {
  int n, i, j, count = 1, a, flag = 0, k, num = 0;
  scanf("%d", &n);
  scanf("%d", &a);
  if (a != 0) {
    num = n - a;
  }
  for (i = 1; i < n; i++) {
    if (flag == 1) {
      scanf("%d", &a);
      continue;
    }
    scanf("%d", &a);
    if (count % 2 == 1) {
      k = a - num;
      if (k < 0) {
        k = k + n;
      }
      if (k != count) {
        flag = 1;
      }
    } else {
      k = a + num;
      if (k > (n - 1)) {
        k = k - n;
      }
      if (k != count) {
        flag = 1;
      }
    }
    count++;
  }
  if (flag == 0) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
