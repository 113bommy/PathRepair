#include <bits/stdc++.h>
int a[110], b[110];
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    bool pd = true;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      if (a[i] < b[i] || a[i] < a[i - 1] || b[i] < b[i - 1]) {
        pd = false;
      }
      if (a[i] - a[i - 1] < b[i] - b[i - 1]) {
        pd = false;
      }
    }
    if (!pd) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
