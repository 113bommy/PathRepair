#include <bits/stdc++.h>
int main() {
  int n;
  int a1[55], a2[55];
  int b[55];
  int ans[55];
  int min;
  int i, j;
  int d;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n - 1; i++) scanf("%d", &a1[i]);
    for (i = 1; i <= n - 1; i++) scanf("%d", &a2[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (i = 1; i <= n; i++) {
      ans[i] = b[i];
      d = 0;
      for (j = 1; j <= i - 1; j++) {
        ans[i] = ans[i] + a1[j];
        d = d + 1;
      }
      for (j = n - 1; j >= 1 + d; j--) {
        ans[i] = ans[i] + a2[i];
      }
    }
    min = 9999999;
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        if ((ans[i] + ans[j]) < min) min = ans[i] + ans[j];
      }
    }
    printf("%d\n", min);
  }
  return 0;
}
