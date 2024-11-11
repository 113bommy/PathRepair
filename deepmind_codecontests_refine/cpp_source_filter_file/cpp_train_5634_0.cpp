#include <bits/stdc++.h>
using namespace std;
bool vis[1010][1010], val[1010][1010];
int n, m, a, l, r, ans;
const int dx[9] = {0, 1, 2, 0, 0, 1, 2, 2};
const int dy[9] = {0, 0, 0, 1, 2, 2, 1, 2};
inline void work(int x, int y) {
  for (register int i = 0; i < 8; ++i)
    if (!val[x + dx[i]][y + dy[i]]) return;
  for (register int i = 0; i < 8; ++i) vis[x + dx[i]][y + dy[i]] = 1;
}
inline bool check() {
  for (register int i = 1; i <= n - 2; ++i)
    for (register int j = 1; j <= m - 2; ++j)
      if (val[i][j]) work(i, j);
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j)
      if (val[i][j] && (!vis[i][j])) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  char c = getchar();
  while (c != '#' && c != '.') c = getchar();
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= m; ++j) {
      val[i][j] = (c == '#');
      if (i != n || j != m) {
        c = getchar();
        while (c != '#' && c != '.') c = getchar();
      }
    }
  puts(check() ? "YES" : "NO");
  return 0;
}
