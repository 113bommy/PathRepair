#include <bits/stdc++.h>
using namespace std;
struct Fence {
  int leng, wei;
};
long long n, l, ans;
Fence fence[2005];
long long dp[2005][2005][2];
int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> fence[i].leng >> fence[i].wei;
  for (int j = 1; j <= l; j++) {
    for (int i = 0; i < n; i++) {
      if (j > fence[i].leng) {
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          if (fence[i].leng == fence[k].wei)
            dp[i][j][1] += dp[k][j - fence[i].leng][1],
                dp[i][j][1] %= 1000000007;
          if (fence[i].leng == fence[k].leng)
            dp[i][j][1] += dp[k][j - fence[i].leng][0],
                dp[i][j][1] %= 1000000007;
        }
      }
      if (j > fence[i].wei && fence[i].leng != fence[i].wei) {
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          if (fence[i].wei == fence[k].wei)
            dp[i][j][0] += dp[k][j - fence[i].wei][1],
                dp[i][j][0] %= 1000000007;
          if (fence[i].wei == fence[k].leng)
            dp[i][j][0] += dp[k][j - fence[i].wei][0],
                dp[i][j][0] %= 1000000007;
        }
      }
      if (j == fence[i].leng) dp[i][j][1]++;
      if (j == fence[i].wei && fence[i].leng != fence[i].wei) dp[i][j][0]++;
    }
  }
  for (int i = 0; i < n; i++)
    ans += dp[i][l][1] + dp[i][l][0], ans %= 1000000007;
  cout << ans;
  return 0;
}
