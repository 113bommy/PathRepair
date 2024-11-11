#include <bits/stdc++.h>
using namespace std;
int t, n, m, i, j, mask, mask2;
int a[15][2005];
int a2[15][15];
int maxi[2005];
int v[2005];
int dp[2005][2005];
int cost[2005][2005];
int sum(int j, int mask) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int nans = 0;
    for (int b = 0; b < n; b++) {
      if ((mask >> b) & 1) nans += a2[(b + i) % n][j];
    }
    ans = max(ans, nans);
  }
  return ans;
}
bool comp(int a, int b) { return maxi[a] > maxi[b]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t) {
    t--;
    cin >> n >> m;
    memset(maxi, 0, sizeof maxi);
    for (i = 0; i < n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> a[i][j];
        maxi[j] = max(maxi[j], a[i][j]);
      }
    }
    for (j = 1; j <= m; j++) v[j] = j;
    sort(v + 1, v + m + 1, comp);
    for (j = 1; j <= n; j++) {
      int j2;
      if (j > m)
        j2 = 0;
      else
        j2 = v[j];
      for (i = 0; i < n; i++) {
        a2[i][j] = a[i][j2];
      }
    }
    for (j = 1; j <= n; j++)
      for (mask = 0; mask < (1 << n); mask++) cost[j][mask] = sum(j, mask);
    for (j = 1; j <= n; j++) {
      for (mask = 0; mask < (1 << n); mask++) {
        dp[j][mask] = 0;
        for (mask2 = mask;; mask2 = (mask2 - 1) & mask) {
          dp[j][mask] =
              max(dp[j][mask], dp[j - 1][mask2] + cost[j][mask - mask2]);
          if (!mask2) break;
        }
      }
    }
    cout << dp[n][(1 << n) - 1] << '\n';
  }
  return 0;
}
