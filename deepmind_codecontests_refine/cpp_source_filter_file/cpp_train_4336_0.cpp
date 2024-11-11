#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node {
  int x, v, id;
};
vector<node> vQ[N];
vector<int> S[N];
int n, m, Q, ans[N];
int type[N], L[2][N];
char s[N];
struct Hash {
  int v1, v2, p1, p2;
  Hash() {
    v1 = v2 = 0;
    p1 = p2 = 1;
  }
  Hash(int _c) {
    if (_c == -1) {
      v1 = v2 = 0;
      p1 = p2 = 1;
    } else {
      v1 = v2 = _c + 99;
      p1 = 233;
      p2 = 237;
    }
  }
  Hash operator+(const Hash &a) const {
    Hash ans;
    ans.p1 = 1ll * p1 * a.p1 % 1000000007;
    ans.p2 = 1ll * p2 * a.p2 % 1000000009;
    ans.v1 = (v1 + 1ll * p1 * a.v1) % 1000000007;
    ans.v2 = (v2 + 1ll * p2 * a.v2) % 1000000009;
    return ans;
  }
  bool operator<(const Hash &a) const {
    return v1 == a.v1 ? v2 < a.v2 : v1 < a.v1;
  }
  bool operator==(const Hash &a) const { return v1 == a.v1 && v2 == a.v2; }
};
namespace SEG {
const int M = 10000005;
int ls[M], rs[M], t[M], nd;
void init() {
  for (; nd; --nd)
    ;
  ls[nd] = rs[nd] = t[nd] = 0;
}
void change(int &nk, int k, int l, int r, int x, int y, int val) {
  nk = ++nd;
  t[nk] = t[k];
  ls[nk] = ls[k];
  rs[nk] = rs[k];
  if (x <= l && r <= y) {
    t[nk] = max(t[nk], val);
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) change(ls[nk], ls[k], l, mid, x, y, val);
  if (y > mid) change(rs[nk], rs[k], mid + 1, r, x, y, val);
}
int ask(int k, int l, int r, int p) {
  if (!k) return 0;
  if (l == r) return t[k];
  int mid = (l + r) / 2;
  if (p <= mid)
    return max(t[k], ask(ls[k], l, mid, p));
  else
    return max(t[k], ask(rs[k], mid + 1, r, p));
}
}  // namespace SEG
struct AC_automaton {
  int l[N], pos[N], at[N], nd;
  int ch[N][26], fa[N];
  int dfn1[N], ed1[N];
  int dfn2[N], ed2[N];
  map<Hash, int> mp;
  vector<int> ed[N];
  vector<int> e[N];
  void ACM() {
    static int q[N];
    int h = 0, t = 0;
    for (int i = (int)(0); i <= (int)(25); i++)
      if (!ch[1][i])
        ch[1][i] = 1;
      else {
        fa[ch[1][i]] = 1;
        q[++t] = ch[1][i];
      }
    while (h != t) {
      int x = q[++h];
      for (int i = (int)(0); i <= (int)(25); i++)
        if (!ch[x][i])
          ch[x][i] = ch[fa[x]][i];
        else {
          fa[ch[x][i]] = ch[fa[x]][i];
          q[++t] = ch[x][i];
        }
    }
    for (int i = (int)(2); i <= (int)(nd); i++) e[fa[i]].push_back(i);
  }
  void dfsTR(int x) {
    dfn2[x] = (*dfn2) + 1;
    for (auto i : ed[x]) at[i] = ++*dfn2;
    for (int i = (int)(0); i <= (int)(25); i++)
      if (ch[x][i]) dfsTR(ch[x][i]);
    ed2[x] = *dfn2;
  }
  void dfsFA(int x) {
    dfn1[x] = ++*dfn1;
    for (auto i : e[x]) dfsFA(i);
    ed1[x] = *dfn1;
  }
  void build() {
    nd = 1;
    for (int i = (int)(1); i <= (int)(m); i++) {
      l[i] = S[i].size();
      Hash tmp(-1);
      int x = 1;
      for (int j = (int)(0); j <= (int)(l[i] - 1); j++) {
        int c = S[i][j];
        tmp = tmp + Hash(c);
        if (!ch[x][c]) {
          ch[x][c] = ++nd;
          mp[tmp] = nd;
        }
        x = ch[x][c];
      }
      ed[x].push_back(i);
      pos[i] = x;
    }
    dfsTR(1);
    ACM();
    dfsFA(1);
  }
  int t[N], q[N], rt[N];
  void TR_change(int x, int v) {
    for (; x <= n; x += x & (-x)) t[x] += v;
  }
  int TR_ask(int x) {
    int ans = 0;
    for (; x; x -= x & (-x)) ans += t[x];
    return ans;
  }
  void push(int x, Hash tmp) {
    q[++*q] = x;
    rt[*q] = rt[(*q) - 1];
    if (mp.find(tmp) != mp.end()) {
      int id = mp[tmp];
      SEG::change(rt[*q], rt[*q], 1, m, dfn2[id], ed2[id], (*q) - 1);
    }
    TR_change(dfn1[x], 1);
  }
  void pop() {
    assert(*q);
    TR_change(dfn1[q[*q]], -1);
    --*q;
  }
  int ask(int x) { return TR_ask(ed1[pos[x]]) - TR_ask(dfn1[pos[x]] - 1); }
  int askL(int x) { return SEG::ask(rt[*q], 1, m, at[x]); }
  void init() {
    *q = 0;
    rt[0] = 0;
  }
} AC[2];
namespace TR {
struct edge {
  int to, next, c;
} e[N * 2];
int head[N], tot;
int sz[N], vis[N], rt;
int co[N], q[N];
vector<node> op[N];
void add(int x, int y, int c) {
  e[++tot] = (edge){y, head[x], c};
  head[x] = tot;
}
void dfs(int x, int fa, int n) {
  sz[x] = 1;
  int mx = 0;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to]) {
      dfs(e[i].to, x, n);
      sz[x] += sz[e[i].to];
      mx = max(mx, sz[e[i].to]);
    }
  if (sz[x] * 2 > n && mx * 2 <= n) rt = x;
}
void dfs1(int x, int fa) {
  q[++*q] = x;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to]) {
      co[e[i].to] = co[x];
      dfs1(e[i].to, x);
    }
}
void dfs2(int x, int fa, int p0, int p1, Hash hsh) {
  AC[0].push(p0, hsh);
  AC[1].push(p1, hsh);
  for (auto i : op[x]) {
    ans[i.id] += AC[i.x ^ 1].ask(i.v);
    L[i.x][i.id] = AC[i.x].askL(i.v);
  }
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to]) {
      int np0 = AC[0].ch[p0][e[i].c];
      int np1 = AC[1].ch[p1][e[i].c];
      Hash nhsh = Hash(e[i].c) + hsh;
      dfs2(e[i].to, x, np0, np1, nhsh);
    }
  AC[0].pop();
  AC[1].pop();
}
void solve_prb(int x) {
  int low = (*co)++;
  co[x] = *co;
  q[0] = 1;
  q[1] = x;
  for (int i = head[x]; i; i = e[i].next)
    if (!vis[e[i].to]) {
      co[e[i].to] = ++*co;
      dfs1(e[i].to, x);
    }
  for (int i = (int)(1); i <= (int)(*q); i++)
    for (auto j : vQ[q[i]])
      if (co[j.x] > low && co[j.x] != co[q[i]]) {
        op[q[i]].push_back((node){0, j.v, j.id});
        op[j.x].push_back((node){1, j.v, j.id});
      }
  SEG::init();
  AC[0].init();
  AC[1].init();
  dfs2(x, 0, 1, 1, Hash(-1));
  for (int i = (int)(1); i <= (int)(*q); i++) op[q[i]].resize(0);
}
void solve(int x, int n) {
  dfs(x, 0, n);
  vis[x = rt] = 1;
  solve_prb(x);
  for (int i = head[x]; i; i = e[i].next)
    if (!vis[e[i].to])
      solve(e[i].to, sz[x] < sz[e[i].to] ? n - sz[x] : sz[e[i].to]);
}
}  // namespace TR
struct KanMaoPian {
  int dfn[N], ed[N];
  int nx[N], t[N], T;
  vector<int> e[N];
  void dfs(int x) {
    dfn[x] = ++T;
    for (auto i : e[x]) dfs(i);
    ed[x] = T;
  }
  void TR_change(int x, int v) {
    for (; x <= T; x += x & (-x)) t[x] += v;
  }
  int TR_ask(int x) {
    int s = 0;
    for (; x; x -= x & (-x)) s += t[x];
    return s;
  }
  void change(int x, int v) {
    TR_change(dfn[x], v);
    TR_change(ed[x] + 1, -v);
  }
  int ask(int x) { return TR_ask(dfn[x]); }
  void build(int *a, int n) {
    T = 0;
    nx[1] = 0;
    for (int i = (int)(0); i <= (int)(n + 1); i++) e[i].resize(0);
    for (int i = (int)(2); i <= (int)(n); i++) {
      int j = nx[i - 1];
      for (; j && a[j + 1] != a[i]; j = nx[j])
        ;
      nx[i] = j + (a[j + 1] == a[i]);
    }
    for (int i = (int)(1); i <= (int)(n); i++) {
      e[nx[i]].push_back(i);
    }
    dfs(0);
  }
} KMP0, KMP1;
vector<pair<int, int> > vQQ[N];
vector<int> vec[N];
void dfs(int x, int l) {
  if (x && l - x) KMP1.change(l - x, 1);
  for (auto i : vQQ[x]) ans[i.second] += KMP1.ask(i.first);
  for (auto i : KMP0.e[x]) dfs(i, l);
  if (x && l - x) KMP1.change(l - x, -1);
}
void solve(int id) {
  static int a[N];
  int l = S[id].size();
  for (int i = (int)(0); i <= (int)(l + 1); i++) vQQ[i].resize(0);
  for (int i = (int)(0); i <= (int)(l - 1); i++) a[i + 1] = S[id][i];
  KMP0.build(a, l);
  reverse(a + 1, a + l + 1);
  KMP1.build(a, l);
  for (auto i : vec[id]) {
    if (L[0][i] == l) L[0][i] = KMP0.nx[l];
    if (L[1][i] == l) L[1][i] = KMP1.nx[l];
    vQQ[L[0][i]].push_back(pair<int, int>(L[1][i], i));
  }
  dfs(0, l);
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d%s", &x, &y, s + 1);
    TR::add(x, y, s[1] - 'a');
    TR::add(y, x, s[1] - 'a');
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int j = (int)(1); j <= (int)(l); j++) S[i].push_back(s[j] - 'a');
  }
  for (int T = (int)(0); T <= (int)(1); T++) {
    AC[T].build();
    for (int i = (int)(1); i <= (int)(m); i++)
      reverse(S[i].begin(), S[i].end());
  }
  for (int i = (int)(1); i <= (int)(Q); i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    vQ[x].push_back((node){y, z, i});
    type[i] = z;
  }
  TR::solve(1, n);
  for (int i = (int)(1); i <= (int)(Q); i++) vec[type[i]].push_back(i);
  for (int i = (int)(1); i <= (int)(m); i++) solve(i);
  for (int i = (int)(1); i <= (int)(Q); i++) printf("%d\n", ans[i]);
}
