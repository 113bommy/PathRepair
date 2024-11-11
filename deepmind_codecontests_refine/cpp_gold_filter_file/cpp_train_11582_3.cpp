#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1010;
long long a[maxn][maxn];
char mm[maxn][maxn];
bool col[maxn], row[maxn];
bool vis[maxn][maxn];
long long nv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
long long n, m;
void dfs(long long x, long long y) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (vis[x][y]) return;
  vis[x][y] = true;
  for (long long i = 0; i < 4; i++) {
    long long _x = x + nv[i][0];
    long long _y = y + nv[i][1];
    if (mm[_x][_y] == '#') {
      dfs(_x, _y);
    }
  }
}
signed main() {
  bool flag = false;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      scanf("%c", &mm[i][j]);
      while (mm[i][j] == '\n') scanf("%c", &mm[i][j]);
    }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (row[i] && mm[i][j - 1] == '.' && mm[i][j] == '#') flag = true;
      if (mm[i][j] == '#') row[i] = true;
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      if (col[i] && mm[j - 1][i] == '.' && mm[j][i] == '#') flag = true;
      if (mm[j][i] == '#') col[i] = true;
    }
  }
  for (long long i = 1; i <= n; i++) {
    bool f = false, _f = false;
    if (!row[i]) {
      _f = true;
      for (long long j = 1; j <= m; j++) {
        if (!col[j]) {
          f = true;
          break;
        }
      }
    }
    if (!f && _f) flag = true;
  }
  for (long long i = 1; i <= m; i++) {
    bool f = false, _f = false;
    if (!col[i]) {
      _f = true;
      for (long long j = 1; j <= n; j++) {
        if (!row[j]) {
          f = true;
          break;
        }
      }
    }
    if (!f && _f) flag = true;
  }
  if (flag) {
    printf("-1\n");
    return 0;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (mm[i][j] == '#' && !vis[i][j]) {
        ans++;
        dfs(i, j);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
