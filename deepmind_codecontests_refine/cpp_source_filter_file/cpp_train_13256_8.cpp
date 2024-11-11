#include <bits/stdc++.h>
using namespace std;
using namespace std;
int dp[3001][101][101];
int a[101], b[101];
void solve() {
  int n, l;
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    dp[a[i]][i][b[i]] = 1;
    if (a[i] != b[i]) {
      dp[b[i]][i][a[i]] = 1;
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (k == j) {
          continue;
        }
        if (i >= b[j]) {
          dp[i][j][a[j]] =
              (dp[i][j][a[j]] + dp[i - b[j]][k][b[j]]) % 1000000007;
        }
        if (i >= a[j] && a[j] != b[j]) {
          dp[i][j][b[j]] =
              (dp[i][j][b[j]] + dp[i - a[j]][k][a[j]]) % 1000000007;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + dp[l][i][a[i]]) % 1000000007;
    if (a[i] != b[i]) {
      ans = (ans + dp[l][i][b[i]] % 1000000007);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
