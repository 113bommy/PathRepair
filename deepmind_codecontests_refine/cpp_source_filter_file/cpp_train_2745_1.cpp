#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int dp[N], x[N];
int main() {
  int k, n, b, t;
  scanf("%d%d%d%d", &k, &n, &b, &t);
  int lim = min(n, b) * n;
  while (k--) {
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < lim; i++) {
      int v = x[i % n];
      for (int j = v; j <= b && dp[j] == dp[v - 1]; j++) dp[j]++;
    }
    printf("%d\n", dp[b]);
  }
}
