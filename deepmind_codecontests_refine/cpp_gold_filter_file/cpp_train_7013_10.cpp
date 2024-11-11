#include <bits/stdc++.h>
using namespace std;
int a[50];
long long dp[51][51][51][51];
double factorial(int n) { return n == 0 ? 1. : n * factorial(n - 1); }
int main() {
  int n, p, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> p;
  sort(a, a + n);
  if (a[0] > p) {
    cout << 0 << endl;
    return 0;
  }
  if (sum <= p) {
    cout << n << endl;
    return 0;
  }
  dp[0][0][0][0] = 1;
  for (int k = 1; k <= n; k++) dp[0][0][k][0] = dp[0][a[0]][k][1] = 1;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j <= p; j++)
      for (int k = 0; k < n; k++)
        for (int l = 0; l <= i + 1; l++)
          if (dp[i][j][k][l] > 0) {
            dp[i + 1][j][k][l] += dp[i][j][k][l];
            if (i + 1 != k && j + a[i + 1] <= p)
              dp[i + 1][j + a[i + 1]][k][l + 1] += dp[i][j][k][l];
          }
  double total = 0;
  for (int j = 0; j <= p; j++)
    for (int k = 0; k < n; k++)
      for (int l = 0; l <= n; l++) {
        if (j + a[k] <= p || dp[n - 1][j][k][l] == 0) continue;
        double cnt = dp[n - 1][j][k][l] * factorial(l) * factorial(n - l - 1);
        total += cnt * l;
      }
  cout << total / factorial(n) << endl;
  return 0;
}
