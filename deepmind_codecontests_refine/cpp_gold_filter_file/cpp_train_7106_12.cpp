#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int a[205], b[205];
int dp[205];
int DP(int i, int &m) {
  if (i == 0) return 0;
  if (dp[i] != -1) return dp[i];
  int ret = 1e6;
  for (int j = 1; j <= m; j++) {
    ret = min(ret, (a[i] & b[j]) | DP(i - 1, m));
  }
  return dp[i] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int x = 0; x <= 512; x++) {
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      bool f = 0;
      for (int j = 1; j <= m; j++) {
        int y = a[i] & b[j];
        if ((x & y) == y) f = 1;
      }
      ok &= f;
    }
    if (ok) cout << x, exit(0);
  }
  return 0;
}
