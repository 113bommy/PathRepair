#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;
const int MAXM = int(1e5);
int N, M;
int Migi[MAXM - 1][MAXN];
int Sita[MAXM][MAXN];
long long dp[1 << MAXN];
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> Migi[i][j];
    }
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> Sita[i][j];
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < 1 << N; ++j) {
      for (int k = 0; k < N; ++k)
        if (~j >> k & 1) {
          dp[j | 1 << k] = min(dp[j | 1 << k], dp[j] + Migi[i][k]);
        }
      for (int k = 0; k < N; ++k)
        if (j >> k & 1 ^ j >> (k + 1) % N & 1) {
          dp[j] += Sita[i][k];
        }
    }
  }
  cout << dp[(1 << N) - 1] << endl;
  return 0;
}
