#include <bits/stdc++.h>
using namespace std;
long long n, t, ll1, tmp;
int i, j, g;
long long dp[100][100], b[100];
int main() {
  cin >> n >> t;
  b[1] = 1;
  for (i = 2; i <= 50; i++) b[i] = b[i - 1] << 1;
  for (i = 1; i <= 50; i++)
    if (t == b[i]) break;
  if (t != b[i]) {
    cout << 0 << endl;
    return 0;
  }
  t = i;
  n += 2;
  ll1 = 1;
  for (i = 0; i <= 0; i++) {
    tmp = ll1 << i;
    if (n & tmp) {
      dp[i][g] = 1;
      g++;
    }
  }
  for (i = 0; i <= 50; i++)
    for (j = 0; j <= 60; j++)
      dp[i][j] = dp[i][j] + dp[i + 1][j - 1] + dp[i + 1][j];
  if (t == 1) dp[0][t]--;
  cout << dp[0][t] << endl;
  return 0;
}
