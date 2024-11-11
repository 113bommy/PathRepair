#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long maxn = 1e5 + 7;
long long hx[4] = {1, 0, -1, 0};
long long hy[4] = {0, 1, 0, -1};
long long n, m, d[57][57], turn;
char a[57][57];
bool check;
void dfs(long long x, long long y, long long u, long long v) {
  d[x][y] = turn;
  for (long long i = 0; i < 4; i++) {
    long long xx = x + hx[i];
    long long yy = y + hy[i];
    if (d[xx][yy] == turn && xx != u && yy != v) {
      check = 1;
    }
    if (d[xx][yy] == 0 && a[xx][yy] == a[x][y]) {
      dfs(xx, yy, x, y);
    }
  }
}
void solve() {
  check = 0;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (!d[i][j]) {
        turn++;
        dfs(i, j, 0, 0);
      }
    }
  }
  if (check == 1)
    cout << "YES";
  else
    cout << "NO";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
