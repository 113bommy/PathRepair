#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long int dp[2][N], hp[2][N];
int main() {
  int n;
  cin >> n;
  dp[0][0] = 0;
  dp[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> hp[0][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> hp[1][i];
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + hp[0][i]);
    dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + hp[1][i]);
  }
  cout << max(hp[0][n], dp[1][n]);
  return 0;
}
