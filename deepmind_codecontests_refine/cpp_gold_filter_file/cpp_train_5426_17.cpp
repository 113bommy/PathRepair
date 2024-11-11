#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7, K = 16, INF = 1e9 + 7;
pair<int, int> combine(const pair<int, int> &a, const pair<int, int> &b) {
  return pair<int, int>(min(a.first, b.first), max(a.second, b.second));
}
struct SegTree {
  int n;
  vector<pair<int, int> > tr;
  SegTree(){};
  SegTree(int n, pair<int, int> *a) : n(n), tr(4 * n) { build(1, 0, n - 1, a); }
  void build(int u, int st, int en, pair<int, int> *a) {
    if (st == en) {
      tr[u] = a[st];
    } else {
      int mid = (st + en) / 2;
      build(2 * u, st, mid, a);
      build(2 * u + 1, mid + 1, en, a);
      tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
    }
  }
  pair<int, int> query(int u, int st, int en, int l, int r) {
    if (r < st || en < l)
      return {INF, -INF};
    else if (l <= st && en <= r)
      return tr[u];
    else {
      int mid = (st + en) / 2;
      return combine(query(2 * u, st, mid, l, r),
                     query(2 * u + 1, mid + 1, en, l, r));
    }
  }
  pair<int, int> query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
int a[N];
pair<int, int> range[K][N];
SegTree tr[K];
int solve(int i, int d) {
  if (d == 0) return 0;
  int ans = 0;
  int cl = i, cr = i;
  for (int i = K - 1; i >= 0; i--) {
    pair<int, int> pr = tr[i].query(cl, cr);
    if (pr.second - pr.first >= d) continue;
    cl = pr.first;
    cr = pr.second;
    ans += 1 << i;
  }
  return ans + 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n; i < 3 * n; i++) a[i] = a[i - n];
  for (int i = 0; i < 3 * n; i++) {
    range[0][i].first = max(0, i - a[i]);
    range[0][i].second = min(3 * n - 1, i + a[i]);
  }
  tr[0] = SegTree(3 * n, range[0]);
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < 3 * n; i++) {
      range[k][i] =
          tr[k - 1].query(range[k - 1][i].first, range[k - 1][i].second);
    }
    tr[k] = SegTree(3 * n, range[k]);
  }
  for (int i = n; i < 2 * n; i++) cout << solve(i, n - 1) << " ";
}
