#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int i, j, a[n];
  for (i = 0; i < n; i++) {
    scanf(" %d", &a[i]);
  }
  int t;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j + 1] < a[j]) {
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
    }
  }
  printf("%d", a[n / 2]);
}
