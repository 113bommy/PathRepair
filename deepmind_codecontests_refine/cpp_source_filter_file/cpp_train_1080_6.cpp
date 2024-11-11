#include <bits/stdc++.h>
using namespace std;
long long const N = 1e5 + 20;
long long n, m, n_, x[N], last[N], type[N], a[N], b[N], ads[N];
vector<pair<long long, long long> > vec;
struct node {
  long long sz, sum, ans;
  node() { sz = sum = ans = 0; }
} seg[N << 3];
node merge(node x, node y) {
  node ret;
  ret.sz = x.sz + y.sz;
  ret.sum = x.sum + y.sum;
  ret.ans = x.ans + y.ans + x.sz * y.sum - y.sz * x.sum;
  return ret;
}
void build(long long v = 1, long long s = 0, long long e = n) {
  if (s + 1 == e) {
    if (vec[s].second < n_) {
      seg[v].sum = vec[s].first;
      seg[v].sz = 1;
    }
    return;
  }
  long long mid = s + e >> 1, lc = v << 1, rc = lc | 1;
  build(lc, s, mid);
  build(rc, mid, e);
  seg[v] = merge(seg[lc], seg[rc]);
}
node get(long long l, long long r, long long v = 1, long long s = 0,
         long long e = n) {
  if (s >= r || e <= l) {
    node ret;
    return ret;
  }
  if (s >= l && e <= r) return seg[v];
  long long mid = s + e >> 1, lc = v << 1, rc = lc | 1;
  return merge(get(l, r, lc, s, mid), get(l, r, rc, mid, e));
}
void upd(long long idx, long long v = 1, long long s = 0, long long e = n) {
  if (idx < s || idx >= e) return;
  if (s + 1 == e) {
    seg[v].sum = vec[s].first - seg[v].sum;
    seg[v].sz = 1 - seg[v].sz;
    return;
  }
  long long mid = s + e >> 1, lc = v << 1, rc = lc | 1;
  upd(idx, lc, s, mid);
  upd(idx, rc, mid, e);
  seg[v] = merge(seg[lc], seg[rc]);
  return;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
    last[i] = i;
    vec.push_back({x[i], i});
  }
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> type[i] >> a[i] >> b[i];
    if (type[i] == 1) {
      a[i]--;
      x[a[i]] += b[i];
      vec.push_back({x[a[i]], n + i});
    }
  }
  sort(vec.begin(), vec.end());
  n_ = n, n = vec.size();
  build();
  for (long long i = 0; i < n; i++) ads[vec[i].second] = i;
  for (long long i = 0; i < m; i++) {
    if (type[i] == 1) {
      upd(ads[last[a[i]]]);
      upd(ads[n_ + i]);
      last[a[i]] = n_ + i;
    } else {
      long long l = lower_bound(vec.begin(), vec.end(),
                                pair<long long, long long>(a[i], -1)) -
                    vec.begin();
      long long r = lower_bound(vec.begin(), vec.end(),
                                pair<long long, long long>(b[i] + 1, -1)) -
                    vec.begin();
      cout << get(l, r).ans << '\n';
    }
  }
  return 0;
}
