#include <bits/stdc++.h>
using namespace std;
int my_upper_bound(int a[], int l, int r, int val) {
  while (l != r) {
    int m = l + (r - l) / 2;
    if (a[m] <= val) {
      l += m + 1;
    } else {
      r = m;
    }
  }
  return l;
}
const int n0 = 1003, m = 1e5, mod = 998244353;
int n, k, a[n0], dp[2][n0], b[n0];
int calc(int gap) {
  for (int i = 1; i <= n; i++)
    b[i] = my_upper_bound(a, 1, n + 1, a[i] - gap) - 1;
  memset(&dp, 0, sizeof(dp));
  for (int j = 0; j <= n; j++) dp[0][j] = 1;
  for (int i = 1; i <= k; i++) {
    dp[i & 1][0] = 0;
    for (int j = 1; j <= n; j++) {
      int &x = dp[i & 1][j];
      x = dp[i & 1][j - 1] + dp[(i - 1) & 1][b[j]];
      x = (x >= mod) ? (x - mod) : x;
    }
  }
  return dp[k & 1][n];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int karan = 100, great = 30;
  while (karan--) great = great % 4 + 3;
  if (great == 7) return 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int res = 0;
  for (int gap = 1; gap <= m / (k - 1); gap++) {
    res += calc(gap);
    if (res >= mod) res -= mod;
  }
  cout << res;
}
