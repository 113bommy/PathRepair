#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int dirx[3] = {0, 1, 0};
const int diry[3] = {0, 0, 1};
char mp[N][N];
int dp[N][N], n, k, ans[N << 1];
int maxn;
bool vis[N][N];
struct position {
  int x, y;
  int step;
};
queue<position> q;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
bool valid(int x, int y) {
  if (vis[x][y]) return false;
  if (x < 1 || x > n || y < 1 || y > n) return false;
  return true;
}
void BFS() {
  if (q.empty()) {
    q.push(position{1, 1, 1});
    ans[1] = mp[1][1] - 'a';
  }
  while (!q.empty()) {
    position cur = q.front();
    q.pop();
    int x = cur.x, y = cur.y, step = cur.step;
    if ((mp[x][y] - 'a') > ans[step] || step < maxn) continue;
    for (int i = 1; i <= 2; i++) {
      int nxtx = x + dirx[i];
      int nxty = y + diry[i];
      if (valid(nxtx, nxty)) {
        if ((mp[nxtx][nxty] - 'a') < ans[step + 1]) {
          vis[nxtx][nxty] = true;
          ans[step + 1] = mp[nxtx][nxty] - 'a';
          q.push(position{nxtx, nxty, step + 1});
        }
      }
    }
  }
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  memset(ans, 0x3f3f3f3f, sizeof(ans));
  dp[0][1] = dp[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (mp[i][j] == 'a' ? 0 : 1);
      if (dp[i][j] == k && maxn <= i + j - 1) {
        maxn = i + j - 1;
        vis[i][j] = true;
        q.push(position{i, j, i + j - 1});
      }
    }
  }
  if (dp[n][n] < k) {
    for (int i = 1; i < (n << 1); i++) printf("a");
    return 0;
  }
  BFS();
  for (int i = 1; i <= maxn; i++) printf("a");
  for (int i = maxn + 1; i < (n << 1); i++) printf("%c", ans[i] + 'a');
  return 0;
}
