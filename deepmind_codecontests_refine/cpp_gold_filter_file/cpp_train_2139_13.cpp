#include <bits/stdc++.h>
using namespace std;
int f[4020][4020];
char s[4020], t[4020];
int n, m;
int ti, td, tr, te;
int pre[2][300];
int main() {
  scanf("%d%d%d%d\n", &ti, &td, &tr, &te);
  scanf("%s\n", s);
  n = strlen(s);
  scanf("%s\n", t);
  m = strlen(t);
  for (int i = 1; i <= n; ++i) f[i][0] = f[i - 1][0] + td;
  for (int i = 1; i <= m; ++i) f[0][i] = f[0][i - 1] + ti;
  for (int i = 1; i <= n; ++i) {
    memset(pre[1], 0, sizeof(pre[1]));
    for (int j = 1; j <= m; ++j) {
      f[i][j] = min(min(f[i][j - 1] + ti, f[i - 1][j] + td),
                    f[i - 1][j - 1] + tr * (s[i - 1] != t[j - 1]));
      int x = pre[1][s[i - 1]];
      int y = pre[0][t[j - 1]];
      if (x && y) {
        f[i][j] = min(f[i][j], f[y - 1][x - 1] + (i - y - 1) * td +
                                   (j - x - 1) * ti + te);
      }
      pre[1][t[j - 1]] = j;
    }
    pre[0][s[i - 1]] = i;
  }
  printf("%d\n", f[n][m]);
  return 0;
}
