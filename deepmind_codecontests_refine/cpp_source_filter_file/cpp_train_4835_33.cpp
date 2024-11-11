#include <bits/stdc++.h>
using namespace std;
int a[110][110], b[110];
int main() {
  int n, m, k;
  while (scanf("%d %d %d", &n, &m, &k) != EOF) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 100;
    if (n > k) {
      for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
          if (j == i) continue;
          int x = 0, y = 0;
          for (int c = 1; c <= m; c++) {
            if (a[i][c] != a[j][c]) x++;
            if (a[i][c] == a[j][c]) y++;
          }
          sum += min(x, y);
          if (sum > k) break;
        }
        if (sum > k) continue;
        if (sum < ans) ans = sum;
      }
      if (ans < 100)
        printf("%d\n", ans);
      else
        printf("-1\n");
    } else {
      int s = 1 << n;
      for (int i = 0; i < s; i++) {
        for (int j = 1; j <= n; j++) {
          if (s & (1 << (j - 1)))
            b[j] = 1;
          else
            b[j] = 0;
        }
        int sum = 0;
        for (int j = 1; j <= m; j++) {
          int x = 0, y = 0;
          for (int r = 1; r <= n; r++) {
            if (a[r][j] != b[r]) x++;
            if (a[r][j] == b[r]) y++;
          }
          if (j == 1)
            sum += x;
          else
            sum += min(x, y);
        }
        if (sum <= k && sum < ans) {
          ans = sum;
        }
      }
      if (ans < 100)
        printf("%d\n", ans);
      else
        printf("-1\n");
    }
  }
  return 0;
}
