#include <bits/stdc++.h>
using namespace std;
long long INF = 1e10;
void mmin(long long &a, long long b) { a = min(a, b); }
struct Node {
  long long tl, tr;
  long long val;
  Node *lnode, *rnode;
  Node(long long tl, long long tr) : tl(tl), tr(tr) {
    val = INF;
    lnode = NULL;
    rnode = NULL;
  }
  void upd(long long pos, long long new_val) {
    if (tl == tr) {
      mmin(val, new_val);
      return;
    }
    long long tm = (tl + tr) >> 1;
    if (pos <= tm) {
      if (lnode == NULL) lnode = new Node(tl, tm);
      lnode->upd(pos, new_val);
    } else {
      if (rnode == NULL) rnode = new Node(tm + 1, tr);
      rnode->upd(pos, new_val);
    }
    val = INF;
    if (lnode != NULL) mmin(val, lnode->val);
    if (rnode != NULL) mmin(val, rnode->val);
  }
  long long get(long long l, long long r) {
    if (l > r) return INF;
    if (l == tl && r == tr) return val;
    long long ret = INF;
    long long tm = (tl + tr) >> 1;
    if (l <= tm && lnode != NULL) mmin(ret, lnode->get(l, min(tm, r)));
    if (r >= tm + 1 && rnode != NULL) mmin(ret, rnode->get(max(tm + 1, l), r));
    return ret;
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Node *dp = new Node(-INF, INF);
  Node *dp2 = new Node(-INF, INF);
  dp->upd(-INF, 0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < int(n); ++i) cin >> a[i];
  long long prev = INF;
  long long last_dp2 = INF;
  long long last_prev = INF;
  for (int i = 0; i < n; ++i) {
    long long v;
    v = dp2->get(-INF, a[i] - i) - 1;
    if (i) {
      long long cur = dp->get(-INF, a[i] - i + 1LL) - 2;
      mmin(v, cur);
    }
    last_dp2 = v;
    dp2->upd(a[i] - i, v);
    last_prev = prev;
    v = dp->get(-INF, a[i] - i) - 1;
    if (i && a[i - 1] < a[i]) mmin(v, prev - 1);
    if (i) dp->upd(a[i - 1] - i + 1, prev);
    prev = v;
  }
  long long ans = n + min(min(last_dp2, last_prev - 1), prev);
  mmin(ans, n + dp->get(-INF, INF));
  mmin(ans, n + dp2->get(-INF, INF));
  cout << ans;
}
