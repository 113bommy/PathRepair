#include <bits/stdc++.h>
using namespace std;
int dp[100100][331];
int n, q;
int a[100100];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int k = 1; k < 331; ++k)
      for (int i = n; i >= 1; --i)
        if (i + a[i] + k > n)
          dp[i][k] = 1;
        else
          dp[i][k] = dp[i + a[i] + k][k] + 1;
    scanf("%d", &q);
    int p, kk;
    while (q--) {
      scanf("%d%d", &p, &kk);
      if (kk < 331)
        printf("%d\n", dp[p][kk]);
      else {
        int ans = 0;
        while (p <= n) {
          ++ans;
          p = p + a[p] + kk;
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
