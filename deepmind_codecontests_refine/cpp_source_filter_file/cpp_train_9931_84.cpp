#include <bits/stdc++.h>
using namespace std;
const int me = 4;
int i, j, k, l, n, m, q[120000], ans, a[1700][1700], b[1700][1700],
    c[1700][1700], num, x, y, o;
void dfs1(int x, int y) {
  if (x < i - me || x > i + me || y < j - me || y > j + me || b[x][y] == 1)
    return;
  b[x][y] = 1;
  o++;
  dfs1(x + 1, y);
  dfs1(x - 1, y);
  dfs1(x, y + 1);
  dfs1(x, y - 1);
}
void dfs3(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || c[x][y] == 0) return;
  c[x][y] = 0;
  dfs3(x + 1, y);
  dfs3(x - 1, y);
  dfs3(x, y + 1);
  dfs3(x, y - 1);
}
void dfs2(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 0) return;
  a[x][y] = 0;
  if (c[x][y] == 1) {
    dfs3(x, y);
    num++;
  }
  dfs2(x + 1, y);
  dfs2(x - 1, y);
  dfs2(x, y + 1);
  dfs2(x, y - 1);
}
void print() {
  printf("%d %d\n", n, m);
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) printf("%d ", c[i][j]);
    puts("");
  }
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  for (i = me + 1; i <= n - me - 1; ++i)
    for (j = me + 1; j <= m - me - 1; ++j)
      if (a[i][j] == 1) {
        num = 0;
        for (x = i - me; x <= i + me; ++x)
          for (y = j - me; y <= j + me; ++y) b[x][y] = a[x][y];
        for (x = i - me; x <= i + me; ++x)
          for (y = j - me; y <= j + me; ++y)
            if (b[x][y] == 0) {
              o = 0;
              dfs1(x, y);
              if (o > 10) num++;
            }
        if (num == 2) c[i][j] = 1;
      }
  ans = 0;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (a[i][j] == 1) {
        ans++;
        num = 0;
        dfs2(i, j);
        q[ans] = num;
      }
  sort(q + 1, q + ans + 1);
  printf("%d\n", ans);
  for (i = 1; i <= ans; ++i) printf("%d ", q[i]);
}
