#include <bits/stdc++.h>
int main() {
  int n, a[1005], b[1005], k = 0, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = i;
  }
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[i] <= b[i])
        a[i] = b[i] - a[i];
      else
        a[i] = (n - a[i]) + b[i];
    } else {
      if (a[i] >= b[i])
        a[i] = a[i] - b[i];
      else
        a[i] = a[i] + (n - b[i]);
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      k = 1;
      break;
    }
  }
  if (k == 1)
    printf("No");
  else
    printf("Yes");
  return 0;
}
