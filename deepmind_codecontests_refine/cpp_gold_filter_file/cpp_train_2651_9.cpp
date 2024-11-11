#include <bits/stdc++.h>
using namespace std;
int f[21][1001000], i, j, n, m, two[21];
char s[1001000], ans[1001000];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), two[0] = 1;
  scanf("%d", &m);
  for (i = 1; i <= 20; i++) two[i] = two[i - 1] << 1;
  while (m--) {
    int t = 0, k, d;
    scanf("%d%d", &k, &d);
    for (i = 1; i <= d; i++) {
      f[0][i] = ++t;
      for (j = i + d; j <= k; j += d) f[0][j] = f[0][j - d] + 1, ++t;
    }
    for (i = 1; i <= 20; i++) {
      if (two[i - 1] >= n) break;
      for (j = 1; j <= k; j++)
        if (f[i - 1][j] <= two[i - 1])
          f[i][j] = f[i - 1][j];
        else
          f[i][j] = f[i - 1][f[i - 1][j] - two[i - 1]] + two[i - 1];
    }
    for (i = 1; i <= n; i++) {
      int st = min(i, k), tim = min(n - k + 1, n - i + 1);
      t = 0;
      for (j = 20; j >= 0; j--)
        if (t + two[j] <= tim) {
          if (st <= t) break;
          st = f[j][st - t] + t, t = t + two[j];
        }
      st = st + max(0, i - k);
      ans[st] = s[i];
    }
    printf("%s\n", ans + 1);
    for (i = 1; i <= n; i++) s[i] = ans[i];
  }
  return 0;
}
