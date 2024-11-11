#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[5005][5005];
vector<int> up[5005], dn[5005], lt[5005], rt[5005];
void del(int x, int y) {
  dn[up[x][y]][y] = dn[x][y];
  up[dn[x][y]][y] = up[x][y];
  rt[x][lt[x][y]] = rt[x][y];
  lt[x][rt[x][y]] = lt[x][y];
}
void ins(int x, int y) {
  dn[up[x][y]][y] = x;
  up[dn[x][y]][y] = x;
  rt[x][lt[x][y]] = y;
  lt[x][rt[x][y]] = y;
}
int dfs(int x, int y) {
  int ans = 1;
  if (s[x][y] == 'U') {
    int cur = up[x][y];
    if (cur) del(x, y), ans += dfs(cur, y), ins(x, y);
  } else if (s[x][y] == 'D') {
    int cur = dn[x][y];
    if (cur != n + 1) del(x, y), ans += dfs(cur, y), ins(x, y);
  } else if (s[x][y] == 'L') {
    int cur = lt[x][y];
    if (cur) del(x, y), ans += dfs(x, cur), ins(x, y);
  } else if (s[x][y] == 'R') {
    int cur = rt[x][y];
    if (cur != m + 1) del(x, y), ans += dfs(x, cur), ins(x, y);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 0; i <= n + 1; i++)
    up[i].resize(m + 3), dn[i].resize(m + 3), lt[i].resize(m + 3),
        rt[i].resize(m + 3);
  for (int i = 1; i <= n; i++) {
    int pre = 0;
    for (int j = 1; j <= m; j++)
      if (s[i][j] != '.') rt[i][pre] = j, lt[i][j] = pre, pre = j;
    rt[i][pre] = m + 1;
    lt[i][m + 1] = pre;
  }
  for (int j = 1; j <= m; j++) {
    int pre = 0;
    for (int i = 1; i <= n; i++)
      if (s[i][j] != '.') dn[pre][j] = i, up[i][j] = pre, pre = i;
    dn[pre][j] = n + 1;
    up[n + 1][j] = pre;
  }
  int ans = 0, mx = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] != '.') {
        int cur = dfs(i, j);
        if (cur > mx)
          mx = cur, ans = 1;
        else if (cur == mx)
          ans++;
      }
  printf("%d %d\n", mx, ans);
  return 0;
}
