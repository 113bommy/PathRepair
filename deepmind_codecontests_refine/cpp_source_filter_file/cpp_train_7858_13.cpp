#include <bits/stdc++.h>
int main() {
  int n, i, j, c = 0;
  scanf("%d", &n);
  int a[n + 1];
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int max = 1, len = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1])
      len++;
    else {
      if (max < len) max = len;
      len = 1;
    }
  }
  if (max < len) max = len;
  printf("%d", max);
  return 0;
}
