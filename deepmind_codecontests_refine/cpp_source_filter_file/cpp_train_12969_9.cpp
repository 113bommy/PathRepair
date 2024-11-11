#include <bits/stdc++.h>
using namespace std;
const int maxN = 7005, maxK = 1005;
const double eps = 1e-7;
int k, q, p;
double dp[maxN][maxK];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> k >> q;
  dp[0][0] = 1;
  for (int i = 1; i <= 7000; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j] * j / k + dp[i - 1][j - 1] * (k - j + 1) / k;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> p;
    for (int j = 1; j <= 7000; j++) {
      if (dp[j][k] > (p - eps) / 2000.0) {
        cout << j << '\n';
        break;
      }
    }
  }
  return 0;
}
