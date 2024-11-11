#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 15, K = 20;
int a[N];
int tr[4 * N];
void build(int u, int st, int en) {
  if (st == en) {
    tr[u] = st;
  } else {
    int mid = (st + en) / 2;
    build(2 * u, st, mid);
    build(2 * u + 1, mid + 1, en);
  }
}
void update(int u, int st, int en, int l, int r, int x) {
  if (r < st || en < l)
    return;
  else if (l <= st && en <= r) {
    tr[u] = max(tr[u], x);
  } else {
    int mid = (st + en) / 2;
    update(2 * u, st, mid, l, r, x);
    update(2 * u + 1, mid + 1, en, l, r, x);
  }
}
int query(int u, int st, int en, int idx) {
  if (st == en)
    return tr[u];
  else {
    int mid = (st + en) / 2;
    if (idx <= mid)
      return max(tr[u], query(2 * u, st, mid, idx));
    else
      return max(tr[u], query(2 * u + 1, mid + 1, en, idx));
  }
}
int r[N][K];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m = 500005;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    update(1, 1, m, l, r, r);
  }
  for (int i = 1; i <= m; i++) r[i][0] = query(1, 1, m, i);
  for (int k = 1; k < K; k++)
    for (int i = 1; i <= m; i++) r[i][k] = r[r[i][k - 1]][k - 1];
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (r[x][K - 1] < y)
      cout << -1 << "\n";
    else {
      int ans = 0, cur = x;
      for (int i = K - 1; i >= 0; i--) {
        if (r[cur][i] >= y) continue;
        ans += 1 << i;
        cur = r[cur][i];
      }
      cout << ans + 1 << "\n";
    }
  }
}
