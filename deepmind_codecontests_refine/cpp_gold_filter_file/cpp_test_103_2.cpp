#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, m, cnt;
int ans1, ans2, ans;
int dist[maxn][maxn], tim[maxn][maxn];
int a[maxn][maxn];
int cl = 0, cr = 0;
inline void dfs(int x, int y) {
  tim[x][y] = ++cnt;
  int x1 = x, y1 = y;
  if (a[x][y] == 1) {
    ++y1;
  }
  if (a[x][y] == 2) --y1;
  if (a[x][y] == 3) --x1;
  if (a[x][y] == 4) ++x1;
  if (x1 < 1 || y1 < 1 || x1 > n || y1 > m) {
    dist[x][y] = 1;
  } else if (tim[x1][y1]) {
    if (dist[x1][y1] == 0) {
      int cyc = tim[x][y] - tim[x1][y1] + 1;
      cl = tim[x1][y1];
      cr = tim[x][y];
      dist[x][y] = cyc;
    } else {
      dist[x][y] = 1 + abs(dist[x1][y1]);
    }
  } else {
    dfs(x1, y1);
    if (tim[x][y] >= cl && tim[x][y] <= cr) {
      dist[x][y] = dist[x1][y1];
    } else {
      dist[x][y] = 1 + abs(dist[x1][y1]);
    }
  }
  if (dist[x][y] > ans) {
    ans = dist[x][y];
    ans1 = x, ans2 = y;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cl = 0, cr = 0;
    ans1 = ans2 = ans = 0;
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j) {
        int xx = 0;
        if (s[j] == 'R')
          xx = 1;
        else if (s[j] == 'L')
          xx = 2;
        else if (s[j] == 'U')
          xx = 3;
        else
          xx = 4;
        a[i][j + 1] = xx;
      }
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (tim[i][j]) continue;
        dfs(i, j);
      }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans << '\n';
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) dist[i][j] = tim[i][j] = 0;
  }
}
