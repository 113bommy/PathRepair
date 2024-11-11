#include <bits/stdc++.h>
const int MAXN = 501;
const int MAXL = 1001;
const int mod = 1000000007;
int n, m, pos[MAXN][MAXN], dp[2][MAXN][MAXN], cnt[MAXL];
std::pair<int, int> whe[MAXL][MAXL];
char s[MAXN][MAXN];
void update(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
bool check(int uX, int uY, int dX, int dY) {
  if (uX < 1 || uX > n) return false;
  if (uY < 1 || uY > m) return false;
  if (dX < 1 || dX > n) return false;
  if (dY < 1 || dY > m) return false;
  return s[uX][uY] == s[dX][dY];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 0; i <= n + m - 2; i++) {
    for (int j = 1; j <= i + 1; j++) {
      int x = j, y = i - j + 2;
      if (1 <= x && x <= n && 1 <= y && y <= m) {
        pos[x][y] = ++cnt[i];
        whe[i][cnt[i]] = std::make_pair(x, y);
      }
    }
  }
  dp[0][pos[1][1]][pos[n][m]] = (s[1][1] == s[n][m]);
  int s = (n + m - 2) >> 1;
  for (int i = 0; i < s; i++) {
    for (int j = 1; j <= cnt[i + 1]; j++)
      for (int k = 1; k <= cnt[n + m - 2 - (i + 1)]; k++) {
        dp[(i + 1) & 1][j][k] = 0;
      }
    for (int j = 1; j <= cnt[i]; j++)
      for (int k = 1; k <= cnt[n + m - 2 - i]; k++) {
        if (!dp[i & 1][j][k]) continue;
        std::pair<int, int> A = whe[i][j];
        std::pair<int, int> B = whe[n + m - 2 - i][k];
        if (check(A.first + 1, A.second, B.first - 1, B.second)) {
          update(dp[(i + 1) & 1][pos[A.first + 1][A.second]]
                   [pos[B.first - 1][B.second]],
                 dp[i & 1][j][k]);
        }
        if (check(A.first + 1, A.second, B.first, B.second - 1)) {
          update(dp[(i + 1) & 1][pos[A.first + 1][A.second]]
                   [pos[B.first][B.second - 1]],
                 dp[i & 1][j][k]);
        }
        if (check(A.first, A.second + 1, B.first - 1, B.second)) {
          update(dp[(i + 1) & 1][pos[A.first][A.second + 1]]
                   [pos[B.first - 1][B.second]],
                 dp[i & 1][j][k]);
        }
        if (check(A.first, A.second + 1, B.first, B.second - 1)) {
          update(dp[(i + 1) & 1][pos[A.first][A.second + 1]]
                   [pos[B.first][B.second - 1]],
                 dp[i & 1][j][k]);
        }
      }
  }
  int ans = 0;
  if ((n + m - 1) & 1) {
    for (int i = 1; i <= cnt[s]; i++) {
      update(ans, dp[s & 1][i][i]);
    }
  } else {
    for (int i = 1; i <= cnt[s]; i++) {
      std::pair<int, int> A = whe[s][i];
      if (A.first + 1 <= n) {
        update(ans, dp[s & 1][i][pos[A.first + 1][A.second]]);
      }
      if (A.second + 1 <= m) {
        update(ans, dp[s & 1][i][pos[A.first][A.second]]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
