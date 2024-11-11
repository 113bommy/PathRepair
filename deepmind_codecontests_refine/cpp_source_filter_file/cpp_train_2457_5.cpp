#include <bits/stdc++.h>
using namespace std;
vector<int> g[5002];
int a[5002];
int i, j, tot, ans, n;
int DP[5002][5002];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    int tot = 0;
    for (j = i + 1; j <= n && tot < 2; j++)
      if (a[i] % 7 == a[j] % 7) {
        tot++;
        g[i].push_back(j);
      }
    tot = 0;
    for (j = i + 1; j <= n && tot < 2; j++)
      if (a[i] == a[j] + 1) {
        tot++;
        g[i].push_back(j);
      }
    tot = 0;
    for (j = i + 1; j <= n && tot < 2; j++)
      if (a[i] == a[j] - 1) {
        tot++;
        g[i].push_back(j);
      }
  }
  for (i = 1; i <= n; i++) g[0].push_back(i);
  for (i = 1; i <= n; i++) DP[i][0] = 1, DP[0][i] = 1;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++)
      if (i != j) {
        for (int k = 0; k < g[i].size(); k++)
          if (g[i][k] > max(i, j))
            DP[g[i][k]][j] = max(DP[g[i][k]][j], DP[i][j] + 1);
        for (int k = 0; k < g[j].size(); k++)
          if (g[j][k] > max(i, j))
            DP[i][g[j][k]] = max(DP[i][g[j][k]], DP[i][j] + 1);
        ans = max(ans, DP[i][j]);
      }
  cout << ans << endl;
}
