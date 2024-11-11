#include <bits/stdc++.h>
using namespace std;
const int N = 517;
int n, m, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, ans[N][N];
char mp[N][N];
int fr[N * N], to[N * N * 8], nxt[N * N * 8], tails;
void add(int ff, int tt) {
  if (ff == 0 || tt == 0) return;
  to[++tails] = tt;
  nxt[tails] = fr[ff];
  fr[ff] = tails;
}
int gp(int x, int y) { return x * m + y; }
void dfs(int x, int y, int fill) {
  for (int p = fr[gp(x, y)], v, xx, yy; p; p = nxt[p]) {
    v = to[p];
    xx = (v - 1) / m, yy = (v - 1) % m + 1;
    if (ans[xx][yy]) continue;
    ans[xx][yy] = fill ^ 1 ^ 4;
    dfs(xx, yy, ans[xx][yy]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      if (mp[i][j] == '.') continue;
      int cnt = (mp[i][j - 1] == '.') + (mp[i][j + 1] == '.') +
                (mp[i - 1][j] == '.') + (mp[i + 1][j] == '.');
      if (cnt & 1) {
        printf("NO");
        return 0;
      }
      for (int dir = 0, last = 0; dir < 4; ++dir) {
        if (mp[i + dx[dir]][j + dy[dir]] == '.') {
          add(last, gp(i + dx[dir], j + dy[dir]));
          add(gp(i + dx[dir], j + dy[dir]), last);
          last = gp(i + dx[dir], j + dy[dir]);
        }
      }
    }
  }
  for (int op = m + 1, x, y; op <= n * m + m; ++op) {
    x = (op - 1) / m, y = (op - 1) % m + 1;
    if (ans[x][y] || mp[x][y] == 'X') continue;
    ans[x][y] = 1;
    dfs(x, y, 1);
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ans[i][j])
        printf("%d ", ans[i][j]);
      else if (mp[i][j] == '.') {
        ans[i][j] = 1;
        printf("%d ", ans[i][j]);
      } else {
        for (int dir = 0; dir < 4; ++dir) {
          if (mp[i + dx[dir]][j + dy[dir]] == '.')
            ans[i][j] += ans[i + dx[dir]][j + dy[dir]];
        }
        printf("%d ", ans[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
