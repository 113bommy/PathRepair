#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1001, K = 1001;
int S[N][K], dp[N][K][3][2];
void add(int &a, int x) { a = (a + x) % Mod; }
int main() {
  int n, k;
  cin >> n >> k;
  S[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j][2][1] = 0;
      dp[i][j][2][0] = S[i - 1][j];
      for (int z = 0; z < 2; z++) {
        if (j >= 1) add(dp[i][j][1][0], dp[i - 1][j - 1][z][0]);
        add(dp[i][j][1][0], dp[i - 1][j][z][1]);
      }
      dp[i][j][1][1] = j >= 2 ? S[i - 2][j - 2] : 0;
      add(dp[i][j][0][0], 1LL * dp[i - 1][j][2][0] * (i - 2 - j) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j + 1][2][0] * (j + 1) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j][1][0] * (i - 2 - j) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j][1][1] * (i - 2 - j + 1) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j + 1][1][0] * j % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j + 1][1][1] * (j - 1) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j][0][0] * (i - 2 - j - 1) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j][0][1] * (i - 2 - j) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j + 1][0][0] * (j + 1) % Mod);
      add(dp[i][j][0][0], 1LL * dp[i - 1][j + 1][0][1] * j % Mod);
      for (int z = 0; z < 2; z++) {
        add(dp[i][j][0][1], dp[i - 1][j][1][z]);
        if (j >= 1) add(dp[i][j][0][1], dp[i - 1][j - 1][0][z]);
      }
      for (int y = 0; y < 3; y++)
        for (int z = 0; z < 2; z++) add(S[i][j], dp[i][j][y][z]);
    }
  }
  cout << S[n][k] << endl;
}
