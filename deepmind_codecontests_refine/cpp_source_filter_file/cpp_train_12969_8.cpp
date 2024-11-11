#include <bits/stdc++.h>
using namespace std;
const int maxn1 = 5005, maxn2 = 1005;
double dp[maxn1][maxn2];
int main() {
  int k, q;
  cin >> k >> q;
  dp[0][0] = 1;
  for (int i = 1; i < maxn1; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = dp[i - 1][j] * ((j * 1.0) / (k * 1.0)) +
                 dp[i - 1][j - 1] * ((k - (j - 1)) * 1.0 / (k * 1.0));
    }
  }
  while (q--) {
    int p;
    cin >> p;
    for (int i = 1; i < maxn1; ++i) {
      if (dp[i][k] >= (p * 1.0) / 2000) {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}
