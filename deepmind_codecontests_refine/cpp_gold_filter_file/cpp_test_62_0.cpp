#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void time_taken() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 1004;
int dp[N][N][2];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int> > a(n, vector<int>(m));
  memset(dp, 0, sizeof(dp));
  dp[n - 1][m - 1][1] = 1;
  dp[n - 1][m - 1][0] = 1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      dp[i][j][0] = 1;
      if (j + 1 < m) dp[i][j][0] += dp[i][j + 1][1];
      dp[i][j][1] = 1;
      if (i + 1 < n) dp[i][j][1] += dp[i + 1][j][0];
      ans += (dp[i][j][0] + dp[i][j][1] - 1);
    }
  };
  auto upd = [&](int r, int c, int delta) {
    if (delta == 0) return;
    ans += delta;
    dp[r][c][0] += delta;
    r--;
    while (r >= 0 and c >= 0) {
      if (a[r][c] == 1) return;
      dp[r][c][1] += delta;
      ans += delta;
      if (c) {
        if (a[r][c - 1] == 1) return;
        dp[r][c - 1][0] += delta;
        ans += delta;
      }
      c--;
      r--;
    }
  };
  while (q--) {
    int r, c;
    cin >> r >> c, --r, --c;
    a[r][c] ^= 1;
    int delta = 0;
    if (a[r][c] == 1) {
      delta -= 1;
      if (c + 1 < m) delta -= dp[r][c + 1][1];
    } else {
      delta += 1;
      if (c + 1 < m) delta += dp[r][c + 1][1];
    }
    upd(r, c, delta);
    delta = 0;
    if (a[r][c] == 1) {
      delta -= 1;
      if (r + 1 < n) delta -= dp[r + 1][c][0];
    } else {
      delta += 1;
      if (r + 1 < n) delta += dp[r + 1][c][0];
    }
    dp[r][c][1] += delta;
    ans += delta;
    if (c > 0 and a[r][c - 1] == 0) {
      upd(r, c - 1, delta);
    }
    if (a[r][c] == 1) {
      ans++;
    } else
      ans--;
    cout << ans << '\n';
  }
  time_taken();
  return 0;
}
