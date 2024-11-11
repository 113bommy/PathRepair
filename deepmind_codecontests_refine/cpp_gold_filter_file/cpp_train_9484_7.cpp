#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int ans[N << 1], n, k, G[N][N], dp[N][N], lim, dir[2][2] = {{0, 1}, {1, 0}};
bool vis[N][N];
struct node {
  int x, y, s;
  node() {}
  node(const int X, const int Y, const int S) { x = X, y = Y, s = S; }
};
queue<node> q;
int read() {
  int x = 0, f = 1;
  char s;
  while ((s = getchar()) > '9' || s < '0')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  return x * f;
}
void bfs() {
  if (q.empty()) {
    vis[1][1] = 1;
    q.push(node(1, 1, 1));
    ans[1] = G[1][1];
  }
  while (!q.empty()) {
    node now = q.front();
    q.pop();
    if (G[now.x][now.y] > ans[now.s] || now.s < lim) continue;
    for (int i = 0; i < 2; ++i) {
      int x = now.x + dir[i][0];
      int y = now.y + dir[i][1];
      if (x > n || y > n || vis[x][y]) continue;
      if (ans[now.s + 1] >= G[x][y]) {
        vis[x][y] = 1;
        ans[now.s + 1] = G[x][y];
        q.push(node(x, y, now.s + 1));
      }
    }
  }
}
int main() {
  memset(ans, 0x3f, sizeof ans);
  memset(dp, 0x3f, sizeof dp);
  dp[0][1] = dp[1][0] = 0;
  n = read(), scanf("%d", &k);
  for (int i = 1; i <= n; ++i) {
    getchar();
    for (int j = 1; j <= n; ++j) G[i][j] = getchar() - 'a';
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (G[i][j] == 0 ? 0 : 1);
      if (dp[i][j] == k && i + j - 1 >= lim) {
        lim = i + j - 1;
        q.push(node(i, j, lim));
        vis[i][j] = 1;
      }
    }
  }
  if (dp[n][n] <= k) {
    for (int i = 1; i <= (n << 1) - 1; ++i) putchar('a');
    putchar('\n');
    return 0;
  }
  bfs();
  for (int i = 1; i <= lim; ++i) putchar('a');
  for (int i = lim + 1; i <= (n << 1) - 1; ++i) putchar(ans[i] + 'a');
  putchar('\n');
  return 0;
}
