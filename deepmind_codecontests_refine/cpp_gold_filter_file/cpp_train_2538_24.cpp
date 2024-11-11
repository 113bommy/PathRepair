#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fff[5000];
int f[15][15], a[15][15], use[15];
int dfs(int x, int y) {
  if (y == m + 1) x++, y = 1;
  if (x == n + 1) return 1;
  int cur, ans = 0, pre = -1, tmp;
  cur = f[x - 1][y] | f[x][y - 1];
  for (int i = (~cur) & ((1 << k) - 1); i; i -= i & (-i)) {
    tmp = fff[i & (-i)];
    if (a[x][y] == 0 || a[x][y] == tmp) {
      use[tmp]++;
      f[x][y] = cur | (1 << (tmp - 1));
      if (use[tmp] == 1) {
        if (pre == -1) pre = dfs(x, y + 1);
        ans += pre;
      } else
        ans += dfs(x, y + 1);
      ans %= 1000000007;
      use[tmp]--;
    }
  }
  return ans;
}
int main() {
  int x;
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      use[a[i][j]]++;
    }
  x = 1;
  for (int i = 1; i <= k; i++) {
    fff[x] = i;
    x <<= 1;
  }
  printf("%d\n", dfs(1, 1));
  return 0;
}
