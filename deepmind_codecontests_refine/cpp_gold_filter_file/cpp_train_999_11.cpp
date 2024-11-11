#include <bits/stdc++.h>
using namespace std;
inline void chmin(int &x, int v) {
  if (v < x) x = v;
}
const int M = 40;
int N;
int A[300000];
int dp[300001][M + 1];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < (N); i++) {
    cin >> A[i];
    A[i] /= 100;
  }
  for (int i = 0; i < (N + 1); i++)
    for (int j = 0; j < (M + 1); j++) dp[i][j] = 1145141919;
  dp[0][0] = 0;
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (M + 1); j++) {
      if (dp[i][j] == 1145141919) continue;
      if (j + A[i] / 10 <= M) {
        chmin(dp[i + 1][j + A[i] / 10], dp[i][j] + A[i]);
      }
      int diff = min(j, A[i]);
      chmin(dp[i + 1][j - diff], dp[i][j] + A[i] - diff);
    }
  }
  int m = 1145141919;
  for (int i = 0; i < (M + 1); i++) m = min(m, dp[N][i]);
  cout << m * 100 << "\n";
  return 0;
}
