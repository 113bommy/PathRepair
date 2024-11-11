#include <bits/stdc++.h>
int n, m, b[300], a[200], c[300];
int pd() {
  for (int i = 1; i <= m; ++i)
    if (c[i] != b[i]) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int t = 0;
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]), t += b[i];
  for (int i = 1; i <= n - t + 1; ++i) {
    memset(c, 0, sizeof(c));
    for (int j = i; j <= i + t - 1; ++j) c[a[j]]++;
    if (pd()) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
}
