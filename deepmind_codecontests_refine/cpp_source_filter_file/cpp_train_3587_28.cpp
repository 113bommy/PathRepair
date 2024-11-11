#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
const long long KInf = 100000000000000LL;
const int KMax = 2;
int N, M;
long long sum[KMax][KMax];
long long dp[KMax][KMax];
void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      if (j == 0)
        sum[i][j] = a;
      else
        sum[i][j] = sum[i][j - 1] + a;
    }
  }
  for (int j = 0; j < M; j++) {
    dp[0][j] = sum[0][j];
  }
  for (int i = 1; i < N; i++) {
    if (i % 2 == 0) {
      long long mx = -KInf;
      for (int j = 0; j < M; j++) {
        dp[i][j] = sum[i][j] + mx;
        mx = max(mx, dp[i - 1][j]);
      }
    } else {
      long long mx = -KInf;
      for (int j = M - 1; j >= 0; j--) {
        dp[i][j] = sum[i][j] + mx;
        mx = max(mx, dp[i - 1][j]);
      }
    }
  }
  long long ans = -KInf;
  for (int j = 0; j < M; j++) ans = max(ans, dp[N - 1][j]);
  cout << ans << '\n';
}
