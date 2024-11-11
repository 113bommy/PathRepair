#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 2e5 + 100;
const long long INF = 1e18;
long long x[N], p[N], a[N];
struct node {
  long long ans = 0, pref = 0, suff = 0, sum = 0;
  node() {}
  node(long long x) {
    pref = suff = sum = x;
    ans = max(x, 0ll);
  }
} t[4 * N];
node merge(node l, node r) {
  node ret;
  ret.ans = max(l.ans, r.ans);
  ret.pref = max(l.pref, l.sum + r.pref);
  ret.suff = max(r.suff, r.sum + l.suff);
  ret.sum = l.sum + r.sum;
  ret.ans = max({ret.ans, ret.pref, ret.suff});
  ret.ans = max(ret.ans, l.suff + r.pref);
  return ret;
}
void build(long long v, long long l, long long r) {
  if (l + 1 == r) {
    t[v] = node(a[l]);
    return;
  }
  long long mid = (l + r) / 2;
  build(v * 2 + 1, l, mid);
  build(v * 2 + 2, mid, r);
  t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}
node qu(long long v, long long l, long long r, long long ql, long long qr) {
  if (qr <= l || r <= ql) return node();
  if (ql <= l && r <= qr) return t[v];
  long long mid = (l + r) / 2;
  return merge(qu(v * 2 + 1, l, mid, ql, qr), qu(v * 2 + 2, mid, r, ql, qr));
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m, c;
  cin >> n >> m >> c;
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
  }
  n--;
  for (long long i = 0; i < n; i++) {
    x[i] = 50 * (x[i + 1] - x[i]);
  }
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (long long i = 0; i < n; i++) {
    a[i] = (x[i] - p[i] * c);
  }
  build(0, 0, n);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    ans += qu(0, 0, n, l, r).ans;
  }
  cout << fixed << setprecision(20) << ans / 100.0 << '\n';
}
