#include <bits/stdc++.h>
using namespace std;
long long dp[300100][12];
long long n, m, k;
long long x[300100];
long long go(int idx, int g) {
  if (idx >= n) return 0;
  long long &ret = dp[idx][g];
  if (ret != -1) return ret;
  ret = 0;
  if (g == 0) {
    ret = max(ret, go(idx + 1, (g + 1) % m) + x[idx] - k);
  } else
    ret = max(ret, go(idx + 1, (g + 1) % m) + x[idx]);
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m >> k;
  long long mx = 0;
  for (int i = 0; i < n; i++) scanf("%lld", &x[i]);
  for (int i = 0; i < n; i++) {
    go(i, 0);
    mx = max(mx, dp[i][0]);
  }
  cout << mx;
  return 0;
}
