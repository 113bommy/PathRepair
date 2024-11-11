#include <bits/stdc++.h>
using namespace std;
int n, k, a[35005], last[35005], tree[140005], lazy[140005], f[35005][55];
void Down(int k) {
  tree[2 * k] += lazy[k];
  tree[2 * k + 1] += lazy[k];
  lazy[2 * k] += lazy[k];
  lazy[2 * k + 1] += lazy[k];
  lazy[k] = 0;
}
void Update(int k, int l, int r, int L, int R, int val) {
  if (l > R || L > r) return;
  if (L <= l && r <= R) {
    tree[k] += val;
    lazy[k] += val;
    return;
  }
  Down(k);
  int mid = (l + r) / 2;
  Update(2 * k, l, mid, L, R, val);
  Update(2 * k + 1, mid + 1, r, L, R, val);
  tree[k] = max(tree[2 * k], tree[2 * k + 1]);
}
int Query(int k, int l, int r, int L, int R) {
  if (l > R || L > r) return 0;
  if (L <= l && r <= R) return tree[k];
  Down(k);
  int mid = (l + r) / 2;
  return max(Query(2 * k, l, mid, L, R), Query(2 * k + 1, mid + 1, r, L, R));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n; j++) last[j] = 0;
    for (int j = 0; j <= 4 * n; j++) {
      tree[j] = 0;
      lazy[j] = 0;
    }
    for (int j = 1; j <= n; j++) {
      Update(1, 0, n, last[a[j]], j - 1, 1);
      f[i][j] = Query(1, 0, n, 0, j - 1);
      Update(1, 0, n, j, j, f[i - 1][j]);
      last[a[j]] = j;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, f[k][i]);
  cout << res;
}
