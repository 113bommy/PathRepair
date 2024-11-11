#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int Mod = 1e9 + 7;
const long long OO = 1e18;
const int N = 2e3 + 5;
int n, m, dp[N][N];
char a[N][N];
int kt(int i, int j) {
  return a[i][j] == a[i - 1][j] && a[i][j] == a[i - 1][j - 1] &&
         a[i][j] == a[i - 1][j + 1] && a[i][j] == a[i - 2][j];
}
void in() {
  cin >> n >> m;
  int ans = 0;
  for (int i = 2; i <= n + 1; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  n++;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (kt(i, j))
        dp[i][j] = min({dp[i - 1][j], dp[i - 1][j + 1], dp[i - 1][j - 1],
                        dp[i - 2][j]}) +
                   1;
      else
        dp[i][j] = 1;
      ans += dp[i][j];
    }
  cout << ans;
}
void solve() {}
void file() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  in();
}
