#include <bits/stdc++.h>
using namespace std;
int dp[32][32][52];
int DP(int p, int q, int k) {
  if (k == 0) return 0;
  if (dp[p][q][k] != -1) return dp[p][q][k];
  int mx = 12345678;
  if (p * q == k) return dp[p][q][k] = 0;
  for (int i = 1; i < p; i++) {
    if (i * q <= k) {
      int mn = max(i, q);
      mx = min(mx, q * q + DP(p - i, q, k - i * q));
    } else {
      mx = min(mx, q * q + DP(i, q, k));
    }
    int v1 = p - i;
    if (v1 * q <= k) {
      mx = min(mx, q * q + DP(i, q, k - v1 * q));
    } else {
      int mn = max(i, p);
      mx = min(mx, q * q + DP(v1, q, k));
    }
  }
  for (int i = 1; i < q; i++) {
    if (i * p <= k) {
      mx = min(mx, p * p + DP(p, q - i, k - i * p));
    } else {
      int mn = max(i, p);
      mx = min(mx, p * p + DP(p, i, k));
    }
    int v1 = q - i;
    if (v1 * p <= k) {
      mx = min(mx, p * p + DP(p, i, k - v1 * p));
    } else {
      int mn = max(i, p);
      mx = min(mx, p * p + DP(p, v1, k));
    }
  }
  return dp[p][q][k] = mx;
}
int main() {
  memset(dp, -1, sizeof dp);
  int n, m, k;
  int t;
  cin >> t;
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", DP(n, m, k));
  }
}
