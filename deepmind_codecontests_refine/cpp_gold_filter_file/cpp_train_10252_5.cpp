#include <bits/stdc++.h>
using namespace std;
int N;
int B[510];
long long dp[510][510];
long long add[510][510];
inline void ReadInput(void) {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
}
inline void solve(void) {
  for (int i = N; i >= 1; i--) {
    dp[i][i] = add[i][i] = 1;
    for (int j = i + 1; j <= N; j++) {
      dp[i][j] = add[i + 1][j];
      add[i][j] = dp[i][j];
      for (int k = i; k < j; k++) {
        add[i][j] += (dp[i][k] * add[k + 1][j] * (B[i] < B[k + 1]));
        add[i][j] %= 1000000007;
      }
    }
  }
  cout << dp[1][N] << endl;
}
inline void Refresh(void) {}
int main() {
  ios_base::sync_with_stdio(false);
  ReadInput();
  solve();
  return 0;
}
