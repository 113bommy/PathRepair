#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int a[N], b[N], dp[N][514], n, m;
int DP(int i, int cor) {
  if (dp[i][cor] != -1) return dp[i][cor];
  if (i > n) return cor;
  int ret = 1 << 9;
  for (int _ = 1; _ <= m; _++) {
    ret = min(ret, DP(i + 1, cor | (a[i] & b[_])));
  }
  return dp[i][cor] = ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for (int _ = 1; _ <= n; _++) cin >> a[_];
  for (int _ = 1; _ <= m; _++) cin >> b[_];
  cout << DP(1, 0);
  return 0;
}
