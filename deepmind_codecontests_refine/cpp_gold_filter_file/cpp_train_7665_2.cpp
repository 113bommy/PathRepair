#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e6 + 10;
struct bkn {
  int next, to;
} e[maxn * 2];
int tot = 1, head[maxn], vis[maxn], ins[maxn], cnt;
int q[maxn];
void add(int x, int y) {
  e[tot].to = y, e[tot].next = head[x], head[x] = tot++;
}
bool dfs(int x) {
  vis[x] = 1;
  int ans = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (!vis[y])
      ans = min(ans, (int)dfs(y));
    else if (!ins[y])
      return 0;
  }
  q[++cnt] = x;
  ins[x] = 1;
  return ans;
}
char s[300300];
int dp[300300][30];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  int ok = 1;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (!dfs(i)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = cnt; i >= 1; i--) {
    int x = q[i];
    int cc = (int)s[x - 1];
    for (int i = 'a' - 97; i <= 'z' - 97; i++)
      dp[x][i] = max(dp[x][i], cc == i + 97 ? 1 : 0), ans = max(ans, dp[x][i]);
    for (int i = head[x]; i; i = e[i].next) {
      int y = e[i].to;
      int dd = (int)s[y - 1];
      for (int j = 'a' - 97; j <= 'z' - 97; j++) {
        dp[y][j] = max(dp[y][j], dp[x][j] + (dd == j + 97 ? 1 : 0));
      }
    }
  }
  cout << ans << endl;
}
