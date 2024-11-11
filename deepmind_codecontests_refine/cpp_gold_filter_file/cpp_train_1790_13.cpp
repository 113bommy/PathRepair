#include <bits/stdc++.h>
int main() {
  int n, a[100], i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 2) {
      printf("2\n");
    } else if (a[i] % 2 != 0) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}
