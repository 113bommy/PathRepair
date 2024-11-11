#include <bits/stdc++.h>
int mp[111][111];
int main() {
  int n, m, x, tp;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &mp[i][j]);
      }
    }
    int all = n, ans = n, no;
    if (n & 1) {
      printf("%d\n", n);
      continue;
    } else {
      while (1) {
        no = 0;
        for (int i = 1; i <= all / 2; i++) {
          for (int j = 1; j <= m; j++) {
            if (mp[i][j] != mp[all + 1 - i][j]) no = 1;
            if (no) break;
          }
          if (no) break;
        }
        if (no) break;
        all /= 2, ans /= 2;
        if (all == 1) break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
