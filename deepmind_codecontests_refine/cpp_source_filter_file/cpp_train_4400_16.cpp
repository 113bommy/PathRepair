#include <bits/stdc++.h>
int main() {
  int n, i, j;
  j = 0;
  int a[100];
  int b[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  while (j <= n) {
    for (i = 0; i < n; i++) {
      if (a[i] == j) b[j - 1] = i + 1;
    }
    j++;
  }
  for (i = 0; i < n; i++) printf("%d", b[i]);
}
