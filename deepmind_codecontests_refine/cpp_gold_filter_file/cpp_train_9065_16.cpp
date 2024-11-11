#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
char mp[maxn][maxn];
char mp1[maxn][maxn];
int x[5][maxn][maxn];
int n, m;
bool ok() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (mp1[i][j] != mp[i][j]) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  int t;
  for (int i = 1; i <= n; i++) {
    t = 0;
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '*')
        t++;
      else
        t = 0;
      x[0][i][j] = t;
    }
  }
  for (int i = 1; i <= n; i++) {
    t = 0;
    for (int j = m; j >= 1; j--) {
      if (mp[i][j] == '*')
        t++;
      else
        t = 0;
      x[1][i][j] = t;
    }
  }
  for (int i = 1; i <= m; i++) {
    t = 0;
    for (int j = 1; j <= n; j++) {
      if (mp[j][i] == '*')
        t++;
      else
        t = 0;
      x[2][j][i] = t;
    }
  }
  for (int i = 1; i <= m; i++) {
    t = 0;
    for (int j = n; j >= 1; j--) {
      if (mp[j][i] == '*')
        t++;
      else
        t = 0;
      x[3][j][i] = t;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      x[0][i][j] =
          min(x[0][i][j], min(x[1][i][j], min(x[2][i][j], x[3][i][j])));
      if (x[0][i][j] > 1) ans++;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) mp1[i][j] = '.';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (x[0][i][j] > 1) {
        int xx = i, yy = j;
        mp1[xx][yy] = '*';
        int k = yy + x[0][i][j] - 1;
        while (yy <= k) mp1[i][yy] = '*', yy++;
        yy = j;
        k = yy - (x[0][i][j] - 1);
        while (yy >= k) mp1[i][yy] = '*', yy--;
        k = xx + x[0][i][j] - 1;
        while (xx <= k) mp1[xx][j] = '*', xx++;
        xx = i;
        k = xx - (x[0][i][j] - 1);
        while (xx >= k) mp1[xx][j] = '*', xx--;
      }
  if (!ok())
    cout << -1;
  else {
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (x[0][i][j] > 1)
          cout << i << " " << j << " " << x[0][i][j] - 1 << endl;
  }
  return 0;
}
