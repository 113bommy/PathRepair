#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
int a[MAXN + 1];
bool dp[MAXN + 1];
bool tree[4 * MAXN];
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
void update(int v, int l, int r, int pos, bool val) {
  if (l == r) {
    tree[v] = dp[l] = val;
  } else {
    int mid = (l + r) >> 1;
    int L = (v << 1) | 1, R = (L | 1) + 1;
    if (pos <= mid)
      update(L, l, mid, pos, val);
    else
      update(R, mid + 1, r, pos, val);
    tree[v] = tree[L] | tree[R];
  }
}
bool query(int v, int tl, int tr, int l, int r) {
  if (l > tr or r < tl) return 0;
  if (l <= tl and r >= tr) return 1;
  int mid = (tl + tr) >> 1;
  int L = (v << 1) | 1, R = (L | 1) + 1;
  return query(L, tl, mid, l, r) | query(R, mid + 1, tr, l, r);
}
int main() {
  fast_io();
  int n, k, d;
  cin >> n >> k >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);
  update(0, 0, n, 0, 1);
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(a, a + n + 1, a[i] - d) - a;
    if (i - pos + 1 < k) continue;
    dp[i] = query(0, 0, n, pos - 1, i - k);
    update(0, 0, n, i, dp[i]);
  }
  cout << (dp[n] ? "YES" : "NO") << '\n';
  return 0;
}
