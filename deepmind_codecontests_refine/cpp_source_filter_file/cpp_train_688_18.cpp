#include <bits/stdc++.h>
int main() {
  int i, j, n, flag = 0;
  scanf("%d", &n);
  int t1 = 1, t2 = 1, arr1[1000], next;
  arr1[0] = 1;
  arr1[1] = 1;
  for (i = 3; i <= (n + 1); i++) {
    next = t1 + t2;
    t1 = t2;
    t2 = next;
    arr1[i - 1] = next;
  }
  for (i = 1; i <= n; i++) {
    flag = 0;
    for (j = 1; j < 15; j++) {
      if (i == arr1[j]) {
        printf("O");
        flag = 1;
      }
    }
    if (flag == 0) {
      printf("o");
    }
  }
  return 0;
}
