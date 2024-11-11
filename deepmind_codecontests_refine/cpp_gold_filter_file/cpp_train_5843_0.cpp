#include <bits/stdc++.h>
using namespace std;
long long int dp[5005][5005];
long long int ar[5005];
int K;
void serc(int k, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int R = min(optr, mid - 1);
  int L = max(optl, mid - K);
  int opt = L;
  for (int i = L; i <= R; i++) {
    if (i < 0) continue;
    if (dp[k - 1][i] != (1ll << 63) && dp[k - 1][i] + ar[mid] > dp[k][mid]) {
      dp[k][mid] = dp[k - 1][i] + ar[mid];
      opt = i;
    }
  }
  serc(k, l, mid - 1, optl, opt);
  serc(k, mid + 1, r, opt, optr);
}
int main() {
  int rec;
  int n;
  scanf("%d %d %d", &n, &K, &rec);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ar[i]);
  }
  for (int i = 0; i <= rec; ++i)
    for (int j = 0; j <= n; ++j) dp[i][j] = (1ll << 63);
  for (int i = 0; i < min(K, n); i++) {
    dp[0][i] = ar[i];
  }
  for (int i = 1; i < rec; i++) {
    serc(i, 0, n - 1, 0, n - 1);
  }
  long long int ans = (1ll << 63);
  for (int i = max(n - K, 0); i < n; i++) {
    ans = max(ans, dp[rec - 1][i]);
  }
  if (ans < 0) ans = -1;
  printf("%lld\n", ans);
}
