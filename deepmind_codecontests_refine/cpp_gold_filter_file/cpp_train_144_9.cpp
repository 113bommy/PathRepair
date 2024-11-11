#include <bits/stdc++.h>
int main() {
  int n, c, ar[100], t, ans = 0;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d", &ar[i]);
  for (int i = 0; i < n - 1; ++i) {
    t = ar[i] - ar[i + 1] - c;
    if (t > ans) ans = t;
  }
  printf("%d\n", ans);
  return 0;
}
