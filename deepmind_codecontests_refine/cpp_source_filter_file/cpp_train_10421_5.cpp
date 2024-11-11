#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int SN = 2e5 + 100;
struct seg {
  int l, r, sum;
} tree[SN * 20];
int scnt;
void pushup(int pos) {
  tree[pos].sum = tree[tree[pos].l].sum + tree[tree[pos].r].sum;
}
void modify(int &pos, int l, int r, int w) {
  if (!pos) pos = ++scnt;
  if (l == r) {
    tree[pos].sum++;
    return;
  }
  int mid = (l + r) >> 1;
  if (w <= mid)
    modify(tree[pos].l, l, mid, w);
  else
    modify(tree[pos].r, mid + 1, r, w);
  pushup(pos);
}
int query(int pos, int ql, int qr, int l, int r) {
  if (ql <= l && r <= qr) return tree[pos].sum;
  int mid = (l + r) >> 1;
  int res = 0;
  if (ql <= mid) res += query(tree[pos].l, ql, qr, l, mid);
  if (qr > mid) res += query(tree[pos].r, ql, qr, mid + 1, r);
  return res;
}
int merge(int u, int v, int l, int r) {
  if (!u || !v) return u + v;
  int pos = ++scnt;
  if (l == r) {
    tree[pos].sum = tree[u].sum + tree[v].sum;
    return pos;
  }
  int mid = (l + r) >> 1;
  tree[pos].l = merge(tree[u].l, tree[v].r, l, mid);
  tree[pos].r = merge(tree[u].r, tree[v].r, mid + 1, r);
  pushup(pos);
  return pos;
}
int rt[SN], n;
struct SAM {
  int trans[SN][26];
  int mxl[SN], link[SN], pre, scnt;
  SAM() { pre = scnt = 1; };
  void init() {
    for (int j = 1; j <= scnt; j++) {
      link[j] = 0;
      mxl[j] = 0;
      memset(trans[j], 0, sizeof(trans[j]));
    }
    scnt = pre = 1;
  };
  void insert(int id) {
    int cur = ++scnt;
    mxl[cur] = mxl[pre] + 1;
    int u;
    modify(rt[cur], 1, n, mxl[cur]);
    for (u = pre; u && !trans[u][id]; u = link[u]) trans[u][id] = cur;
    pre = cur;
    if (!u)
      link[cur] = 1;
    else {
      int x = trans[u][id];
      if (mxl[x] == mxl[u] + 1)
        link[cur] = x;
      else {
        int nc = ++scnt;
        link[nc] = link[x];
        mxl[nc] = mxl[u] + 1;
        memcpy(trans[nc], trans[x], sizeof(trans[x]));
        link[cur] = link[x] = nc;
        for (; u && trans[u][id] == x; u = link[u]) trans[u][id] = nc;
      }
    }
  }
} sam;
struct edge {
  int to, nxt;
} e[SN];
int ecnt, head[SN];
void addadge(int u, int v) {
  e[++ecnt].to = v;
  e[ecnt].nxt = head[u];
  head[u] = ecnt;
}
void dfs(int x) {
  for (int i = head[x]; i; i = e[i].nxt) {
    int to = e[i].to;
    dfs(to);
    rt[x] = merge(rt[x], rt[to], 1, n);
  }
}
void solve(int l, int r, char *t) {
  int u = 1;
  int len = strlen(t + 1);
  t[len + 1] = 'a' - 1;
  int ansi = -1, ansj = -1;
  for (int i = 1; i <= len + 1; i++) {
    for (int j = t[i] - 'a' + 1; j < 26; j++) {
      int v = sam.trans[u][j];
      if (v && query(rt[v], l + i - 1, r, 1, n)) {
        ansi = i;
        ansj = j;
        break;
      }
    }
    if (i == len + 1) break;
    u = sam.trans[u][t[i] - 'a'];
    if (!u || !query(rt[u], l + i - 1, r, 1, n)) break;
  }
  if (ansi == -1)
    printf("-1\n");
  else {
    for (int i = 1; i <= ansi - 1; i++) printf("%c", t[i]);
    printf("%c", ansj + 'a');
    printf("\n");
  }
}
char s[N], t[N];
int q;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) sam.insert(s[i] - 'a');
  for (int i = 2; i <= sam.scnt; i++) addadge(sam.link[i], i);
  dfs(1);
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d%s", &l, &r, t + 1);
    solve(l, r, t);
  }
}
