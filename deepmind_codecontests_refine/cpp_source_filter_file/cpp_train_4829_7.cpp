#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
using ll = long long;
int n, kk;
ll a[N];
struct TNode {
  int l, r, v;
} t[N << 2];
int lazy[N << 2];
inline int lc(int pos) { return pos << 1; }
inline int rc(int pos) { return pos << 1 | 1; }
inline void pushup(int pos) { t[pos].v = t[lc(pos)].v + t[rc(pos)].v; }
inline void pushdown(int pos) {
  if (!lazy[pos]) return;
  t[lc(pos)].v = t[lc(pos)].r - t[lc(pos)].l + 1 - t[lc(pos)].v;
  lazy[lc(pos)] ^= 1;
  t[rc(pos)].v = t[rc(pos)].r - t[rc(pos)].l + 1 - t[rc(pos)].v;
  lazy[rc(pos)] ^= 1;
  lazy[pos] = 0;
}
void build(int pos, int l, int r) {
  t[pos].l = l;
  t[pos].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lc(pos), l, mid);
  build(rc(pos), mid + 1, r);
  pushup(pos);
}
void modify(int pos, int l, int r) {
  if (t[pos].l == l && t[pos].r == r) {
    t[pos].v = r - l + 1 - t[pos].v;
    lazy[pos] ^= 1;
    return;
  }
  pushdown(pos);
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (r <= mid)
    modify(lc(pos), l, r);
  else if (l > mid)
    modify(rc(pos), l, r);
  else
    modify(lc(pos), l, mid), modify(rc(pos), mid + 1, r);
  pushup(pos);
}
int query(int pos, int l, int r) {
  if (t[pos].l == l && t[pos].r == r) return t[pos].v;
  pushdown(pos);
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (r <= mid)
    return query(lc(pos), l, r);
  else if (l > mid)
    return query(rc(pos), l, r);
  else
    return query(lc(pos), l, mid) + query(rc(pos), mid + 1, r);
}
struct Query {
  int l, r;
} q[N];
vector<int> v[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  a[n + 1] = LLONG_MAX >> 3;
  build(1, 1, n);
  ll ans = ll(n) * (n - 1) / 2 * (n - 2) / 3;
  int t1, t2;
  for (int i = 1; i <= kk; i++) {
    cin >> t1 >> t2;
    q[i].l = lower_bound(a + 1, a + n + 1, t1) - a;
    q[i].r = upper_bound(a + 1, a + n + 2, t2) - a - 1;
    if (q[i].l > q[i].r) q[i].l = 0;
  }
  sort(q + 1, q + kk + 1, [](Query a, Query b) { return a.l < b.l; });
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    while (q[cur].l == i)
      modify(1, q[cur].l, q[cur].r), v[q[cur].r].push_back(q[cur].l), ++cur;
    ll tmp = 0;
    if (i > 1) tmp += query(1, 1, i - 1);
    if (i < n) tmp += (n - i) - query(1, i + 1, n);
    for (auto &j : v[i]) modify(1, j, i);
    ans -= tmp * (tmp - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
