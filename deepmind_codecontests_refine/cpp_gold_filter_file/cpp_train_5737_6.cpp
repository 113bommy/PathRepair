#include <bits/stdc++.h>
using namespace std;
using seg = pair<int, int>;
using ll = long long;
seg intersect(seg a, seg b) {
  seg ret = {max(a.first, b.first), min(a.second, b.second)};
  if (ret.first > ret.second) return {-1, -1};
  return ret;
}
inline int len(const seg& a) { return a.second - a.first; }
const int inf = 1234567890;
struct node {
  int l, r;
  seg x;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0, inf) {}
  node(int _l, int _r, const seg& _x) : node(_l, _r) { x = _x; }
  node(node a, node b) : node(a.l, b.r) { x = intersect(a.x, b.x); }
  void update(const seg& v) { x = v; }
};
struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree(const vector<seg>& a) : n(a.size()), arr(4 * n) {
    mk(a, 0, 0, n - 1);
  }
  node mk(const vector<seg>& a, int i, int l, int r) {
    int m = (l + r) / 2;
    return arr[i] = l > r    ? node(l, r)
                    : l == r ? node(l, r, a[l])
                             : node(mk(a, 2 * i + 1, l, m),
                                    mk(a, 2 * i + 2, m + 1, r));
  }
  node update(int at, seg v, int i = 0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(v);
      return arr[i];
    }
    return arr[i] = node(update(at, v, 2 * i + 1), update(at, v, 2 * i + 2));
  }
  node query(int l, int r, int i = 0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl, hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l, r, 2 * i + 1), query(l, r, 2 * i + 2));
  }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<seg> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  segment_tree st(a);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    st.update(i, seg(0, inf));
    mx = max(mx, len(st.query(0, n - 1).x));
    st.update(i, a[i]);
  }
  cout << mx << '\n';
  return 0;
}
