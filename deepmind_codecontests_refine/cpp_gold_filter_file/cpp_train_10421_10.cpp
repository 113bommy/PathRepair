#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const int inf = 1e9;
int n, m;
char s[N], t[N];
vector<int> g[N];
struct SegmentTree {
  int tr[N * 40], ls[N * 40], rs[N * 40], tot;
  void up(int x, int l, int r, int &p) {
    if (!p) p = ++tot;
    tr[p]++;
    if (l == r) return;
    int mid = l + r >> 1;
    if (x <= mid)
      up(x, l, mid, ls[p]);
    else
      up(x, mid + 1, r, rs[p]);
  }
  int merge(int x, int y, int l, int r) {
    if (!x || !y) return x + y;
    int o = ++tot, mid = l + r >> 1;
    if (l == r)
      tr[o] = tr[x] + tr[y];
    else {
      ls[o] = merge(ls[x], ls[y], l, mid);
      rs[o] = merge(rs[x], rs[y], mid + 1, r);
      tr[o] = tr[ls[o]] + tr[rs[o]];
    }
    return o;
  }
  int qy(int dl, int dr, int l, int r, int p) {
    if (!p || l > r) return 0;
    if (l == dl && r == dr) return tr[p];
    int mid = l + r >> 1;
    if (dr <= mid)
      return qy(dl, dr, l, mid, ls[p]);
    else if (dl > mid)
      return qy(dl, dr, mid + 1, r, rs[p]);
    else
      return qy(dl, mid, l, mid, ls[p]) + qy(mid + 1, dr, mid + 1, r, rs[p]);
  }
} seg;
struct SAM {
  int last, cnt;
  int ch[N][26], fa[N], len[N], rt[N];
  void insert(int c, int pos) {
    int p = last, np = ++cnt;
    last = np;
    len[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p)
      fa[np] = 1;
    else {
      int q = ch[p][c];
      if (len[q] == len[p] + 1)
        fa[np] = q;
      else {
        int nq = ++cnt;
        len[nq] = len[p] + 1;
        memcpy(ch[nq], ch[q], sizeof ch[q]);
        fa[nq] = fa[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
      }
    }
    seg.up(pos, 1, n, rt[np]);
  }
  void init() { last = cnt = 1; }
  void dfs(int u) {
    for (int x : g[u]) {
      dfs(x);
      rt[u] = seg.merge(rt[u], rt[x], 1, n);
    }
  }
  void gao() {
    for (int i = 2; i <= cnt; i++) g[fa[i]].push_back(i);
    dfs(1);
  }
  void solve(int l, int r) {
    int u = 1;
    t[m + 1] = 'a' - 1;
    pair<int, int> ans = make_pair(-1, -1);
    for (int i = 1; i <= m + 1; i++) {
      for (int j = t[i] - 'a' + 1; j < 26; j++) {
        int x = ch[u][j];
        if (!x) continue;
        int pos = seg.qy(l + i - 1, r, 1, n, rt[x]);
        if (pos) {
          ans = make_pair(i, j);
          break;
        }
      }
      if (i == m + 1 || !ch[u][t[i] - 'a']) break;
      u = ch[u][t[i] - 'a'];
    }
    if (ans == make_pair(-1, -1))
      puts("-1");
    else {
      t[ans.first] = 0;
      printf("%s%c\n", t + 1, ans.second + 'a');
    }
  }
} sam;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  sam.init();
  for (int i = 1; i <= n; i++) sam.insert(s[i] - 'a', i);
  sam.gao();
  int q, l, r;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    scanf("%s", t + 1);
    m = strlen(t + 1);
    sam.solve(l, r);
  }
  return 0;
}
