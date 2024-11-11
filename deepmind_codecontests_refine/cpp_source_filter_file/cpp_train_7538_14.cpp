#include <bits/stdc++.h>
using namespace std;
int n, m;
int bian[600][600];
int in[600], out[600];
int match[550];
int vis[550];
int ans;
bool solve(int x, int i) {
  for (int j = 1; j < n; j++) {
    if (x == j) continue;
    if (vis[j] == 1) continue;
    if (bian[i][j] == 0) continue;
    vis[j] = 1;
    if (match[j] == -1 || solve(x, match[j]) == true) {
      match[j] = i;
      return true;
    }
  }
  return false;
}
int f(int x) {
  int ans = 0;
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    memset(vis, 0, sizeof(vis));
    if (solve(x, i) == true) ans++;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  ans = 1e9;
  int x, y;
  for (int w = 1; w <= m; w++) {
    scanf("%d%d", &x, &y);
    bian[x][y] = 1;
    out[x]++;
    in[y]++;
  }
  for (int i = 1; i <= n; i++) {
    int ibian = in[i] + out[i] - bian[i][i];
    int sum = 2 * (n - 1) + 1 - ibian;
    int num = f(i);
    int j = m - ibian;
    sum += j - num;
    sum += n - 1 - num;
    ans = min(ans, sum);
  }
  printf("%d\n", ans);
  return 0;
}
