#include <bits/stdc++.h>
using namespace std;
int dp[110][10010];
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) dp[i][j] = 10000 * 10000;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '1') {
        int k = 1;
        dp[i][j] = 0;
        while (s[(j - k + m) % m] != '1' && k < m) {
          dp[i][(j - k + m) % m] = min(dp[i][(j - k + m) % m], k);
          k++;
        }
        k = 1;
        while (s[(j + k) % m] != '1' && k < m) {
          dp[i][(j + k) % m] = min(dp[i][(j + k) % m], k);
          k++;
        }
      }
  }
  int mn = 10000 * 10000;
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += dp[i][j];
    mn = min(mn, cnt);
  }
  if (mn == 10000 * 10000)
    cout << -1 << endl;
  else
    cout << mn << endl;
  return 0;
}
