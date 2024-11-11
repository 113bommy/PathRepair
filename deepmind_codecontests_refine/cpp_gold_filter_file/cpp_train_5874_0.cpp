#include <bits/stdc++.h>
using namespace std;
long long int a[1010][1010];
long long int dp[1010][1010];
long long int v[1010][1010];
long long int n, m;
long long int f;
long long int dx[4] = {0, 1, 0, -1};
long long int dy[4] = {1, 0, -1, 0};
void dfs(long long int x, long long int y) {
  if (dp[x][y] != -1) {
    return;
  }
  v[x][y] = 1;
  dp[x][y] = 1;
  for (long long int i = 0; i < 4; i++) {
    long long int xx = x + dx[i];
    long long int yy = y + dy[i];
    if (xx <= 0 || xx > n || yy <= 0 || yy > m ||
        a[xx][yy] != (1 + a[x][y]) % 4) {
      continue;
    }
    if (v[xx][yy]) {
      f = 1;
      return;
    }
    dfs(xx, yy);
    if (f) {
      return;
    }
    dp[x][y] = max(dp[x][y], 1 + dp[xx][yy]);
  }
  v[x][y] = 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == 'D') a[i][j] = 0;
      if (c == 'I') a[i][j] = 1;
      if (c == 'M') a[i][j] = 2;
      if (c == 'A') a[i][j] = 3;
    }
  }
  memset(dp, -1, sizeof(dp));
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (dp[i][j] == -1) {
        dfs(i, j);
      }
      if (f) {
        cout << "Poor Inna!" << endl;
        return 0;
      }
    }
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (!a[i][j]) {
        ans = max(ans, dp[i][j] / 4);
      }
    }
  }
  if (!ans) {
    cout << "Poor Dima!" << endl;
  } else {
    cout << ans << endl;
  }
}
