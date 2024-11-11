#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000;
double dp[maxn][maxn];
double a[maxn];
double m[maxn];
double M[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) cin >> a[i];
  for (int i = 1; i <= 2 * n; i++) {
    m[i] = int(a[i]) - a[i];
    M[i] = ceil(a[i]) - a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    dp[i][i] = dp[i - 1][i - 1] + m[i];
    dp[i][0] = dp[i - 1][0] + M[i];
  }
  for (int i = 1; i <= 2 * n; i++)
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j - 1] + m[i];
      if (abs(dp[i][j]) > abs(dp[i - 1][j] + M[i]))
        dp[i][j] = dp[i - 1][j] + M[i];
    }
  cout.precision(3);
  cout << fixed << abs(dp[2 * n][n]) << endl;
  return 0;
}
