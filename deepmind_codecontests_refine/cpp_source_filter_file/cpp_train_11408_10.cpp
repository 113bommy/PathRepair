#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, wh;
} b[300012 * 3];
int n, a[300012], m, rt[300012], ls[300012 * 40], rs[300012 * 40],
    he[300012 * 40], js, ans[300012 * 3], s[300012], tot, id[300012];
vector<int> v[300012];
void chng(int &o, int ind, int l, int r, int x) {
  o = ++js;
  ls[o] = ls[ind], rs[o] = rs[ind], he[o] = he[ind] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    chng(ls[o], ls[ind], l, mid, x);
  else
    chng(rs[o], rs[ind], mid + 1, r, x);
}
int getrk(int id1, int id2, int l, int r, int x) {
  if (l == r) return he[id2] - he[id1];
  int mid = (l + r) >> 1;
  if (x <= mid)
    return getrk(ls[id1], ls[id2], l, mid, x);
  else
    return he[ls[id2]] - he[ls[id1]] + getrk(rs[id1], rs[id2], mid + 1, r, x);
}
int getkth(int id1, int id2, int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1, lh = he[ls[id2]] - he[ls[id1]];
  if (k <= lh)
    return getkth(ls[id1], ls[id2], l, mid, k);
  else
    return getkth(rs[id1], rs[id2], mid + 1, r, k - lh);
}
void ins(int &o, int l, int r, int x, int y) {
  if (!o) o = ++js;
  he[o] = min(he[o], y);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    ins(ls[o], l, mid, x, y);
  else
    ins(rs[o], mid + 1, r, x, y);
}
int qry(int ind, int l, int r, int al, int ar) {
  if (!ind) return 2e9;
  if (al <= l && r <= ar) return he[ind];
  int mid = (l + r) >> 1, ret = 2e9;
  if (al <= mid) ret = min(ret, qry(ls[ind], l, mid, al, ar));
  if (ar > mid) ret = min(ret, qry(rs[ind], mid + 1, r, al, ar));
  return ret;
}
inline bool cmp(node n1, node n2) { return n1.r < n2.r; }
inline bool mmp(int x, int y) { return a[x] < a[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = a[i];
  sort(s + 1, s + 1 + n);
  tot = unique(s + 1, s + 1 + n) - s - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(s + 1, s + 1 + tot, a[i]) - s, id[i] = i;
  sort(id + 1, id + 1 + n, mmp);
  int R = 0;
  for (int i = 1; i <= n; i++) {
    int x = id[i];
    while (R < a[x]) R++, rt[R] = rt[R - 1];
    chng(rt[a[x]], rt[a[x]], 1, n, x);
  }
  for (int i = 1; i <= n; i++) {
    int df = 2.1e9, pos = i;
    while (true) {
      if (df < 2) break;
      if (pos <= 1) break;
      int lx = max(0, s[a[i]] - df / 2 + (df % 2 == 0));
      lx = lower_bound(s + 1, s + 1 + tot, lx) - s;
      int ans = -1;
      int trk = getrk(rt[lx - 1], rt[a[i]], 1, n, i);
      trk--;
      if (trk) ans = getkth(rt[lx - 1], rt[a[i]], 1, n, trk);
      if (ans == -1) break;
      v[i].push_back(ans);
      df = s[a[i]] - s[a[ans]];
      pos = ans;
    }
    df = 2.1e9, pos = i;
    while (true) {
      if (df < 2) break;
      if (pos <= 1) break;
      int lx = min(1000000000, s[a[i]] + df / 2 - (df % 2 == 0));
      int rx = lower_bound(s + 1, s + 1 + tot, lx) - s;
      if (s[rx] != lx) rx--;
      int ans = -1;
      int trk = getrk(rt[a[i] - 1], rt[rx], 1, n, i);
      trk--;
      if (trk) ans = getkth(rt[a[i] - 1], rt[rx], 1, n, trk);
      if (ans == -1) break;
      v[i].push_back(ans);
      df = s[a[ans]] - s[a[i]];
      pos = ans;
    }
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].l, &b[i].r), b[i].wh = i;
  sort(b + 1, b + 1 + m, cmp);
  R = 0;
  memset(ls, 0, sizeof(ls));
  memset(rs, 0, sizeof(rs));
  memset(he, 0x3f3f3f3f, sizeof(he));
  js = 0;
  for (int i = 1; i <= m; i++) {
    while (R < b[i].r) {
      R++;
      for (int j = 0; j < v[R].size(); j++) {
        int x = v[R][j];
        ins(rt[0], 1, n, x, abs(s[a[R]] - s[a[x]]));
      }
    }
    ans[b[i].wh] = qry(rt[0], 1, n, b[i].l, b[i].r);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
