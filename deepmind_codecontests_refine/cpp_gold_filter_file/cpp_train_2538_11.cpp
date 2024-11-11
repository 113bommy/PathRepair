#include <bits/stdc++.h>
using namespace std;
int rk[1024], n, m, k;
int num[11], now[11][11];
int col[11][11];
int dfs(int x, int y) {
  if (y == m + 1) y = 1, x++;
  if (x > n) return 1;
  now[x][y] = now[x - 1][y] | now[x][y - 1];
  int re = ((1 << k) - 1) - now[x][y], ans = 0;
  if (col[x][y] != -1) {
    if ((1 << col[x][y]) & re) {
      num[col[x][y]]++;
      now[x][y] |= (1 << col[x][y]);
      ans = (ans + dfs(x, y + 1)) % 1000000007;
      num[col[x][y]]--;
      now[x][y] -= (1 << col[x][y]);
    }
  } else {
    for (int flag = -1, k = (re & (-re)); re; k = (re & (-re))) {
      re -= k;
      num[rk[k]]++;
      now[x][y] |= k;
      if (num[rk[k]] == 1) {
        if (flag == -1) flag = dfs(x, y + 1);
        ans = (ans + flag) % 1000000007;
      } else
        ans = (ans + dfs(x, y + 1)) % 1000000007;
      num[rk[k]]--;
      now[x][y] ^= k;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    puts("0");
    return 0;
  }
  for (int tmp = 1, i = 0; i < k; i++) rk[tmp] = i, tmp <<= 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &col[i][j]);
      col[i][j]--;
      if (col[i][j] != -1) num[col[i][j]]++;
    }
  cout << dfs(1, 1) << endl;
}
