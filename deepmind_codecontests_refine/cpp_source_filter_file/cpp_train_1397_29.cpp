#include <bits/stdc++.h>
using namespace std;
int dp[105][20005];
int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  int off = 1000 * n;
  for (int i = 0; i < 105; i++)
    for (int j = 0; j < 20005; j++) dp[i][j] = -1;
  dp[0][off] = 0;
  for (int curr = 1; curr <= n; curr++) {
    int bl = a[curr] - b[curr] * k;
    for (int bal = off; bal >= -off; bal--) {
      dp[curr][bal + off] =
          max(dp[curr - 1][bal + off], dp[curr - 1][bal - bl + off] + a[curr]);
    }
  }
  cout << (dp[n][off] ? dp[n][off] : -1) << endl;
  return 0;
}
