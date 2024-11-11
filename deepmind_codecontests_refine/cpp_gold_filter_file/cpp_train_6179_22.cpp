#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
int n, m, a[maxn][maxn], x, y;
bool vis[maxn];
int ans;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    a[x][y] = i;
  }
  ans = m + 1;
  int now;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      now = 0;
      if (a[i - 1][j - 1] && a[i - 1][j] && a[i - 1][j + 1] && a[i][j - 1] &&
          a[i][j] && a[i][j + 1] && a[i + 1][j - 1] && a[i + 1][j] &&
          a[i + 1][j + 1]) {
        now = max(now, a[i - 1][j - 1]);
        now = max(now, a[i - 1][j]);
        now = max(now, a[i - 1][j + 1]);
        now = max(now, a[i][j - 1]);
        now = max(now, a[i][j]);
        now = max(now, a[i][j + 1]);
        now = max(now, a[i + 1][j - 1]);
        now = max(now, a[i + 1][j]);
        now = max(now, a[i + 1][j + 1]);
        ans = min(now, ans);
      }
    }
  }
  if (ans == m + 1)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}
