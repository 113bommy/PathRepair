#include <bits/stdc++.h>
int main() {
  int n, a[1005], i, j, count;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  if (a[0] == 0)
    count = 0;
  else
    count = n - a[0];
  for (i = 0; i < count; i++) {
    for (j = 0; j < n; j++) {
      if (j % 2 == 0) {
        if (a[j] == n - 1)
          a[j] = 0;
        else
          a[j] += 1;
      } else {
        if (a[j] == 0)
          a[j] = n - 1;
        else
          a[j] -= 1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i] != i) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
