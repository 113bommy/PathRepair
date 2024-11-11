#include <bits/stdc++.h>
int a[100010];
int main() {
  int n, x, ans;
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (a[x - 1] != 0) {
        a[x] = a[x - 1] + 1;
      } else {
        a[x] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans < a[i]) {
        ans = a[i];
      }
    }
    printf("%d\n", n - ans);
  }
}
