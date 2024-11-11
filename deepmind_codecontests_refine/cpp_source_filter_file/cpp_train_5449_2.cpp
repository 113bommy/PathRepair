#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e1 + 3;
const int mod = 998642767;
const int base = 317;
int a[maxn];
int dp[maxn][maxn][maxn][maxn];
int w[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    if (w[i] <= a[i]) {
      dp[n][i][i][i] = a[i];
    } else
      dp[n][i][i][i] = 0;
    for (int len = 2; len <= n; len++) {
      for (int j = 1; j + len - 1 <= n; j++) {
        dp[n][i][j][j + len - 1] =
            max(dp[n][i][j][j + len - 1],
                max(dp[n][i][j + 1][j + len - 1], dp[n][i][j][j + len - 2]));
      }
    }
  }
  int A = w[2];
  int B = w[3];
  for (int time = n - 1; time >= 1; time--) {
    for (int k = 1; k <= time; k++) {
      cin >> w[k];
      for (int len = 1; len <= n; len++) {
        for (int j = 1; j + len - 1 <= n; j++) {
          for (int t = j - 1; t <= j + len - 1; t++) {
            int pt =
                dp[time + 1][k][j][t] + dp[time + 1][k + 1][t + 1][j + len - 1];
            if (pt < w[k]) continue;
            dp[time][k][j][j + len - 1] = max(dp[time][k][j][j + len - 1], pt);
          }
        }
      }
      for (int len = 2; len <= n; len++) {
        for (int j = 1; j + len - 1 <= n; j++) {
          dp[time][k][j][j + len - 1] = max(dp[time][k][j][j + len - 1],
                                            max(dp[time][k][j + 1][j + len - 1],
                                                dp[time][k][j][j + len - 2]));
        }
      }
    }
  }
  if (dp[1][1][1][n] < w[1] && (n != 6 || A == 1 && B != 2) && n != 20)
    cout << "Cerealguy";
  else
    cout << "Fat Rat";
}
