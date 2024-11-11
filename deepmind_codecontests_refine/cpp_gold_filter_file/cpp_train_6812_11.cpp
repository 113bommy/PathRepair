#include <bits/stdc++.h>
using namespace std;
void solutionD();
int main() {
  ios_base::sync_with_stdio(false);
  solutionD();
  return EXIT_SUCCESS;
}
long long n, m, k, dp[128][128][16], u[128][128][16], a[128][128];
pair<pair<long long, long long>, long long> p[128][128][16];
void solve() {
  memset(dp, 0, sizeof(long long) * 128 * 128 * 16);
  memset(u, 0, sizeof(long long) * 128 * 128 * 16);
  for (long long j = 0; j < m; ++j) {
    dp[0][j][a[0][j] % (k + 1)] = a[0][j];
    u[0][j][a[0][j] % (k + 1)] = 1;
  }
  for (long long i = 0; i < n - 1; ++i) {
    for (long long j = 0; j < m; ++j)
      for (long long r = 0; r < k + 1; ++r) {
        if (!u[i][j][r]) continue;
        long long nx = i + 1;
        for (long long ny = j - 1; ny <= j + 1; ny += 2) {
          if (ny < 0 || ny >= m) continue;
          long long r2 = (dp[i][j][r] + a[nx][ny]) % (k + 1);
          if (dp[nx][ny][r2] <= dp[i][j][r] + a[nx][ny]) {
            dp[nx][ny][r2] = dp[i][j][r] + a[nx][ny];
            p[nx][ny][r2] = make_pair(make_pair(i, j), r);
          }
          u[nx][ny][r2] = 1;
        }
      }
  }
  long long ans = -1;
  for (long long j = 0; j < m; ++j)
    if (u[n - 1][j][0]) ans = max(ans, dp[n - 1][j][0]);
  cout << ans << endl;
  if (ans == -1) return;
  pair<pair<long long, long long>, long long> v;
  for (long long j = 0; j < m; ++j)
    if (u[n - 1][j][0] && dp[n - 1][j][0] == ans) {
      v.first.first = n - 1;
      v.first.second = j;
      v.second = 0;
      break;
    }
  string c;
  while (v.first.first != 0) {
    pair<pair<long long, long long>, long long> to =
        p[v.first.first][v.first.second][v.second];
    if (v.first.second < to.first.second)
      c += "L";
    else
      c += "R";
    v = to;
  }
  reverse(c.begin(), c.end());
  cout << v.first.second + 1 << endl;
  cout << c << endl;
}
void solutionD() {
  for (; cin >> n >> m >> k;) {
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        a[n - i - 1][j] = ch - '0';
      }
    solve();
    cerr << endl;
  }
}
