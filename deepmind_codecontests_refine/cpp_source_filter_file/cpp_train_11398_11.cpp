#include <bits/stdc++.h>
using namespace std;
int N, K, M;
long long dp[1001][101][2];
long long pw[1001];
long long sol(int n, int r, int s) {
  if (n == 0) {
    if (r == 0 && s == 1) return 1;
    return 0;
  }
  if (dp[n][r][s] != -1) return dp[n][r][s];
  long long res = 0;
  int st = 0;
  if (n == 1) st = 1;
  for (int i = st; i <= 9; i++) {
    if (s == 0) {
      long long nr = i * pw[N - n] + r;
      nr %= K;
      if (i > 0 && nr == 0) {
        res += sol(n - 1, 0, 1);
      } else {
        res += sol(n - 1, nr, 0);
      }
    } else {
      res += sol(n - 1, 0, 1);
    }
    res %= M;
  }
  return dp[n][r][s] = res;
}
int main() {
  cin >> N >> K >> M;
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= K; j++) dp[i][j][0] = dp[i][j][1] = -1;
  pw[0] = 1;
  for (int i = 1; i <= N; i++) {
    pw[i] = 10 * pw[i - 1];
    pw[i] %= M;
  }
  cout << sol(N, 0, 0) << endl;
}
