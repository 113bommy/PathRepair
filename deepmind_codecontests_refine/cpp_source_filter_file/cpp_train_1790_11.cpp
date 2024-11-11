#include <bits/stdc++.h>
int main() {
  int n, a[100], i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 2) {
      printf("2");
    } else if (a[i] % 2 != 0) {
      printf("1");
    } else {
      printf("0");
    }
  }
  return 0;
}
