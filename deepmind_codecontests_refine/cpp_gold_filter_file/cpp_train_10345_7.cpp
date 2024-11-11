#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, cnt;
long long ans;
char s[101][10005];
int dfs(int x, int y, int d) {
  if (x == n - 1) return 1;
  if (s[x + 1][y] == '.') {
    l = y;
    r = y;
    ans++;
    cnt = 0;
    return dfs(x + 1, y, d);
  }
  if (s[x][y + d] == '.') {
    ans++;
    r = max(r, y + d);
    l = min(l, y + d);
    return dfs(x, y + d, d);
  } else if (s[x][y + d] == '#') {
    if (cnt > 2 * m) return 0;
    ans += 1;
    cnt++;
    if (d == 1) {
      ans += y - l;
      r = y;
      return dfs(x, l, -1);
    } else {
      ans += r - y;
      l = y;
      return dfs(x, r, 1);
    }
  } else {
    s[x][y + d] = '.';
    ans++;
    if (d == 1) {
      ans += y - l;
      r = y + 1;
      return dfs(x, l, -1);
    } else {
      ans += r - y;
      l = y - 1;
      return dfs(x, r, 1);
    }
  }
}
int main() {
  int i, j, k, t;
  while (~scanf("%d%d", &n, &m)) {
    m++;
    for (i = 0; i < n; i++) scanf("%s", s[i] + 1), s[i][0] = s[i][m] = '#';
    l = r = 1;
    ans = 0;
    j = dfs(0, 1, 1);
    if (j)
      printf("%I64d\n", ans);
    else
      puts("Never");
  }
  return 0;
}
