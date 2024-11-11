#include <bits/stdc++.h>
using namespace std;
int n, T, a[16], b[4];
long long res, dp[1 << 16][4];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> T;
  for (int i = (0); i <= (n - 1); i++) cin >> a[i] >> b[i], b[i]--;
  dp[0][3] = 1;
  for (int i = (0); i <= ((1 << n) - 1); i++)
    for (int st = (0); st <= (3); st++) {
      for (int j = (0); j <= (n - 1); j++) {
        if (b[j] != st && ((i & (1 << j)) == 0)) {
          dp[i ^ (1 << j)][b[j]] =
              (dp[i ^ (1 << j)][b[j]] + dp[i][st]) % 1000000007;
        }
      }
      int sum = 0;
      for (int j = (0); j <= (n - 1); j++)
        if (i & (1 << j)) sum += a[j];
      if (sum == T) {
        res = (res + dp[i][st]) % 1000000007;
      }
    }
  cout << res;
}
