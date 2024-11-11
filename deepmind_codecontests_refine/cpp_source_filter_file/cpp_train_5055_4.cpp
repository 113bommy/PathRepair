#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 1e9 + 100;
int lazy[4 * N], n, a[N];
struct node {
  int sz, mn[2], sum;
  void add(int val) {
    if (sz & 1) sum += val;
    mn[1] += val;
  }
  node() {
    sz = -1;
    mn[0] = mn[1] = -1;
    sum = -1;
  }
  node(const node &a) {
    sz = a.sz;
    mn[0] = a.mn[0];
    mn[1] = a.mn[1];
    sum = a.sum;
  }
} seg[4 * N];
node merge(node a, node b) {
  node ret;
  if (b.sz == -1) return a;
  if (a.sz == -1) return b;
  ret.mn[(b.sz & 1)] = a.mn[0] + b.sum;
  ret.mn[(b.sz & 1) ^ 1] = a.mn[1] - b.sum;
  ret.mn[0] = min(ret.mn[0], b.mn[0]);
  ret.mn[1] = min(ret.mn[1], b.mn[1]);
  int mul = a.sz % 2 == 0 ? 1 : -1;
  ret.sum = a.sum + mul * b.sum;
  ret.sz = a.sz + b.sz;
  return ret;
}
void shift(int id) {
  lazy[2 * id] += lazy[id];
  lazy[2 * id + 1] += lazy[id];
  seg[2 * id].add(lazy[id]);
  seg[2 * id + 1].add(lazy[id]);
  lazy[id] = 0;
}
void build(int s = 0, int e = n, int id = 1) {
  if (e - s == 1) {
    lazy[id] = 0;
    seg[id].sz = 1;
    seg[id].mn[0] = INF;
    seg[id].mn[1] = a[s];
    seg[id].sum = a[s];
    return;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * id);
  build(mid, e, 2 * id + 1);
  seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
}
void upd(int l, int r, int val, int s = 0, int e = n, int id = 1) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    lazy[id] += val;
    seg[id].add(val);
    return;
  }
  shift(id);
  int mid = (s + e) / 2;
  upd(l, r, val, s, mid, 2 * id);
  upd(l, r, val, mid, e, 2 * id + 1);
  seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
}
node get(int l, int r, int s = 0, int e = n, int id = 1) {
  if (r <= s || e <= l) return node();
  if (l <= s && e <= r) return seg[id];
  shift(id);
  int mid = (s + e) / 2;
  return merge(get(l, r, s, mid, 2 * id), get(l, r, mid, e, 2 * id + 1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  int q;
  cin >> q;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    b++;
    if (t == 1) {
      int k;
      cin >> k;
      upd(a, b, k);
    } else {
      node cur = get(a, b);
      int eq = (cur.sz & 1) ? 1 : -1;
      cout << (cur.mn[0] >= -1 && cur.mn[1] >= 1 && cur.sum == eq) << "\n";
    }
  }
  return 0;
}
