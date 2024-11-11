#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int fh = 1;
  char ch = 1;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
const int maxn = 100000 + 7;
const int maxm = 200000 + 7;
const int INF = 0x3f3f3f3f;
int n, m, d, dp[maxn], dp2[maxn];
bool mark[maxn];
int Head[maxn], Next[maxm], to[maxm], tot;
void addedge(int x, int y) {
  to[++tot] = y, Next[tot] = Head[x], Head[x] = tot;
}
void add(int x, int y) {
  addedge(x, y);
  addedge(y, x);
}
void Init(void) {
  read(n);
  read(m);
  read(d);
  for (int i = 1, x; i <= m; i++) {
    read(x);
    mark[x] = true;
  }
  for (int i = 1, x, y; i < n; i++) {
    read(x);
    read(y);
    add(x, y);
  }
}
void dfs(int x, int fa) {
  dp[x] = dp2[x] = INF;
  for (int i = Head[x]; i; i = Next[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);
    if (dp[y] != INF) {
      if (dp[x] == INF)
        dp[x] = dp[y] + 1;
      else {
        if (dp[y] + 1 > dp[x]) {
          dp2[x] = dp[x];
          dp[x] = dp[y] + 1;
        } else if (dp2[x] == INF)
          dp2[x] = dp[y] + 1;
        else
          dp2[x] = max(dp2[x], dp[y] + 1);
      }
    }
  }
  if (dp[x] == INF)
    if (mark[x]) dp[x] = 0;
}
int ans;
void dfs2(int x, int fa, int mov) {
  if (mov == INF && mark[fa]) mov = 1;
  if ((dp[x] <= d || dp[x] == INF) && (mov <= d || mov == INF)) {
    ++ans;
  }
  for (int i = Head[x]; i; i = Next[i]) {
    int y = to[i];
    if (y == fa) continue;
    if (dp[x] == dp[y] + 1) {
      if (mov == INF && dp2[x] != INF)
        dfs2(y, x, dp2[x] + 1);
      else if (mov != INF && dp2[x] == INF)
        dfs2(y, x, mov + 1);
      else if (mov == INF && dp2[x] == INF)
        dfs2(y, x, INF);
      else
        dfs2(y, x, max(dp2[x], mov) + 1);
    } else {
      if (mov == INF && dp[x] != INF)
        dfs2(y, x, dp[x] + 1);
      else if (mov != INF && dp[x] == INF)
        dfs2(y, x, mov + 1);
      else if (mov == INF && dp[x] == INF)
        dfs2(y, x, INF);
      else
        dfs2(y, x, max(dp[x], mov) + 1);
    }
  }
}
void Work(void) {
  dfs(1, 0);
  dfs2(1, 0, INF);
  printf("%d\n", ans);
}
int main(void) {
  Init();
  Work();
  return 0;
}
