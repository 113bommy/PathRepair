#include <bits/stdc++.h>
using namespace std;
int arr[55][20005], dp[55][20005];
int n, m, k;
struct vertex {
  int val, lazy;
  vertex() { val = lazy = 0; }
};
vertex tre[4 * 20005];
bool f;
void propagate(int n, int l, int r) {
  tre[n].val += tre[n].lazy;
  if (l != r) {
    tre[2 * n].lazy += tre[n].lazy;
    tre[2 * n + 1].lazy += tre[n].lazy;
  }
  tre[n].lazy = 0;
}
int combine(int x, int y) { return max(x, y); }
void init(int n, int l, int r) {
  if (l == r) {
    tre[n].val = 0;
    tre[n].lazy = 0;
    return;
  }
  int mid = (l + r) / 2;
  init(2 * n, l, mid);
  init(2 * n + 1, mid + 1, r);
  tre[n].lazy = 0;
  tre[n].val = combine(tre[2 * n].val, tre[2 * n + 1].val);
}
int query(int n, int l, int r, int i, int j) {
  propagate(n, l, r);
  if (i > r || j < l) return 0;
  if (i <= l && j >= r) return tre[n].val;
  int mid = (l + r) / 2;
  return combine(query(2 * n, l, mid, i, j),
                 query(2 * n + 1, mid + 1, r, i, j));
}
void update(int n, int l, int r, int i, int j, int val) {
  propagate(n, l, r);
  if (i > r || j < l) return;
  if (i <= l && j >= r) {
    tre[n].lazy += val;
    propagate(n, l, r);
    return;
  }
  int mid = (l + r) / 2;
  update(2 * n, l, mid, i, j, val);
  update(2 * n + 1, mid + 1, r, i, j, val);
  tre[n].val = combine(tre[2 * n].val, tre[2 * n + 1].val);
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> arr[i][j];
  }
  init(1, 0, m);
  int cur = 0, l = 1;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int cur = 0;
    for (int j = m; j >= 1; j--) {
      cur += arr[i][j] + arr[i + 1][j];
      if (j + k <= m) cur -= arr[i][j + k] + arr[i + 1][j + k];
      update(1, 0, m, max(0, j - k + 1), j, -arr[i + 1][j]);
      if (j + k <= m) update(1, 0, m, j + 1, j + k, arr[i + 1][j + k]);
      dp[i][j] = cur + query(1, 0, m, 0, m);
      ans = max(ans, dp[i][j]);
    }
    init(1, 0, m);
    cur = 0;
    int l = 1;
    for (int j = 1; j <= m; j++) {
      update(1, 0, m, j, j, dp[i][j]);
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
