#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
const int sz = 30 * N;
struct item {
  int l, r, p;
};
bool operator<(const item &a, const item &b) { return a.l < b.l; };
int n, m, k, tree[sz], lc[sz], rc[sz], root[sz], cn;
vector<item> s;
void build(int l, int r, int node) {
  tree[node] = 1e9;
  if (l == r) return;
  int mid = (l + r) / 2;
  lc[node] = cn++;
  rc[node] = cn++;
  build(l, mid, lc[node]);
  build(mid + 1, r, rc[node]);
}
void update(int l, int r, int node, int node2, int ind, int val) {
  tree[node] = tree[node2];
  if (l == r) {
    tree[node] = min(tree[node], val);
    return;
  }
  int mid = (l + r) / 2;
  if (ind <= mid) {
    lc[node] = cn++;
    rc[node] = rc[node2];
    update(l, mid, lc[node], lc[node2], ind, val);
  } else {
    lc[node] = lc[node2];
    rc[node] = cn++;
    update(mid + 1, r, rc[node], rc[node2], ind, val);
  }
  tree[node] = max(tree[lc[node]], tree[rc[node]]);
}
int query(int l, int r, int node, int s, int e) {
  if (r < l || r < s || l > e) return 0;
  if (s <= l && r <= e) return tree[node];
  int mid = (l + r) / 2;
  return max(query(l, mid, lc[node], s, e), query(mid + 1, r, rc[node], s, e));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  root[0] = cn++;
  build(1, n, root[0]);
  s.push_back({-1, -1, -1});
  for (int i = 0; i < k; i++) {
    int l, r, p;
    cin >> l >> r >> p;
    s.push_back({l, r, p});
  }
  sort(s.begin(), s.end());
  for (int i = k; i >= 1; i--) {
    root[i] = cn++;
    update(1, n, root[i], root[i == k ? 0 : i + 1], s[i].p, s[i].r);
  }
  while (m--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    item r = {x, -1, -1};
    int ind = lower_bound(s.begin(), s.end(), r) - s.begin();
    if (ind == s.size()) {
      cout << "no" << endl;
      continue;
    }
    int v = query(1, n, root[ind], a, b);
    if (v <= y)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
