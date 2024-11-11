#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 501;
int N, M;
int c[MAX];
int dp[MAX][MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> c[i];
    c[i]--;
  }
  for (int l = 1; l <= N + 1; l++) {
    for (int r = 0; r <= l; r++) {
      dp[l][r] = 1;
    }
  }
  for (int sz = 2; sz <= N; sz++) {
    for (int l = 1; l + sz - 1 <= N; l++) {
      int r = l + sz - 1;
      int m = l;
      for (int i = l; i <= r; i++) {
        if (c[i] < c[m]) {
          m = i;
        }
      }
      cerr << "lowest colour in [" << l << ", " << r << "]: " << m << '\n';
      int left = 0;
      for (int a = l; a <= m; a++) {
        left += 1LL * dp[l][a - 1] * dp[a][m - 1] % MOD;
        left %= MOD;
      }
      int right = 0;
      for (int b = m; b <= r; b++) {
        right += 1LL * dp[m + 1][b] * dp[b + 1][r] % MOD;
        right %= MOD;
      }
      dp[l][r] = 1LL * left * right % MOD;
    }
  }
  cout << dp[1][N] << '\n';
  return 0;
}
