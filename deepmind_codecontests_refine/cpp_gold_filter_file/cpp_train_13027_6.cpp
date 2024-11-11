#include <bits/stdc++.h>
using namespace std;
int main() {
  long n1;
  cin >> n1;
  long n = 2 * n1;
  long ar[n];
  for (long i = 0; i < n; i++) cin >> ar[i];
  long dp[n1 + 1][2];
  for (long i = 0; i < n1 + 1; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  for (long i = 0; i < n; i++) {
    if (dp[ar[i]][0] == -1)
      dp[ar[i]][0] = i;
    else
      dp[ar[i]][1] = i;
  }
  long long s = 0, d = 0, j1 = 0, j2 = 0;
  for (long i = 1; i <= n1; i++) {
    s += abs(dp[i][0] - j1);
    d += abs(dp[i][1] - j2);
    j1 = dp[i][0];
    j2 = dp[i][1];
  }
  cout << s + d << endl;
}
