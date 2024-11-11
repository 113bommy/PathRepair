#include <bits/stdc++.h>
using namespace std;
const int N = 250000;
long long tmpans, ans;
struct SAM {
  struct Node {
    int len, fa, ch[26];
  } a[N];
  int node_cnt, cur;
  vector<int> e[N];
  void ade(int u, int v) { e[u].push_back(v); }
  void clear() { node_cnt = cur = 1; }
  void ins(int ch) {
    int u = cur;
    cur = ++node_cnt;
    a[cur].len = a[u].len + 1;
    for (; u && !a[u].ch[ch]; u = a[u].fa) a[u].ch[ch] = cur;
    if (!u) {
      a[cur].fa = 1;
      tmpans += a[cur].len;
      return;
    }
    int v = a[u].ch[ch];
    if (a[v].len == a[u].len + 1) {
      a[cur].fa = v;
      tmpans += a[cur].len - a[v].len;
      return;
    }
    int t = ++node_cnt;
    a[t] = a[v], a[t].len = a[u].len + 1;
    a[v].fa = a[cur].fa = t;
    for (; u && a[u].ch[ch] == v; u = a[u].fa) a[u].ch[ch] = t;
    tmpans += a[cur].len - a[t].len;
  }
  void build() {
    for (int i = 2; i <= node_cnt; i++) ade(a[i].fa, i);
  }
  void print() {
    for (int i = 1; i <= node_cnt; i++) printf("%d %d\n", i, a[i].fa);
  }
} s1, s2;
int root[N], seg_cnt, ch[N * 20][2], dfs_cnt, euler_cnt, euler[20][N << 1],
    edfn[N], dfn[N], nid[N], pos1[N], pos2[N], dep[N], lg[N];
char st[N];
void dfs2(int u) {
  dfn[u] = ++dfs_cnt;
  nid[dfs_cnt] = u;
  dep[u] = dep[s2.a[u].fa] + 1;
  euler[0][++euler_cnt] = u;
  edfn[u] = euler_cnt;
  for (vector<int>::iterator i = s2.e[u].begin(); i != s2.e[u].end(); i++) {
    int v = *i;
    dfs2(v);
    euler[0][++euler_cnt] = u;
  }
}
void make() {
  lg[0] = -1;
  for (int i = 1; i <= euler_cnt; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; (1 << i) <= euler_cnt; i++)
    for (int j = 1; j + (1 << i) - 1 <= euler_cnt; j++) {
      int x = euler[i - 1][j], y = euler[i - 1][j + (1 << (i - 1))];
      euler[i][j] = dep[x] < dep[y] ? x : y;
    }
}
int lca(int u, int v) {
  u = edfn[u], v = edfn[v];
  if (u > v) swap(u, v);
  int len = lg[v - u + 1];
  int x = euler[len][u], y = euler[len][v - (1 << len) + 1];
  return dep[x] < dep[y] ? x : y;
}
struct SegNode {
  int l, r;
  long long ans;
  SegNode operator+(const SegNode &a) const {
    SegNode t;
    t.l = l ? l : a.l, t.r = a.r ? a.r : r;
    t.ans = ans + a.ans;
    if (r && a.l) t.ans -= s2.a[lca(nid[r], nid[a.l])].len;
    return t;
  }
} s[N * 20];
void update(int &rot, int lt, int rt, int q) {
  if (!rot) rot = ++seg_cnt;
  if (lt == rt) {
    s[rot].ans = s2.a[nid[q]].len;
    s[rot].l = s[rot].r = q;
    return;
  }
  int mid = (lt + rt) >> 1;
  if (q <= mid)
    update(ch[rot][0], lt, mid, q);
  else
    update(ch[rot][1], mid + 1, rt, q);
  s[rot] = s[ch[rot][0]] + s[ch[rot][1]];
}
int merge(int u, int v, int lt, int rt) {
  if (!u || !v) return u | v;
  if (lt == rt) return u;
  int mid = (lt + rt) >> 1;
  ch[u][0] = merge(ch[u][0], ch[v][0], lt, mid);
  ch[u][1] = merge(ch[u][1], ch[v][1], mid + 1, rt);
  s[u] = s[ch[u][0]] + s[ch[u][1]];
  return u;
}
void dfs1(int u) {
  for (vector<int>::iterator i = s1.e[u].begin(); i != s1.e[u].end(); i++) {
    int v = *i;
    dfs1(v);
    root[u] = merge(root[u], root[v], 1, s2.node_cnt);
  }
  ans += 1ll * (s1.a[u].len - s1.a[s1.a[u].fa].len) * s[root[u]].ans;
}
int main() {
  scanf("%s", st + 1);
  s1.clear(), s2.clear();
  int n = strlen(st + 1);
  for (int i = 1; i < n; i++) s1.ins(st[i] - 97), pos1[i] = s1.cur;
  ans += tmpans;
  s1.ins(st[n] - 97);
  ans += tmpans;
  tmpans = 0;
  for (int i = n; i > 1; i--) s2.ins(st[i] - 97), pos2[i] = s2.cur;
  ans += tmpans;
  s2.ins(st[1] - 97);
  ans++;
  ans++;
  s1.build(), s2.build();
  dfs2(1);
  make();
  for (int i = 1; i <= n - 2; i++)
    update(root[pos1[i]], 1, s2.node_cnt, dfn[pos2[i + 2]]);
  dfs1(1);
  cout << ans << endl;
}
