#include <bits/stdc++.h>
using namespace std;
int lg(long long n) {
  assert(n > 0);
  int ans = -1;
  while (n) {
    ans++;
    n >>= 1;
  }
  return ans;
}
struct SegmentTree {
  int n;
  vector<long long> mn, add;
  SegmentTree(int n) : n(n), mn(4 * n, 0), add(4 * n) {}
  void Add(int id, int l, int r, long long val) {
    add[id] += val;
    mn[id] += val;
  }
  void push(int id, int l, int r) {
    if (add[id] != 0) {
      int m = (l + r) >> 1;
      Add(id << 1, l, m, add[id]);
      Add(id << 1 | 1, m + 1, r, add[id]);
      add[id] = 0;
    }
  }
  void pull(int id) { mn[id] = min(mn[id << 1], mn[id << 1 | 1]); }
  SegmentTree(const vector<int> &v) {
    n = (int)v.size();
    mn.resize(4 * n);
    add.resize(4 * n);
    function<void(int, int, int)> build = [&](int id, int l, int r) {
      if (l == r) {
        mn[id] = v[l];
        return;
      }
      int m = (l + r) >> 1;
      build(id << 1, l, m);
      build(id << 1 | 1, m + 1, r);
      pull(id);
    };
    build(1, 0, n - 1);
  }
  void RangeAdd(int id, int l, int r, int ql, int qr, long long val) {
    if (l > qr || r < ql) return;
    if (ql <= l && qr >= r) {
      Add(id, l, r, val);
      return;
    }
    push(id, l, r);
    int m = (l + r) >> 1;
    RangeAdd(id << 1, l, m, ql, qr, val);
    RangeAdd(id << 1 | 1, m + 1, r, ql, qr, val);
    pull(id);
  }
  void RangeAdd(int ql, int qr, long long val) {
    RangeAdd(1, 0, n - 1, ql, qr, val);
  }
  long long GetMin(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 9e18;
    if (ql <= l && qr >= r) return mn[id];
    push(id, l, r);
    int m = (l + r) >> 1;
    return min(GetMin(id << 1, l, m, ql, qr),
               GetMin(id << 1 | 1, m + 1, r, ql, qr));
  }
  long long GetMin(int ql, int qr) { return GetMin(1, 0, n - 1, ql, qr); }
  long long GetEle(int pos) { return GetMin(1, 0, n - 1, pos, pos); }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> e(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int T = 0;
  vector<int> tin(n), tout(n), h(n);
  function<void(int, int)> dfs = [&](int cur, int fa) {
    tin[cur] = T++;
    for (int nxt : e[cur]) {
      if (nxt == fa) continue;
      h[nxt] = h[cur] + 1;
      dfs(nxt, cur);
    }
    tout[cur] = T - 1;
  };
  h[0] = 0;
  dfs(0, -1);
  SegmentTree st(n);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, val;
      cin >> x >> val;
      x--;
      int sign = (h[x] & 1 ? -1 : 1);
      st.RangeAdd(tin[x], tout[x], sign * val);
    } else if (op == 2) {
      int x;
      cin >> x;
      x--;
      int sign = (h[x] & 1 ? -1 : 1);
      cout << a[x] + sign * st.GetEle(tin[x]) << '\n';
    } else
      assert(false);
  }
  return 0;
}
