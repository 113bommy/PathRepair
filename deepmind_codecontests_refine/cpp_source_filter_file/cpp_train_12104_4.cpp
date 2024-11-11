#include <bits/stdc++.h>
using namespace std;
const int maxn = 26, mod = 1e9 + 7;
const long long inf = 1e18;
string s[maxn];
int a[maxn][maxn];
int dp[maxn + 2][maxn + 2][maxn + 2][maxn + 2], arr[maxn * maxn], C;
void solve() {
  memset(dp, 0, sizeof dp);
  for (int rx = 1; rx < maxn; rx++) {
    for (int lx = rx; lx >= 1; lx--) {
      for (int ry = 1; ry < maxn; ry++) {
        for (int ly = ry; ly >= 1; ly--) {
          C = 0;
          for (int i = lx; i <= rx; i++) {
            for (int j = ly; j <= ry; j++) {
              if (a[i][j] == 0) continue;
              int val = 0;
              if (a[i][j] == 1)
                val = dp[lx][i - 1][ly][ry] ^ dp[i + 1][rx][ly][ry];
              if (a[i][j] == 2)
                val = dp[lx][rx][ly][j - 1] ^ dp[lx][rx][j + 1][ry];
              if (a[i][j] == 3)
                val = dp[lx][i - 1][ly][j - 1] ^ dp[lx][i - 1][j + 1][ry] ^
                      dp[i + 1][rx][ly][j - 1] ^ dp[i + 1][rx][j + 1][ry];
              arr[C++] = val;
            }
          }
          sort(arr, arr + C);
          C = unique(arr, arr + C) - arr;
          dp[lx][rx][ly][ry] = C;
          for (int i = 0; i < C; i++) {
            if (arr[i] != i) {
              dp[lx][rx][ly][ry] = i;
              break;
            }
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int _ = 0; _ < 2; _++) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == _) {
          int &x = a[((i + j) / 2) + 1][((i - j + m - 1) / 2) + 1];
          if (s[i][j] == 'R') x = 1;
          if (s[i][j] == 'L') x = 2;
          if (s[i][j] == 'X') x = 3;
        }
      }
    }
    solve();
    ans ^= dp[1][maxn - 1][1][maxn - 1];
  }
  return cout << (ans == 0 ? "LOSE\n" : "WIN\n"), 0;
}
