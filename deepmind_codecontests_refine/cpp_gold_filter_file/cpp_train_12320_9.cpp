#include <bits/stdc++.h>
const int N = 200010;
int x[N], idx[N];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 1, tmp; i <= n; i++) {
      scanf("%d", &tmp);
      idx[tmp] = i;
    }
    int ans = n, check = true;
    for (int i = 0; i < n; i++) {
      x[i] = idx[x[i]];
      if (x[i] != i + 1) check = false;
    }
    if (check) {
      puts("0");
      continue;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
      if (x[i] < max) {
        ans = n - i;
        break;
      } else
        max = x[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
