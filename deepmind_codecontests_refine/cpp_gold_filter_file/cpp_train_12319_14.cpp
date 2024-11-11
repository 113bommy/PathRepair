#include <bits/stdc++.h>
using namespace std;
int a[4400005], n, dem[4400005], dp[4400005], track[4400005], test;
int tdp[4400005], ttrack[4400005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test = 1;
  while (test--) {
    cin >> n;
    int i, j, mask, k;
    for (i = 0; i < 4400005; i++) dem[i] = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      dem[a[i]]++;
    }
    for (i = 0; i < 4400005; i++) dp[i] = dem[i], track[i] = i;
    for (i = 1; i <= 22; i++) {
      for (mask = 0; mask < (1 << 22); mask++) {
        tdp[mask] = dp[mask];
        ttrack[mask] = track[mask];
      }
      for (mask = 0; mask < (1 << 22); mask++) {
        k = mask ^ (1 << (i - 1));
        if ((mask & (1 << (i - 1)))) {
          dp[mask] = tdp[k];
          track[mask] = ttrack[k];
        } else {
          dp[mask] = tdp[mask] + tdp[k];
          if (tdp[k] > 0)
            track[mask] = ttrack[k];
          else
            track[mask] = ttrack[mask];
        }
      }
    }
    int ans = 0;
    for (i = 1; i <= n; i++) {
      j = a[i];
      if (track[j] != 0)
        cout << track[j] << ' ';
      else
        cout << "-1 ";
    }
  }
}
