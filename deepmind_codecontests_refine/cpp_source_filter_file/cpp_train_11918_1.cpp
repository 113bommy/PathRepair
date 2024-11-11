#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 15;
struct node {
  long long pref, suff, tot, sm;
} tree[MAXN << 2];
node operator+(const node&, const node&);
void build(int, int, int);
node query(int, int, int, int, int);
int h[MAXN], d[MAXN];
int n, m, FN;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cerr << "HELLO WORLD :)\n";
  cin >> n >> m;
  FN = (n << 1);
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) cin >> h[i], h[i] <<= 1;
  for (int i = n; i < FN; i++) d[i] = d[i - n], h[i] = h[i - n];
  build(1, 0, FN);
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    if (l < r)
      cout << query(1, 0, FN, r, l + n).tot << ' ';
    else
      cout << query(1, 0, FN, r, l).tot << ' ';
  }
  return false;
}
node operator+(const node& a, const node& b) {
  node ret({});
  ret.pref = max(a.pref, a.sm + b.pref);
  ret.suff = max(b.suff, b.sm + a.suff);
  ret.tot = max({a.tot, b.tot, a.suff + b.pref});
  ret.sm = a.sm + b.sm;
  return ret;
}
void build(int id, int b, int e) {
  if (b == e - 1) {
    tree[id] = {h[b], h[b] + d[b], h[b], d[b]};
    return;
  }
  int mid = (b + e) >> 1;
  build(id << 1, b, mid);
  build(id << 1 | 1, mid, e);
  tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
node query(int id, int b, int e, int l, int r) {
  if (b >= r || e <= l) {
    node ret({-2ll * 1000000 * 1000000 * 100000,
              -2ll * 1000000 * 1000000 * 100000,
              -2ll * 1000000 * 1000000 * 100000, 0});
    return ret;
  }
  if (b >= l && e <= r) return tree[id];
  int mid = (b + e) >> 1;
  return query(id << 1, b, mid, l, r) + query(id << 1 | 1, mid, e, l, r);
}
