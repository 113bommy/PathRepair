#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, k;
int a[11][11];
int f[11][11];
int vis[11];
int ans;
void dfs(int x, int y) {
  if (x > n) {
    ans++;
    if (ans == mod) ans = 0;
    return;
  }
  int nx = y == m ? x + 1 : x, ny = y == m ? 1 : y + 1;
  f[x][y] = f[x][y - 1] | f[x - 1][y];
  int cnt = __builtin_popcount(f[x][y]);
  if ((n - x) * (m - y) > cnt) return;
  if (a[x][y] != -1) {
    if (!(f[x][y] & (1 << a[x][y]))) {
      f[x][y] |= 1 << a[x][y];
      dfs(nx, ny);
    }
    return;
  }
  int lst = -1;
  for (int i = 0; i < k; i++) {
    if (!(f[x][y] & (1 << i))) {
      int pre = ans;
      if (!vis[i] && lst != -1) {
        ans += lst;
        if (ans >= mod) ans -= mod;
        continue;
      }
      vis[i]++;
      f[x][y] ^= 1 << i;
      dfs(nx, ny);
      f[x][y] ^= 1 << i;
      vis[i]--;
      if (!vis[i]) {
        lst = ans - pre + mod;
        if (lst >= mod) lst -= mod;
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) return puts("0"), 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]), a[i][j]--;
      if (~a[i][j]) vis[a[i][j]]++;
    }
  dfs(1, 1);
  printf("%d", ans);
}
