#include <bits/stdc++.h>
using namespace std;
struct Data {
  int l, r, w;
  Data(int a, int b, int c) {
    l = a;
    r = b;
    w = c;
  }
  Data(){};
};
bool cmp(Data a, Data b) { return a.w < b.w; }
int tree[4 * 1000005], lazy[4 * 1000005];
void push(int indx) {
  tree[2 * indx] += lazy[indx];
  tree[2 * indx + 1] += lazy[indx];
  lazy[2 * indx] += lazy[indx];
  lazy[2 * indx + 1] += lazy[indx];
  lazy[indx] = 0;
}
void update(int node, int st, int en, int l, int r, int val) {
  if (st > r || en < l) return;
  if (st >= l && en <= r) {
    lazy[node] += val;
    tree[node] += val;
  } else {
    int mid = (st + en) / 2;
    push(node);
    update(2 * node, st, mid, l, r, val);
    update(2 * node + 1, mid + 1, en, l, r, val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}
int query(int node, int st, int en, int l, int r) {
  if (st > r || en < l) return 1e8;
  if (st >= l && en <= r) {
    return tree[node];
  }
  int m = (st + en) / 2;
  push(node);
  return min(query(2 * node, st, m, l, r),
             query(2 * node + 1, m + 1, en, l, r));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  std::vector<Data> v(n);
  for (int i = 0; i < n; ++i) {
    int l, r, w;
    cin >> l >> r >> w;
    v[i] = Data(l, r, w);
  }
  sort(v.begin(), v.end(), cmp);
  int i = 0, j = 0, ans = 1e9;
  while (j < n) {
    int a = v[j].l;
    if (a != 1) ++a;
    update(1, 1, m, a, v[j].r, 1);
    ++j;
    int x = query(1, 1, m, 1, m);
    while (x != 0) {
      ans = min(ans, v[j - 1].w - v[i].w);
      a = v[i].l;
      int b = v[i].r;
      if (a != 1) ++a;
      if (a <= b) update(1, 1, m, a, b, -1);
      ++i;
      x = query(1, 1, m, 1, m);
    }
  }
  cout << ans << '\n';
  return 0;
}
