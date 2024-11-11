#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct segtree {
  int n;
  vector<int> st, lazy;
  segtree(int n) {
    this->n = n;
    st.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);
  }
  inline void change(int id) { st[id] += lazy[id]; }
  inline void push(int id) {
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
  }
  inline void reset(int id) { lazy[id] = 0; }
  inline void renew(int id) { st[id] = max(st[id * 2], st[id * 2 + 1]); }
  void update(int l, int r, int val, int id, int u, int v) {
    if (lazy[id]) {
      change(id);
      if (u != v) push(id);
      reset(id);
    }
    if (r < u || v < l) return;
    if (l <= u && v <= r) {
      lazy[id] += val;
      change(id);
      if (u != v) push(id);
      reset(id);
      return;
    }
    int mid = (u + v) / 2;
    update(l, r, val, id * 2, u, mid);
    update(l, r, val, id * 2 + 1, mid + 1, v);
    renew(id);
  }
  inline void update(int l, int r, int val) { update(l, r, val, 1, 1, n); }
  int query(int l, int r, int id, int u, int v) {
    if (lazy[id]) {
      change(id);
      if (u != v) push(id);
      reset(id);
    }
    if (r < u || v < l) return -INF;
    if (l <= u && v <= r) return st[id];
    int mid = (u + v) / 2;
    int lv = query(l, r, id * 2, u, mid);
    int rv = query(l, r, id * 2 + 1, mid + 1, v);
    renew(id);
    return max(lv, rv);
  }
  inline int query(int l, int r) { return query(l, r, 1, 1, n); }
};
const int nax = 3e5 + 5;
int a[nax];
vector<pair<int, int>> query[nax];
int n, q;
int ans[nax];
segtree st(nax);
bool chk(int pos, int val) { return st.query(pos, pos) >= val; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    a[i] = i - a[i];
    if (a[i] < 0) a[i] = nax;
  }
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    y = n - y;
    query[y].emplace_back(x + 1, i);
  }
  for (int r = 1; r <= n; ++r) {
    int low = 1, high = r;
    int rightmost = r + 1;
    while (high >= low) {
      int mid = (low + high) / 2;
      bool status = chk(mid, a[r]);
      if (status) {
        rightmost = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    if (rightmost > r)
      ;
    else {
      st.update(1, rightmost, 1);
    }
    for (auto &p : query[r]) {
      ans[p.second] = st.query(p.first, p.first);
    }
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
  return 0;
}
