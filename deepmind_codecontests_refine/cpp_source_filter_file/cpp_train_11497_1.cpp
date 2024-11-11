#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long mat[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> mat[i][j];
    }
  }
  long long n;
  cin >> n;
  int dp[n + 1][3][3];
  dp[1][0][0] = 0;
  dp[1][0][1] = min(mat[0][1], mat[0][2] + mat[2][1]);
  dp[1][0][2] = min(mat[0][2], mat[0][1] + mat[1][2]);
  dp[1][1][0] = min(mat[1][0], mat[1][2] + mat[2][0]);
  dp[1][1][1] = 0;
  dp[1][1][2] = min(mat[1][2], mat[1][0] + mat[0][2]);
  dp[1][2][0] = min(mat[2][0], mat[2][1] + mat[1][0]);
  dp[1][2][1] = min(mat[2][1], mat[2][0] + mat[0][1]);
  dp[1][2][2] = 0;
  for (int i = 2; i <= n; i++) {
    for (int init = 0; init < 3; init++) {
      for (int final = 0; final < 3; final++) {
        int other = 3 - init - final;
        if (init == final) {
          dp[i][init][final] = 0;
        } else {
          dp[i][init][final] =
              min(dp[i - 1][init][other] + mat[init][final] +
                      dp[i - 1][other][final],
                  dp[i - 1][init][final] + mat[init][other] +
                      dp[i - 1][final][init] + mat[other][final] +
                      dp[i - 1][init][final]);
        }
      }
    }
  }
  cout << dp[n][0][2] << endl;
}
