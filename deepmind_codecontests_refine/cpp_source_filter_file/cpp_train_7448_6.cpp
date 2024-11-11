#include <bits/stdc++.h>
using namespace std;
char use[105][105];
char aim;
int maxx = -1, maxy = -1, minx = 1000, miny = 1000;
int main() {
  int n, m;
  cin >> n >> m >> aim;
  for (int i = 1; i <= n; i++) cin >> (use[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (use[i][j] == aim) {
        maxx = max(i, maxx);
        maxy = max(j, maxy);
        minx = min(i, minx);
        miny = min(j, miny);
      }
    }
  int ans = 0;
  int vis[30];
  memset(vis, 0, sizeof(vis));
  if (minx > 1) {
    for (int i = miny; i <= maxy; i++) {
      if (use[minx - 1][i] != '.' && vis[use[minx - 1][i] - 'A'] == 0) {
        ans++;
        vis[use[minx - 1][i] - 'A'] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  if (maxx < n) {
    for (int i = miny; i <= maxy; i++) {
      if (use[maxx + 1][i] != '.' && vis[use[maxx + 1][i] - 'A'] == 0) {
        ans++;
        vis[use[maxx + 1][i] - 'A'] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  if (miny > 1) {
    for (int i = minx; i <= maxx; i++) {
      if (use[i][miny - 1] != '.' && vis[use[i][miny - 1] - 'A'] == 0) {
        ans++;
        vis[use[i][miny - 1] - 'A'] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  if (maxy < m) {
    for (int i = minx; i <= maxx; i++) {
      if (use[i][maxy + 1] != '.' && vis[use[i][maxy + 1] - 'A'] == 0) {
        ans++;
        vis[use[i][maxy + -1] - 'A'] = 1;
      }
    }
  }
  cout << ans;
  return 0;
}
