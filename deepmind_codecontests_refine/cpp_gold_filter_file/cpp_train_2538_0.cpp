#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const int mod = 1e9 + 7;
int n, m, k, ans;
int a[N][N], bad[N][N][N], res[N][N], ma[N];
void dfs(int x, int y, int maxc) {
  if (x == n) {
    for (int i = 1; i <= maxc; i++)
      for (int j = i + 1; j <= maxc; j++)
        if (ma[i] && ma[j] && ma[i] == ma[j]) return;
    int sq = 0, co = k;
    for (int i = 1; i <= maxc; i++)
      if (!ma[i])
        sq++;
      else
        co--;
    int A = 1;
    for (int i = 1; i <= sq; i++) A *= co, co--;
    ans += A;
    if (ans >= mod) ans -= mod;
    return;
  }
  for (int i = 1; i <= min(k, maxc + 1); i++) {
    if (bad[x][y][i]) continue;
    for (int x2 = x; x2 < n; x2++)
      for (int y2 = y; y2 < m; y2++) bad[x2][y2][i]++;
    res[x][y] = i;
    if (!(a[x][y] && ma[i] && ma[i] != a[x][y])) {
      bool flg = 0;
      if (!ma[i]) {
        ma[i] = a[x][y];
        flg = 1;
      }
      int newc = max(i, maxc);
      if (y < m - 1)
        dfs(x, y + 1, newc);
      else
        dfs(x + 1, 0, newc);
      if (flg) ma[i] = 0;
    }
    for (int x2 = x; x2 < n; x2++)
      for (int y2 = y; y2 < m; y2++) bad[x2][y2][i]--;
  }
}
int main() {
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  dfs(0, 0, 0);
  cout << ans;
  return 0;
}
