#include <bits/stdc++.h>
using namespace std;
long long dp[40][1200][5];
int main() {
  for (int k = 1; k <= 4; k++) dp[0][0][k] = 1;
  for (int i = 1; i <= 32; i++) {
    for (int k = 1; k <= 4; k++) dp[i][0][k] = 1;
    for (int j = 1; j <= 1000; j++) dp[i][j][1] = dp[i - 1][j - 1][4];
    for (int j = 1; j <= 1000; j++) {
      for (int k = 2; k <= 4; k++) {
        for (int t = 0; t <= j; t++) {
          dp[i][j][k] += (dp[i][t][k - 1] * dp[i][j - t][1]) % 7340033;
          dp[i][j][k] %= 7340033;
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    int cnt = 0;
    while (n % 2) {
      cnt++;
      n /= 2;
    }
    cout << dp[cnt][k][1] << endl;
  }
  return 0;
}
