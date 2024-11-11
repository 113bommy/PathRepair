#include <bits/stdc++.h>
int main() {
  int n, m, i, j, k;
  scanf("%d %d", &n, &m);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        k = a[i];
        a[i] = a[j];
        a[j] = k;
      }
    }
  }
  int s = 0;
  for (i = 0; i < m; i++) {
    s = s + a[i];
  }
  printf("%d", s);
  return 0;
}
