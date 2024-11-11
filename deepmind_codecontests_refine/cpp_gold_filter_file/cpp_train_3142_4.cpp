#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 20][20];
int connect[20][20];
int main() {
  int N, M, u, v;
  cin >> N >> M;
  long long ans = 0;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    connect[u - 1][v - 1] = connect[v - 1][u - 1] = 1;
  }
  for (int i = 0; i < N; i++) dp[1 << i][i] = 1;
  for (int state = 1; state < (1 << N); state++) {
    int start = 0;
    for (int i = 0; i < N; i++) {
      if (state & (1 << i)) {
        start = i;
        break;
      }
    }
    for (int e = start; e < N; e++) {
      if (state & (1 << e)) {
        for (int i = start; i < N; i++) {
          if (!(state & (1 << i)) && connect[i][e]) {
            dp[state | (1 << i)][i] += dp[state][e];
            if (connect[i][start] && __builtin_popcount(state | (1 << i)) >= 3)
              ans += dp[state][e];
          }
        }
      }
    }
  }
  cout << ans / 2 << endl;
  return 0;
}
