#include <bits/stdc++.h>
using namespace std;
long long n, m, q, a[45][45];
long long s[45][45], ans[45][45][45][45];
signed main() {
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch - '0';
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  for (long long sx = 1; sx <= n; sx++)
    for (long long sy = 1; sy <= m; sy++)
      for (long long tx = sx; tx <= n; tx++)
        for (long long ty = sy; ty <= m; ty++)
          if (s[tx][ty] - s[sx - 1][ty] - s[tx][sy - 1] + s[sx - 1][sy - 1] ==
              0)
            ans[sx][sy][tx][ty] = 1;
  for (long long sx = n; sx >= 1; sx--)
    for (long long sy = m; sy >= 1; sy--)
      for (long long tx = 1; tx <= n; tx++)
        for (long long ty = 1; ty <= m; ty++)
          ans[sx][sy][tx][ty] += ans[sx + 1][sy][tx][ty];
  for (long long sx = n; sx >= 1; sx--)
    for (long long sy = m; sy >= 1; sy--)
      for (long long tx = 1; tx <= n; tx++)
        for (long long ty = 1; ty <= m; ty++)
          ans[sx][sy][tx][ty] += ans[sx][sy + 1][tx][ty];
  for (long long sx = n; sx >= 1; sx--)
    for (long long sy = m; sy >= 1; sy--)
      for (long long tx = 1; tx <= n; tx++)
        for (long long ty = 1; ty <= m; ty++)
          ans[sx][sy][tx][ty] += ans[sx][sy][tx - 1][ty];
  for (long long sx = n; sx >= 1; sx--)
    for (long long sy = m; sy >= 1; sy--)
      for (long long tx = 1; tx <= n; tx++)
        for (long long ty = 1; ty <= m; ty++)
          ans[sx][sy][tx][ty] += ans[sx][sy][tx][ty - 1];
  while (q--) {
    long long sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    cout << ans[sx][sy][tx][ty] << endl;
  }
  return 0;
}
