#include <bits/stdc++.h>
int main() {
  int n, temp, i, j;
  scanf("%d", &n);
  int a[n - 1];
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n - 1; i++)
    for (j = 1; j <= n - 1; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  for (i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
