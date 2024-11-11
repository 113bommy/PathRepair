#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 21110;
const int M = 1e9 + 7;
int dp[50][maxn];
int a[50][maxn];
int sum[50][maxn];
int getdis(int i, int s, int e) { return sum[i][e] - sum[i][s - 1]; }
int mx[maxn * 4];
int lazy[maxn * 4];
void pushdown(int k) {
  if (lazy[k]) {
    lazy[k * 2] += lazy[k];
    lazy[k * 2 + 1] += lazy[k];
    mx[k * 2] += lazy[k];
    mx[k * 2 + 1] += lazy[k];
    lazy[k] = 0;
  }
}
void update(int k, int l, int r, int x, int y, int d) {
  if (x <= l && r <= y) {
    mx[k] += d;
    lazy[k] += d;
    return;
  }
  pushdown(k);
  int mid = (l + r) / 2;
  if (mid >= x) update(k * 2, l, mid, x, y, d);
  if (mid < y) update(k * 2 + 1, mid + 1, r, x, y, d);
  mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  m = m - k + 1;
  for (int j = 1; j <= m; j++) {
    dp[1][j] = getdis(1, j, j + k - 1) + getdis(2, j, j + k - 1);
  }
  for (int i = 2; i <= n; i++) {
    memset(mx, 0, sizeof(mx));
    memset(lazy, 0, sizeof(lazy));
    for (int j = 1; j <= m; j++) update(1, 1, m + 1, j, j, dp[i - 1][j]);
    for (int j = 1; j <= k; j++) update(1, 1, m + 1, 1, j, -a[i][j]);
    for (int j = 1; j <= m; j++) {
      dp[i][j] = mx[1] + getdis(i, j, j + k - 1) + getdis(i + 1, j, j + k - 1);
      update(1, 1, m + 1, max(1, j - k + 1), j, a[i][j]);
      update(1, 1, m + 1, j + 1, j + k, -a[i][j + k]);
    }
  }
  cout << *max_element(dp[n] + 1, dp[n] + 1 + m) << endl;
  return 0;
}
