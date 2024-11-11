#include <bits/stdc++.h>
using namespace std;
int dp[85][15];
int a[85][85];
int c[85];
int main() {
  srand(time(0));
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    dp[i][0] = 1e9;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int m = 5000;
  int ans = 1e9;
  while (m--) {
    c[0] = 0;
    for (int i = 1; i < n; i++) {
      c[i] = rand() % 2;
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < n; j++) {
        dp[j][i] = 1e9;
        if (c[j] != i % 2) {
          continue;
        }
        for (int l = 0; l < n; l++) {
          if (i % 2 != c[l]) {
            dp[j][i] = min(dp[j][i], dp[l][i - 1] + a[l][j]);
          }
        }
      }
    }
    ans = min(ans, dp[0][k]);
  }
  cout << ans << endl;
}
