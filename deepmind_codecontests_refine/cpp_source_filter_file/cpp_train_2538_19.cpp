#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, k;
int ans;
int a[15][15], res[15][15];
int vis[15][15][15];
int mp[15];
void dfs(int x, int y, int mi) {
  if (y == m)
    dfs(x + 1, 0, mi);
  else if (x == n) {
    for (int i = 1; i <= k; i++)
      for (int j = i + 1; j <= k; j++)
        if (mp[i] != 0 && mp[j] != 0 && mp[i] == mp[j]) return;
    int mx = k, xs = 0;
    for (int i = 1; i <= k; i++)
      if (mp[i] != 0)
        mx--;
      else
        xs++;
    int p = 1;
    for (int i = 0; i < xs; i++) {
      p *= mx;
      mx--;
    }
    ans = (ans + p) % MOD;
  } else {
    for (int i = 1; i <= min((mi + 1), k); i++) {
      if (vis[x][y][i]) continue;
      if (a[x][y] != 0 && mp[i] != 0 && mp[i] != a[x][y]) continue;
      for (int xx = x; xx < n; xx++)
        for (int yy = y; yy < m; yy++) vis[xx][yy][i]++;
      res[x][y] = i;
      bool f = false;
      if (a[x][y] != 0) {
        mp[i] = a[x][y];
        f = true;
      }
      dfs(x, y + 1, max(mi, i));
      for (int xx = x; xx < n; xx++)
        for (int yy = y; yy < m; yy++) vis[xx][yy][i]--;
      if (f) mp[i] = 0;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  dfs(0, 0, 0);
  cout << ans;
  return 0;
}
