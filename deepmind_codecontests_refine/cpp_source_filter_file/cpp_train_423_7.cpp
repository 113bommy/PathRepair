#include <bits/stdc++.h>
using namespace std;
const int N = 502;
const int big = 2e9;
const int md = 998244353;
int n, k, f[N][N], ans, dp[N][N], x;
void up(int &x, int y) { x = (x + y) % md; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) f[i][i] = 2;
  for (int i = 1; i <= n; i++)
    for (int sm = 1; sm <= i; sm++)
      for (int j = i + 1; j <= n; j++) up(f[j][max(sm, j - i)], f[i][sm]);
  for (int i = 1; i <= n; i++) {
    x = f[n][i];
    for (int j = 1; j <= n; j++)
      for (int kol = 1; kol <= j; kol++) dp[j][kol] = 0;
    dp[1][1] = x;
    for (int j = 1; j <= n; j++) {
      for (int kol = 1; kol <= j; kol++) {
        if ((kol + 1) * i <= k) up(dp[j + 1][kol + 1], dp[j][kol]);
        up(dp[j + 1][1], dp[j][kol]);
      }
    }
    for (int kol = 1; kol <= n; kol++)
      if (kol * i <= k) up(ans, dp[n][kol]);
  }
  cout << ans;
  return 0;
}
