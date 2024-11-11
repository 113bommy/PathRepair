#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int inf = 1e9 + 3;
const int md = 1e9 + 7;
struct node {
  int left, right;
  int res, len;
};
node combine(node a, node b) {
  node c;
  c.len = a.len + b.len;
  c.res = max(a.res, b.res);
  c.res = max(c.res, a.right + b.left);
  c.left = a.left;
  c.right = b.right;
  if (b.right == b.len) {
    c.right = b.right + a.right;
  }
  if (a.left == a.len) {
    c.left = a.left + b.left;
  }
  return c;
}
int n, m, l, r, w, l1, r1, mid1, nm, sz;
int h[N];
pair<int, int> a[N];
int root[N];
node d[N * (31)];
int le[N * 31], ri[N * 31];
int copy(int v) {
  nm++;
  d[nm] = d[v];
  le[nm] = le[v];
  ri[nm] = ri[v];
  return nm;
}
void update(int v, int l, int r, int ps) {
  if (l == r) {
    d[v] = {1, 1, 1, 1};
    return;
  }
  int mid = (l + r) / 2;
  if (ps <= mid) {
    le[v] = copy(le[v]);
    update(le[v], l, mid, ps);
  } else {
    ri[v] = copy(ri[v]);
    update(ri[v], mid + 1, r, ps);
  }
  d[v] = combine(d[le[v]], d[ri[v]]);
}
node get_res(int v, int l, int r, int l_v, int r_v) {
  if (l > r_v || r < l_v) return {0, 0, 0, 0};
  if (l >= l_v && r <= r_v) return d[v];
  int mid = (l + r) / 2;
  return combine(get_res(le[v], l, mid, l_v, r_v),
                 get_res(ri[v], mid + 1, r, l_v, r_v));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  sz = 1;
  while (sz < n) sz += sz;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    a[i] = make_pair(-h[i], i);
  }
  sort(a + 1, a + n + 1);
  nm = sz * 2 - 1;
  for (int i = 1; i < sz; ++i) le[i] = i + i, ri[i] = i + i + 1;
  for (int i = 1; i <= sz; ++i) {
    d[i + sz - 1] = {0, 0, 0, 1};
  }
  for (int i = sz - 1; i >= 1; i--) d[i] = combine(d[i + i], d[i + i + 1]);
  root[0] = 1;
  for (int i = 1; i <= n; ++i) {
    root[i] = copy(root[i - 1]);
    update(root[i], 1, sz, a[i].second);
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r >> w;
    l1 = 1;
    r1 = n;
    while (l1 < r1) {
      mid1 = (l1 + r1) / 2;
      if (get_res(root[mid1], 1, sz, l, r).res >= w)
        r1 = mid1;
      else
        l1 = mid1 + 1;
    }
    cout << -a[l1].first << '\n';
  }
}
