#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 7;
const long long MOD = 1e9 + 7;
struct Seg {
  int ls[MAXN * 40], rs[MAXN * 40], sum[MAXN * 40], rt[MAXN * 40],
      pos[MAXN * 40], dfn = 0;
  void init() {
    for (int i = 1; i <= dfn; i++)
      rt[i] = ls[i] = rs[i] = sum[i] = 0, pos[i] = 0X3f3f3f3f;
    dfn = 0;
  }
  void update(int &o, int nowl, int nowr, int l, int r, int v) {
    if (!o) o = ++dfn;
    if (nowl >= l && nowr <= r) {
      sum[o] += v;
      return;
    }
    int mid = (nowl + nowr) / 2;
    if (l <= mid) update(ls[o], nowl, mid, l, r, v);
    if (r > mid) update(rs[o], mid + 1, nowr, l, r, v);
    sum[o] = sum[ls[o]] + sum[rs[o]];
  }
  int merge(int p, int q, int l, int r) {
    if (p == 0) return q;
    if (q == 0) return p;
    int id = ++dfn;
    if (l == r) {
      sum[id] = sum[q] + sum[p];
      return id;
    }
    int mid = (l + r) / 2;
    ls[id] = merge(ls[p], ls[q], l, mid);
    rs[id] = merge(rs[p], rs[q], mid + 1, r);
    sum[id] = sum[ls[id]] + sum[rs[id]];
    return id;
  }
  int query(int o, int nowl, int nowr, int l, int r) {
    int res = 0;
    if (nowl >= l && nowr <= r) {
      return sum[o];
    }
    int mid = (nowl + nowr) / 2;
    if (l <= mid && ls[o]) res += query(ls[o], nowl, mid, l, r);
    if (r > mid && rs[o]) res += query(rs[o], mid + 1, nowr, l, r);
    return res;
  }
} seg;
const int CHARSET_SIZE = 26;
char s[MAXN];
int n;
struct Suffix_Automaton {
  int cnt, root, last, prt[MAXN << 1], son[MAXN << 1][CHARSET_SIZE],
      size[MAXN << 1], mx[MAXN << 1], pos[MAXN << 1];
  int topo[MAXN << 1], buc[MAXN << 1];
  inline void init() {
    for (int i = 1; i <= cnt; i++)
      for (int j = 0; j < CHARSET_SIZE; j++) son[i][j] = 0;
    root = last = cnt = 1;
    size[cnt] = mx[cnt] = prt[cnt] = 0;
  }
  inline void extend(int c, int i) {
    int np = ++cnt, p = last;
    mx[np] = mx[p] + 1;
    size[np] = 1;
    pos[np] = i;
    for (; p && !son[p][c]; p = prt[p]) son[p][c] = np;
    if (!p)
      prt[np] = root;
    else {
      int q = son[p][c];
      if (mx[q] == mx[p] + 1)
        prt[np] = q;
      else {
        int nq = ++cnt;
        memcpy(son[nq], son[q], sizeof(son[q]));
        size[nq] = 0;
        mx[nq] = mx[p] + 1;
        pos[nq] = pos[q];
        prt[nq] = prt[q];
        prt[q] = prt[np] = nq;
        for (; p && son[p][c] == q; p = prt[p]) son[p][c] = nq;
      }
    }
    last = np;
  }
  void toposort() {
    int maxv = 0;
    memset(buc, 0, sizeof(buc));
    for (int i = 1; i <= cnt; i++) {
      buc[mx[i]]++;
      maxv = max(maxv, mx[i]);
    }
    for (int i = 1; i <= maxv; i++) buc[i] += buc[i - 1];
    for (int i = cnt; i >= 1; i--) topo[buc[mx[i]]--] = i;
  }
  void cal_right() {
    toposort();
    for (int i = cnt; i >= 1; i--) {
      int v = topo[i];
      seg.rt[prt[v]] = seg.merge(seg.rt[prt[v]], seg.rt[v], 1, n);
    }
  }
  int dp[MAXN << 1], top[MAXN << 1];
  void solve() {
    int ans = 1;
    for (int i = 2; i <= cnt; i++) {
      int u = topo[i];
      if (u == root) {
        dp[u] = 1;
        top[u] = u;
        continue;
      }
      int t = seg.query(seg.rt[top[prt[u]]], 1, n,
                        pos[u] - (mx[u] - mx[top[prt[u]]]), pos[u] - 1);
      if (t) {
        dp[u] = dp[prt[u]] + 1;
        top[u] = u;
      } else {
        dp[u] = dp[prt[u]];
        top[u] = top[prt[u]];
      }
      ans = max(dp[u], ans);
    }
    printf("%d\n", ans);
  }
} sam;
int main() {
  seg.init();
  sam.init();
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    sam.extend(s[i] - 'a', i + 1);
    seg.update(seg.rt[sam.last], 1, n, i + 1, i + 1, 1);
  }
  sam.cal_right();
  sam.solve();
}
