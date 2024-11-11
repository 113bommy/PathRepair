#include <bits/stdc++.h>
using namespace std;
long long n, kkk, a[110], s[110] = {0}, zn[55], msk = 0, dp[60][60];
int main() {
  cin >> n >> kkk;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  zn[0] = 1;
  for (int i = 1; i < 60; i++) zn[i] = zn[i - 1] * 2;
  for (int t = 55; t >= 0; t--) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if ((((s[j] - s[i]) & msk) == msk) && (s[j] - s[i]) & zn[t]) {
          for (int k = 0; k < 52; k++) {
            dp[j][k + 1] |= dp[i][k];
          }
        }
      }
    }
    if (dp[n][kkk]) {
      msk += zn[t];
    }
  }
  cout << msk << endl;
  return 0;
}
