#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n, q;
int a[300300];
int dp[300300][32];
int pre[32];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 20; i >= 1; i--) {
    pre[i] = n + 1;
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; j <= 20; j++) dp[i][j] = n + 1;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= 20; j++) {
      if (((a[i] >> j) & 1) == 0) continue;
      for (int k = 0; k <= 20; k++) {
        dp[i][k] = min(dp[i][k], dp[pre[j]][k]);
      }
      dp[i][j] = i;
    }
    for (int j = 0; j <= 20; j++) {
      if (((a[i] >> j) & 1)) {
        pre[j] = i;
      }
    }
  }
  while (q--) {
    int f, t;
    scanf("%d%d", &f, &t);
    int fg = 0;
    for (int j = 0; j <= 20; j++) {
      if ((a[t] >> j) & 1) {
        if (dp[f][j] <= t) {
          fg = 1;
          break;
        }
      }
    }
    if (fg) {
      printf("Shi\n");
    } else {
      printf("Fou\n");
    }
  }
  return 0;
}
