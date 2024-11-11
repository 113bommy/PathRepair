#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e5 + 5;
vector<pair<int, int> > tree[maxn << 2];
int tag[maxn << 2];
int n, m, p;
int a[maxn];
vector<pair<int, int> > merge(vector<pair<int, int> > a,
                              vector<pair<int, int> > b) {
  for (auto [x, y] : b) {
    int flag = 0;
    for (auto &[xx, yy] : a) {
      if (xx == x) {
        yy += y, flag = 1;
        break;
      }
    }
    if (flag) continue;
    a.emplace_back(x, y);
    if ((int)a.size() <= p) continue;
    int mn = n;
    for (auto [xx, yy] : a) mn = min(mn, yy);
    vector<pair<int, int> > tmp;
    for (auto [xx, yy] : a)
      if (yy - mn) tmp.emplace_back(xx, yy - mn);
    a = tmp;
  }
  return a;
}
void reset(int t, int len, int num) {
  tree[t].clear();
  tree[t].emplace_back(num, len);
}
void down(int t, int ls, int rs) {
  if (tag[t]) {
    tag[t << 1] = tag[t], tag[t << 1 | 1] = tag[t];
    reset(t << 1, ls, tag[t]), reset(t << 1 | 1, rs, tag[t]);
    tag[t] = 0;
  }
}
void build(int l, int r, int t) {
  if (l == r) {
    tree[t].emplace_back(a[l], 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, t << 1);
  build(mid + 1, r, t << 1 | 1);
  tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
}
void modify(int ll, int rr, int l, int r, int num, int t) {
  if (ll <= l && r <= rr) {
    reset(t, r - l + 1, num), tag[t] = num;
    return;
  }
  int mid = (l + r) >> 1;
  down(t, mid - l + 1, r - mid);
  if (ll <= mid) modify(ll, rr, l, mid, num, t << 1);
  if (rr > mid) modify(ll, rr, mid + 1, r, num, t << 1 | 1);
  tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
}
vector<pair<int, int> > query(int ll, int rr, int l, int r, int t) {
  if (ll <= l && r <= rr) return tree[t];
  int mid = (l + r) >> 1;
  down(t, mid - l + 1, r - mid);
  vector<pair<int, int> > tmp;
  if (ll <= mid) tmp = merge(tmp, query(ll, rr, l, mid, t << 1));
  if (rr > mid) tmp = merge(tmp, query(ll, rr, mid + 1, r, t << 1 | 1));
  return tmp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> p;
  p = 100 / p;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, n, 1);
  for (int i = 1; i <= m; ++i) {
    int opt, l, r, v;
    cin >> opt >> l >> r;
    if (opt == 1) {
      cin >> v;
      modify(l, r, 1, n, v, 1);
    } else {
      auto ans = query(l, r, 1, n, 1);
      cout << ans.size() << ' ';
      for (auto [x, y] : ans) cout << x << ' ';
      cout << '\n';
    }
  }
  return 0;
}
