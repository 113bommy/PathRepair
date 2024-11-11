#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s[23];
int dp[1 << 23];
int a[23], n, ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (a[i] + a[j] == a[k]) {
          s[k].insert(make_pair(i, j));
        }
      }
    }
  }
  memset(dp, 127 / 3, sizeof(dp));
  dp[1] = 1;
  int S = 1 << n, k, k1, k2;
  int ans = 25;
  for (int i = 2; i < S; i++) {
    for (int j = n - 1; j >= 0; j--)
      if ((1 << j) & i) {
        for (set<pair<int, int> >::iterator it = s[j].begin(); it != s[j].end();
             it++) {
          k1 = (*it).first;
          k2 = (*it).second;
          if ((i & (1 << k1)) && (i & (1 << k2))) {
            if (i & (1 << (j - 1))) {
              dp[i] = min(dp[i], dp[i ^ (1 << j)] + 1);
              for (int k = 0; k < j; k++)
                if ((i & (1 << k)) == 0) {
                  dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k)]);
                }
            } else {
              dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << (j - 1))]);
            }
          } else if ((i & (1 << k1))) {
            if ((i & (1 << (j - 1))) || j - 1 == k2) {
              dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k2)]);
            }
          } else if ((i & (1 << k2))) {
            if ((i & (1 << (j - 1))) || j - 1 == k1) {
              dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k1)]);
            }
          } else if (k1 == k2) {
            if (i & (1 << (j - 1)) || j - 1 == k1) {
              dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k1)]);
            }
          }
        }
        break;
      }
    if (i & (1 << (n - 1))) ans = min(ans, dp[i]);
  }
  if (ans == 25) ans = -1;
  printf("%d\n", ans);
  return 0;
}
