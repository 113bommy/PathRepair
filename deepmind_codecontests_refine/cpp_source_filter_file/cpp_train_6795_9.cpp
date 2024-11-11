#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int base = 19260817;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const double eps = 1e-8;
inline int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
inline int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) { return 1LL * x * y % mod; }
int a[maxn], pre[maxn], last[maxn];
int mn[maxn << 2], cnt[maxn << 2], tag[maxn << 2];
void pushup(int o) {
  mn[o] = min(mn[o << 1], mn[o << 1 | 1]);
  cnt[o] = (mn[o << 1] <= mn[o << 1 | 1] ? cnt[o << 1] : 0) +
           (mn[o << 1 | 1] <= mn[o << 1] ? cnt[o << 1 | 1] : 0);
}
void build(int o, int l, int r) {
  if (l == r) {
    cnt[o] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
  pushup(o);
}
void pushdown(int o) {
  if (tag[o]) {
    mn[o << 1] += tag[o], tag[o << 1] += tag[o];
    mn[o << 1 | 1] += tag[o], tag[o << 1 | 1] += tag[o];
    tag[o] = 0;
  }
}
void update(int o, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    mn[o] += v, tag[o] += v;
    return;
  }
  pushdown(o);
  int mid = (l + r) >> 1;
  if (ll <= mid) update(o << 1, l, mid, ll, rr, v);
  if (rr > mid) update(o << 1 | 1, mid + 1, r, ll, rr, v);
  pushup(o);
}
pair<int, int> query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) return pair<int, int>{mn[o], cnt[o]};
  pushdown(o);
  int mid = (l + r) >> 1;
  int lmn = INT_MAX, lcnt = 0, rmn = INT_MAX, rcnt = 0;
  if (ll <= mid) tie(lmn, lcnt) = query(o << 1, l, mid, ll, rr);
  if (rr > mid) tie(rmn, rcnt) = query(o << 1 | 1, mid + 1, r, ll, rr);
  return pair<int, int>{min(lmn, rmn),
                        (lmn <= rmn ? lcnt : 0) + (rmn <= lmn ? rcnt : 0)};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  fill(last + 1, last + n + 1, 0);
  long long ans = 0;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (pre[pre[pre[last[a[i]]]]])
      update(1, 1, n, 1, pre[pre[pre[last[a[i]]]]], -1);
    if (last[a[i]]) update(1, 1, n, pre[pre[last[a[i]]]], last[a[i]], -1);
    if (pre[pre[pre[i]]]) update(1, 1, n, 1, pre[pre[pre[i]]], 1);
    update(1, 1, n, pre[pre[i]] + 1, i, 1);
    last[a[i]] = i;
    pair<int, int> res = query(1, 1, n, 1, i);
    if (!res.first) ans += res.second;
  }
  cout << ans;
  return 0;
}
