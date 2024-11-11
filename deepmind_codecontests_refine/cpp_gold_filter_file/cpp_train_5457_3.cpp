#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
const int MOD = 1000000007;
string mx[MAXN];
int dp[MAXN][MAXN];
int m, n;
void mainp() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> mx[i];
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
      if (j == m - 1)
        dp[i][j] = mx[i][j] == '1' ? 1 : 0;
      else {
        if (mx[i][j] == '1')
          dp[i][j] = 1 + dp[i][j + 1];
        else
          dp[i][j] = 0;
      }
    }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    int temp[MAXN];
    for (int i = 0; i < n; i++) temp[i] = dp[i][j];
    sort(temp, temp + n);
    for (int i = 0; i < n; i++)
      if (temp[i] * (n - i) > ans) ans = temp[i] * (n - i);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  mainp();
  return 0;
}
