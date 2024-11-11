#include <bits/stdc++.h>
int main() {
  int n, k, i;
  scanf("%d", &n);
  int a[n][2];
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a[i][0], &a[i][1]);
  }
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    if (k > a[i][0] && k <= a[i][1]) {
      printf("%d", n - i);
      break;
    }
  }
  return 0;
}
