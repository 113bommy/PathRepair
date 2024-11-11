#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
int n, kk, w[N], g[N], stk[N], top, ans = 1, nxt[N];
ll suf[N], pre[N], dep[N], mn[N], ord[N];
vector<int> r[N];
struct SegTree {
  int cnt, opl, opr;
  ll mn[N << 2], opv;
  SegTree() { memset(mn, 63, sizeof(mn)); }
  inline int lc(int pos) { return pos << 1; }
  inline int rc(int pos) { return pos << 1 | 1; }
  void ins(int pos, int l, int r) {
    if (l == r) {
      mn[pos] = opv;
      return;
    }
    int mid = (l + r) >> 1;
    if (opl <= mid)
      ins(lc(pos), l, mid);
    else
      ins(rc(pos), mid + 1, r);
    mn[pos] = min(mn[lc(pos)], mn[rc(pos)]);
  }
  inline void ins(int x, ll v) {
    opl = x;
    opv = v;
    ins(1, 1, n + 1);
  }
  ll query(int pos, int l, int r) {
    if (opl > opr || opl > r || opr < l) return LLONG_MAX >> 2;
    if (opl <= l && opr >= r) return mn[pos];
    int mid = (l + r) >> 1;
    ll v1 = LLONG_MAX >> 2, v2 = LLONG_MAX >> 2;
    if (opl <= mid) v1 = query(lc(pos), l, mid);
    if (opr > mid) v2 = query(rc(pos), mid + 1, r);
    return min(v1, v2);
  }
  int queryr(int pos, int l, int r) {
    if (opl > opr || l > opr || r < opl || mn[pos] > opv) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int rt = queryr(rc(pos), mid + 1, r);
    if (rt >= 0) return rt;
    return queryr(lc(pos), l, mid);
  }
  inline ll query(int l, int r) {
    opl = l;
    opr = r;
    return query(1, 1, n + 1);
  }
  inline int queryr(int l, int r, ll v) {
    opl = l;
    opr = r;
    opv = v;
    return queryr(1, 1, n + 1);
  }
} t0, t;
void dfs(int pos, int ptr) {
  stk[++top] = pos;
  ord[top] = dep[pos];
  while (ord[ptr] < dep[pos] - kk) ++ptr;
  t.ins(top, min(mn[pos] + dep[pos], suf[nxt[pos]] + ord[top - 1]));
  ll qq = min(t.query(ptr + 1, top), mn[stk[pos]] + ord[pos]);
  ans = max(ans, t0.queryr(pos + 1, stk[ptr - 1], qq + kk - dep[pos]) - pos);
  for (auto &i : r[pos]) dfs(i, ptr);
  --top;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk;
  for (int i = 1; i < n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) cin >> g[i];
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + g[i] - w[i];
  t0.ins(n + 1, 0);
  for (int i = n; i > 0; --i) t0.ins(i, suf[i] = suf[i + 1] + g[i] - w[i - 1]);
  stk[top = 0] = n + 1;
  for (int i = n; i > 0; --i) {
    while (top && pre[stk[top - 1]] >= pre[i - 1]) --top;
    nxt[i] = stk[top];
    if (top)
      dep[i] = dep[nxt[i]] + pre[i - 1] - pre[nxt[i] - 1];
    else
      dep[i] = 0;
    r[nxt[i]].push_back(i);
    stk[++top] = i;
    mn[i] = t0.query(i + 1, nxt[i]);
  }
  top = 0;
  for (int i = 1; i <= n; i++)
    if (nxt[i] == n + 1) dfs(i, 1);
  cout << ans << endl;
  return 0;
}
