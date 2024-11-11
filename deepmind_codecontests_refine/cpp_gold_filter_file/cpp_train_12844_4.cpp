#include <bits/stdc++.h>
int n;
int ans[100010];
int main() {
  int i, t;
  scanf("%d", &n);
  if (n % 4 > 1)
    printf("-1\n");
  else {
    for (i = 1; i <= n / 2; i += 2) {
      ans[i] = i + 1;
      ans[i + 1] = n - i + 1;
      ans[n - i + 1] = n - i;
      ans[n - i] = i;
    }
    if (n % 4 == 1) ans[(n + 1) / 2] = (n + 1) / 2;
    for (i = 1; i < n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
  }
  return 0;
}
