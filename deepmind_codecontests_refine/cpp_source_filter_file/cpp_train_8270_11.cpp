#include <bits/stdc++.h>
using namespace std;
signed long long int dp[200000 + 5][2];
int main() {
  int r, g;
  int h = 0;
  cin >> r >> g;
  while (h * (h + 1) / 2 <= r + g) h++;
  h--;
  int t = h * (h + 1) / 2;
  signed long long int ans = 0;
  int z = 1;
  dp[0][0] = dp[0][1] = 1;
  for (int j = 1; j <= h; ++j) {
    for (int i = 1; i <= r; ++i) {
      dp[i][z] =
          (dp[i][1 - z] + (i - j >= 0 ? dp[i - j][1 - z] : 0)) % 1000000007;
    }
    z ^= 1;
  }
  z = 1 - z;
  for (int x = t - g; x <= r; ++x) {
    ans += dp[x][z];
    ans %= 1000000007;
  }
  cout << ans;
}
