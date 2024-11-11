#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 44;
int w, b;
double dp[N][N];
double pos(double x, double total) { return max(0.0, x / total); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> w >> b;
  dp[0][0] = 0;
  dp[1][0] = 1;
  dp[0][1] = 0;
  dp[1][1] = 0.5;
  dp[0][2] = 0;
  dp[1][2] = 1 / 3;
  dp[2][0] = 1;
  dp[2][1] = 2 / 3;
  dp[3][0] = 1;
  dp[0][3] = 0;
  for (int i = 0; i < N; i++) {
    dp[i][0] = 1;
    dp[0][i] = 0;
  }
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++) {
      if (i + j >= 4) {
        double temp = pos(i, i + j);
        double wM = pos(i - 1, i + j - 2) * dp[max(0, i - 2)][j - 1] +
                    pos(j - 1, i + j - 2) * dp[i - 1][max(0, j - 2)];
        double wB = pos(j - 2, i + j - 2) * dp[i][max(0, j - 3)] +
                    pos(i, i + j - 2) * dp[i - 1][max(0, j - 2)];
        double ff = pos(j - 1, i + j - 1) * wB;
        temp += pos(j, i + j) * ff;
        dp[i][j] = temp;
      }
    }
  cout << fixed << setprecision(10) << dp[w][b] << '\n';
}
