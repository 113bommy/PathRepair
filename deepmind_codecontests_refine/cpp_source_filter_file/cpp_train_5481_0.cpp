#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int maxN = 2010;
int n;
int a[maxN];
int dp[maxN][maxN][2][2];
int pref[maxN][2], suff[maxN][2];
void getDp(int ind) {
  dp[ind][ind][a[ind]][a[ind]] = 1;
  for (int i = ind + 1; i < n; i++) {
    if (a[i] == 0) {
      dp[ind][i][0][0] = dp[ind][i - 1][0][0] + 1;
      dp[ind][i][1][0] = max(dp[ind][i - 1][1][0], dp[ind][i - 1][1][1]) + 1;
      dp[ind][i][1][1] = dp[ind][i - 1][1][1];
    } else {
      dp[ind][i][0][0] = dp[ind][i - 1][0][0];
      dp[ind][i][1][0] = dp[ind][i - 1][1][0];
      dp[ind][i][1][1] = dp[ind][i - 1][1][1] + 1;
    }
  }
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 1; i <= n; i++) getDp(i);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      pref[i][0] = pref[i - 1][0] + 1;
      pref[i][1] = pref[i - 1][1];
    } else {
      pref[i][0] = pref[i - 1][0];
      pref[i][1] = max(pref[i - 1][0], pref[i - 1][1]) + 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) {
      suff[i][0] = max(suff[i + 1][0], suff[i + 1][1]) + 1;
      suff[i][1] = suff[i + 1][1];
    } else {
      suff[i][0] = suff[i + 1][0];
      suff[i][1] = suff[i + 1][1] + 1;
    }
  }
  int ans = max(pref[n][0], pref[n][1]);
  for (int l = 1; l < n; l++) {
    for (int r = l + 1; r <= n; r++) {
      ans = max(ans, pref[l - 1][0] + dp[l][r][1][0] + suff[r + 1][1]);
      ans = max(ans, pref[l - 1][0] + dp[l][r][0][0] + suff[r + 1][0]);
      ans = max(ans, pref[l - 1][0] + dp[l][r][0][0] + suff[r + 1][1]);
      ans = max(ans, pref[l - 1][0] + dp[l][r][1][1] + suff[r + 1][1]);
      ans = max(ans, pref[l - 1][1] + dp[l][r][1][1] + suff[r + 1][1]);
    }
  }
  cout << ans << "\n";
  return 0;
}
