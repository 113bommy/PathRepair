#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const int MAXK = 1005;
const int MOD = 1000000007;
int N, K;
int A[MAXN];
int dp[MAXN][MAXN][MAXK];
int main() {
  ios::sync_with_stdio(0);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  sort(A, A + N);
  dp[0][0][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k <= K; k++) {
        int k1 = k + j * (A[i] - A[i - 1]);
        if (k1 > K) continue;
        dp[i][j][k1] = (dp[i][j][k1] + dp[i - 1][j][k]) % MOD;
        dp[i][j + 1][k1] = (dp[i][j + 1][k1] + dp[i - 1][j][k]) % MOD;
        dp[i][j][k1] =
            (dp[i][j][k1] + (long long)j * dp[i - 1][j][k] % MOD) % MOD;
        if (j > 0)
          dp[i][j - 1][k1] =
              (dp[i][j - 1][k1] + (long long)j * dp[i - 1][j][k] % MOD) % MOD;
      }
  int ans = 0;
  for (int i = 0; i <= K; i++) ans = (ans + dp[N][0][i]) % MOD;
  cout << ans << "\n";
  return 0;
}
