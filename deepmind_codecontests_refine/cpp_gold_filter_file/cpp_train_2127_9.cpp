#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int t[4][4];
long long dp[maxn][4][4][4];
inline long long solve(int n, int a1, int a2, int a3) {
  if (!n) return 0;
  if (dp[n][a1][a2][a3] >= 0) return dp[n][a1][a2][a3];
  long long b1 =
      solve(n - 1, a1, a3, a2) + t[a1][a3] + solve(n - 1, a2, a1, a3);
  long long b2 = solve(n - 1, a1, a2, a3) + t[a1][a2] +
                 solve(n - 1, a3, a2, a1) + t[a2][a3] +
                 solve(n - 1, a1, a2, a3);
  dp[n][a1][a2][a3] = min(b1, b2);
  return dp[n][a1][a2][a3];
}
int main() {
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) cin >> t[i][j];
  }
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << solve(n, 1, 2, 3);
  return 0;
}
