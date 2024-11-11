#include <bits/stdc++.h>
int main() {
  int n, i, sum = 0;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum = sum + a[i];
  }
  if (n == 1) {
    if (sum % 2 == 0) {
      printf("1");
    } else {
      printf("1");
    }
    return 0;
  }
  int res = 0;
  if (sum % 2 == 0) {
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        res++;
      }
    }
  } else {
    for (i = 0; i < n; i++) {
      if (a[i] % 2 != 0) {
        res++;
      }
    }
  }
  printf("%d", res);
}
