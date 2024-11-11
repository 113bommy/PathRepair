#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int a[N][N], u[N], f[N][N], l[1 << 12];
int n, m, k;
int mo = 1e9 + 7;
int dfs(int x, int y) {
  if (y > m) x++, y = 1;
  if (x > n) return 1;
  int v = f[x - 1][y] | f[x][y - 1], ans = 0, t = -1;
  for (int i = ((~v) & ((1 << k) - 1)); i; i -= (i & -i)) {
    int c = l[i & -i];
    if (a[x][y] == c || !a[x][y]) {
      u[c]++;
      f[x][y] = v | (i & -i);
      if (u[c] == 1) {
        if (t == -1) t = dfs(x, y + 1);
        ans = (ans + t) % mo;
      } else
        ans = (ans + dfs(x, y + 1)) % mo;
      u[c]--;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      u[a[i][j]]++;
    }
  for (int i = 1; i <= k; i++) l[1 << i] = i;
  printf("%d", dfs(1, 1));
}
