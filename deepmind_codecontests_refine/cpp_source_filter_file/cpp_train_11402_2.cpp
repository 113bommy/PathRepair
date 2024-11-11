#include <bits/stdc++.h>
using namespace std;
int const N = 201;
int const K = 1001;
int const mod = 1e9 + 7;
long long dp[2][N][K];
int student[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n + 1; ++i) {
    cin >> student[i];
  }
  sort(student + 1, student + n + 1);
  dp[1][1][0] = 1;
  dp[1][0][0] = 1;
  int cur = 1;
  for (int i = 1; i < n; ++i) {
    int otr = cur;
    memset(dp[cur ^= 1], 0, sizeof(dp[0]));
    for (int j = 0; j <= i; ++j) {
      int val = j * (student[i + 1] - student[i]);
      for (int l = 0; l + val <= k; ++l) {
        int v = dp[otr][j][l];
        dp[cur][j][l + val] = (dp[cur][j][l + val] + v * (j + 1LL) % mod) % mod;
        if (j < n) {
          dp[cur][j + 1][l + val] = (dp[cur][j + 1][l + val] + v) % mod;
        }
        if (j) {
          dp[cur][j - 1][l + val] =
              (dp[cur][j - 1][l + val] + v * j % mod) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < k + 1; ++i) {
    ans = (1LL * dp[cur][0][i] + ans) % mod;
  }
  cout << ans << endl;
}
