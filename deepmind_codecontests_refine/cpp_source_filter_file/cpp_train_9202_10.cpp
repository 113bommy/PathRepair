#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int m;
int x, y, ans;
int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};
int b[4][100005], dp[100005][(1 << 3)], nxt[100005];
char a[4][10005];
bool vis[1 << 4];
bool inside(int x, int y) {
  if (0 <= x && x <= 2 && 1 <= y && y <= m) return 1;
  return 0;
}
int init(int s) {
  memset(nxt, 0, sizeof(nxt));
  for (int i = 0; i <= 2; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.')
        b[i][j] = 0;
      else
        b[i][j] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (s & (1 << i)) {
      int tx = x + dx[i] * 2;
      int ty = y + dy[i] * 2;
      if (inside(tx, ty) == 0)
        s = s - (1 << i);
      else if (b[x + dx[i]][y + dy[i]] == 1 ||
               b[x + dx[i] * 2][y + dy[i] * 2] == 1)
        s = s - (1 << i);
      else {
        for (int j = 1; j <= 2; j++) b[x + dx[i] * j][y + dy[i] * j] = 1;
      }
    }
  }
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= 2; j++)
      if (b[j][i]) nxt[i] = nxt[i] | (1 << j);
  return s;
}
int solve() {
  memset(dp, 0, sizeof(dp));
  dp[1][nxt[1]] = 1;
  if ((nxt[1] & (1 << 0)) == 0 && (nxt[1] & (1 << 1)) == 0)
    dp[1][nxt[1] | 3] = 1;
  if ((nxt[1] & (1 << 1)) == 0 && (nxt[1] * (1 << 2)) == 0)
    dp[1][nxt[1] | 6] = 1;
  for (int i = 2; i <= m; i++) {
    for (int j = nxt[i - 1]; j < (1 << 3); j = (j + 1) | nxt[i - 1]) {
      if ((j ^ 7) & nxt[i]) continue;
      dp[i][(j ^ 7) | nxt[i]] = (dp[i][(j ^ 7) | nxt[i]] + dp[i - 1][j]) % mod;
    }
    if ((nxt[i] & (1 << 0)) == 0 && (nxt[i] & (1 << 1)) == 0) {
      dp[i][3] = (dp[i][3] + dp[i][0]) % mod;
      dp[i][7] = (dp[i][7] + dp[i][4]) % mod;
    }
    if ((nxt[i] & (1 << 1)) == 0 && (nxt[i] & (1 << 2)) == 0) {
      dp[i][6] = (dp[i][6] + dp[i][0]) % mod;
      dp[i][7] = (dp[i][7] + dp[i][1]) % mod;
    }
  }
  return dp[m][7];
}
int count_two(int val) {
  int ret = 0;
  while (val) {
    ret = ret + (val & 1);
    val >>= 1;
  }
  return ret;
}
int main() {
  cin >> m;
  for (int i = 0; i <= 2; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'O') {
        x = i;
        y = j;
      }
    }
  for (int i = 1; i < (1 << 4); i++) {
    int now = init(i);
    if (vis[now] || now == 0) continue;
    ans = (ans + solve() * (count_two(now) % 2 ? 1 : -1)) % mod;
    vis[now] = 1;
  }
  cout << (ans + mod) % mod;
  return 0;
}
