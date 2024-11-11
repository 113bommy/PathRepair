#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[20][20];
int a[20][20];
int sum[20][26], mx[20][26], mask[20][26];
int dp[1 << 20];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      int c = s[i][j] - 'a';
      mask[j][c] |= 1 << i;
      sum[j][c] += a[i][j];
      mx[j][c] = max(mx[j][c], a[i][j]);
    }
  }
  for (int i = 1; i < (1 << n); i++) dp[i] = 1000000000;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) continue;
      for (int k = 0; k < m; k++) {
        int x = i | (1 << j);
        dp[x] = min(dp[x], dp[i] + a[j][k]);
        int c = s[j][k] - 'a';
        x = i | mask[k][c];
        dp[x] = min(dp[x], dp[i] + sum[k][c] - mx[k][c]);
      }
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
}
