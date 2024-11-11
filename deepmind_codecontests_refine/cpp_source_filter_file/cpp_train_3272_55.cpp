#include <bits/stdc++.h>
int main() {
  int j, g, i, n;
  int a[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n - 1; j++) {
      if (a[i] > a[j]) {
        g = a[i];
        a[i] = a[j];
        a[j] = g;
      }
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
