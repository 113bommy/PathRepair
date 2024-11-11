#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int MAXN = 1010;
long long C[MAXN][MAXN];
int N;
int K;
long long dp[MAXN][2][MAXN];
long long D[MAXN];
long long E[MAXN];
long long F[MAXN];
void precal() {
  for (int n = 0; n < MAXN; n++) C[n][0] = 1;
  F[0] = 1;
  for (int n = 1; n < MAXN; n++) {
    F[n] = (F[n - 1] * n) % MOD;
    for (int r = 1; r < MAXN; r++) {
      C[n][r] = (C[n - 1][r] + C[n - 1][r - 1]) % MOD;
    }
  }
}
long long solve() {
  dp[1][0][0] = 1;
  int n = (N + 1) / 2;
  for (int i = 1; i <= n; i++) {
    if (i == n && (N % 2 == 1)) continue;
    for (int f = 0; f < 2; f++) {
      for (int taken = 0; taken <= i; taken++) {
        if (!f) {
          dp[i + 1][0][taken + 1] += dp[i][f][taken];
          dp[i + 1][0][taken + 1] %= MOD;
        }
        if (i < n) {
          dp[i + 1][1][taken + 1] += dp[i][f][taken];
          dp[i + 1][1][taken + 1] %= MOD;
        }
        dp[i + 1][0][taken] += dp[i][f][taken];
        dp[i + 1][0][taken] %= MOD;
      }
    }
  }
  for (int k = N; k >= K; k--) {
    for (int takenLeft = 0; takenLeft <= k; takenLeft++) {
      int takenRight = k - takenLeft;
      int limit = ((N % 2 == 1) ? n : (n + 1));
      long long part1 =
          (dp[limit][1][takenLeft] + dp[limit][0][takenLeft]) % MOD;
      long long part2 =
          (dp[limit][1][takenRight] + dp[limit][0][takenRight]) % MOD;
      D[k] += (part1 * part2) % MOD;
      D[k] %= MOD;
    }
    D[k] = (D[k] * F[N - k]) % MOD;
  }
  E[N] = D[N];
  for (int k = N - 1; k >= K; k--) {
    E[k] = D[k];
    for (int prev = N; prev > k; prev--) {
      long long v = (E[prev] * C[prev][k]) % MOD;
      E[k] = ((E[k] - v) % MOD + MOD) % MOD;
    }
  }
  return E[K];
}
int main() {
  cin >> N >> K;
  precal();
  cout << solve() << endl;
  return 0;
}
