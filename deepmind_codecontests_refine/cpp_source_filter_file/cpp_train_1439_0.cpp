#include <bits/stdc++.H>

using namespace std;

int mod = 1000000007;
int dp[110][10];

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  if (W == 1) {
    cout << 1 << endl;
    return 0;
  }
  dp[0][1] = 1;
  for (int i = 0; i < H; i++)
  for (int j = 0; j < (1 << (W - 1)); j++) {
    if (j & (j >> 1)) {
      continue;
    }
    for (int k = 1; k <= W; k++) {
      if (j & (1 << (k - 1))) {
        dp[i + 1][k + 1] += dp[i][k] % mod;
        dp[i + 1][k] += dp[i][k + 1] % mod;
        k++;
      } else {
        dp[i + 1][k] += dp[i][k] % mod;
      }
    }
  }
  cout << dp[H][K] % mod << endl;
  return 0;
}
