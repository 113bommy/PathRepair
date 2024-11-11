#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m, x, y;
bool vis[505][505];
char a[100005];
int main() {
  scanf("%d %d %d %d", &n, &m, &x, &y);
  scanf("%s", a);
  int len = strlen(a);
  for (i = 0; i < len - 1; i++) {
    printf("%d ", !vis[x][y]);
    vis[x][y] = 1;
    if (a[i] == 'U') x--;
    if (a[i] == 'D') x++;
    if (a[i] == 'L') y--;
    if (a[i] == 'R') y++;
    x = min(x, n), x = max(1, x);
    y = min(y, m), y = max(1, y);
  }
  int ans = n * m;
  for (i = 1; i <= n; i++)
    for (i0 = 1; i0 <= m; i0++) ans -= vis[i][i0];
  printf("%d\n", ans);
  return 0;
}
