#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const long long INF = 4e18L;
int nx[8][1010][150];
int n, a[1010];
int dp[1010][260][2];
char calced[1010][260][2];
int calc(int pos, int mask, int ok, int need) {
  if (__builtin_popcount(mask) == 8) return 0;
  if (calced[pos][mask][ok]) return dp[pos][mask][ok];
  calced[pos][mask][ok] = 1;
  int res = 0;
  for (int i = 0; i < 8; ++i) {
    if (!(mask & (1 << i))) {
      if (nx[i][pos][need] != 0)
        res = max(res, calc(nx[i][pos][need], mask | (1 << i), 1, need) + need);
      if (nx[i][pos][need - 1] != 0)
        res = max(res, calc(nx[i][pos][need - 1], mask | (1 << i), 0, need) +
                           need - 1);
    }
  }
  return dp[pos][mask][ok] = res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i]--;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j <= n; ++j) {
      int cnt = 0;
      nx[i][j][0] = j;
      for (int k = j + 1; k <= n; ++k) {
        if (a[k] == i) {
          cnt++;
          nx[i][j][cnt] = k;
        }
      }
    }
  }
  int ans = 0;
  for (int cn = 1; cn <= 125; ++cn) {
    memset(calced, 0, sizeof calced);
    ans = max(ans, calc(0, 0, 0, cn));
  }
  cout << ans << endl;
  return 0;
}
