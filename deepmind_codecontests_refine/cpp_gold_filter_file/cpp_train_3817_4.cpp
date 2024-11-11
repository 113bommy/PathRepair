#include <bits/stdc++.h>
int main() {
  int n, i, y = 1;
  scanf("%d", &n);
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    scanf("%1d", &a[i]);
  }
  b[0] = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] == 0) {
      b[y] = a[i];
      y++;
    }
  }
  for (i = 0; i < y; i++) {
    printf("%d", b[i]);
  }
}
