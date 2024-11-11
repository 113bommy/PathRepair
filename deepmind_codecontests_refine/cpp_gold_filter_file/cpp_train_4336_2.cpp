#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0, b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return a;
}
inline int tc() {
  int c = fetch();
  while (c <= 32 && c != EOF) c = fetch();
  return c;
}
inline int ts(char *s) {
  int a = 0, c = fetch();
  while (c <= 32 && c != EOF) c = fetch();
  while (c > 32 && c != EOF) s[a++] = c, c = fetch();
  s[a] = 0;
  return a;
}
inline string ts() {
  string a = "";
  int c = fetch();
  while (c <= 32 && c != EOF) c = fetch();
  while (c > 32 && c != EOF) a.push_back(c), c = fetch();
  return a;
}
}  // namespace ae86
using ae86::tc;
using ae86::ts;
using ae86::ty;
const int _ = 200007, alp = 26;
struct gsam {
  int fa[_], len[_], tran[_][alp], tcnt;
  int push(int p, int c) {
    int np = ++tcnt;
    len[np] = len[p] + 1;
    while (p && !tran[p][c]) tran[p][c] = np, p = fa[p];
    if (!p) {
      fa[np] = 1;
      return np;
    }
    int q = tran[p][c];
    if (len[q] == len[p] + 1) {
      fa[np] = q;
      return np;
    }
    int nq = ++tcnt;
    len[nq] = len[p] + 1, memcpy(tran[nq], tran[q], sizeof(tran[q]));
    fa[nq] = fa[q], fa[q] = fa[np] = nq;
    while (p && tran[p][c] == q) tran[p][c] = nq, p = fa[p];
    return np;
  }
  int rt, ch[_][alp], ccnt;
  int pushstr(string s) {
    int now = rt;
    for (auto c_ : s) {
      int c = c_ - 'a';
      if (!ch[now][c]) ch[now][c] = ++ccnt;
      now = ch[now][c];
    }
    return now;
  }
  int sz[_], id[_], mxch[_], xlen[_][alp];
  vector<int> kid[_];
  void dfs(int x) {
    sz[x] = 1;
    for (int i = 0; i < alp; i++) {
      if (tran[x][i]) continue;
      tran[x][i] = tran[fa[x]][i];
      if (xlen[fa[x]][i] >= 0)
        xlen[x][i] = xlen[fa[x]][i];
      else
        xlen[x][i] = len[fa[x]] + 1;
    }
    mxch[x] = 0;
    for (auto b : kid[x]) {
      dfs(b), sz[x] += sz[b];
      if (sz[mxch[x]] < sz[b]) mxch[x] = b;
    }
  }
  int top[_], dfn[_], dfncnt;
  void dfs2(int x, int tp) {
    dfn[x] = ++dfncnt, top[x] = tp;
    if (mxch[x]) dfs2(mxch[x], tp);
    for (auto b : kid[x])
      if (b != mxch[x]) dfs2(b, b);
  }
  pair<int, int> range(int x) {
    x = id[x];
    return pair<int, int>(dfn[x], dfn[x] + sz[x] - 1);
  }
  pair<int, int> runtime(int x, int c, int temp) {
    return pair<int, int>(tran[x][c], xlen[x][c] >= 0 ? xlen[x][c] : temp + 1);
  }
  void make() {
    memset(xlen, -1, sizeof(xlen));
    queue<int> q;
    q.emplace(1), id[1] = 1;
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int i = 0; i < alp; i++)
        if (ch[a][i]) id[ch[a][i]] = push(id[a], i), q.emplace(ch[a][i]);
    }
    for (int i = 2; i <= tcnt; i++) kid[fa[i]].emplace_back(i);
    len[0] = -1;
    for (int i = 0; i < alp; i++) tran[0][i] = 1;
    dfncnt = 0, dfs(1), dfs2(1, 1);
  }
  vector<int> buc[_];
  void pushbuc(int x, int d) { buc[top[x]].emplace_back(d); }
  void popbuc(int x) { buc[top[x]].pop_back(); }
  int findbuc(int x) {
    x = id[x];
    int temp = x;
    while (1) {
      int b = top[x];
      if (buc[b].empty() || buc[b][0] > len[x] || buc[b][0] == len[temp]) {
        x = fa[b];
        continue;
      }
      auto a = upper_bound(buc[b].begin(), buc[b].end(), len[x]);
      a--;
      if ((*a) == len[temp]) a--;
      return *a;
    }
  }
  gsam() { rt = tcnt = ccnt = 1; }
} gs[2];
struct tla {
  long long t[_];
  void add(int x, long long d) {
    while (x < _) t[x] += d, x += ((x) & (-(x)));
  }
  long long sum(int x) {
    long long d = 0;
    while (x) d += t[x], x -= ((x) & (-(x)));
    return d;
  }
  void cls() { memset(t, 0, sizeof(t)); }
  tla() { cls(); }
};
int n, m, qn, qa[_], qb[_], qc[_];
string sp[_][2];
int at[_][2], qloc[_][2];
long long ans[_] = {0};
namespace geralt {
vector<pair<int, int> > e[_];
inline void adde(int a, int b, int c) { e[a].emplace_back(b, c); }
inline void addde(int a, int b, int c) { adde(a, b, c), adde(b, a, c); }
int allsz = 0, ban[_] = {0}, sz[_] = {0}, mxsz[_] = {0}, yaourt = 0;
void getsz(int x) {
  allsz++, mxsz[x] = 0, ban[x] = 1;
  for (auto [b, $] : e[x])
    if (!ban[b]) getsz(b);
  ban[x] = 0;
}
void geralt(int x) {
  sz[x] = 1, mxsz[x] = 0, ban[x] = 1;
  for (auto [b, $] : e[x])
    if (!ban[b]) geralt(b), sz[x] += sz[b], mxsz[x] = max(mxsz[x], sz[b]);
  mxsz[x] = max(mxsz[x], allsz - sz[x]);
  if (mxsz[x] < mxsz[yaourt]) yaourt = x;
  ban[x] = 0;
}
int col[_];
void dfscol(int x, int d) {
  col[x] = d, ban[x] = 1;
  for (auto [b, $] : e[x])
    if (!ban[b]) dfscol(b, d);
  ban[x] = 0;
}
vector<int> qry[_];
vector<pair<int, int> > tags[_];
tla f[2];
void dfstag(int x, int now0, int now1, int len0, int len1, int got0, int got1) {
  int loc0 = gs[0].dfn[gs[0].len[now0] == len0 ? now0 : gs[0].fa[now0]];
  int loc1 = gs[1].dfn[gs[1].len[now1] == len1 ? now1 : gs[1].fa[now1]];
  ban[x] = 1, f[0].add(loc0, 1), f[1].add(loc1, 1);
  if (got0) gs[0].pushbuc(now0, len0);
  if (got1) gs[1].pushbuc(now1, len1);
  for (auto [a, b] : tags[x]) {
    pair<int, int> loc = gs[b].range(at[qc[a]][b]);
    ans[a] += f[b].sum(loc.second) - f[b].sum(loc.first - 1);
    qloc[a][1 - b] = gs[b].findbuc(at[qc[a]][b]);
  }
  tags[x].clear();
  for (auto [b, c] : e[x]) {
    if (ban[b]) continue;
    pair<int, int> nex0 = gs[0].runtime(now0, c, len0);
    pair<int, int> nex1 = gs[1].runtime(now1, c, len1);
    dfstag(b, nex0.first, nex1.first, nex0.second, nex1.second,
           got0 & (nex0.second == len0 + 1), got1 & (nex1.second == len1 + 1));
  }
  ban[x] = 0, f[0].add(loc0, -1), f[1].add(loc1, -1);
  if (got0) gs[0].popbuc(now0);
  if (got1) gs[1].popbuc(now1);
}
void finder(int x) {
  vector<int> temp(0);
  temp.swap(qry[x]);
  allsz = 0, yaourt = 0, mxsz[yaourt] = 1e9;
  getsz(x), geralt(x), x = yaourt;
  ban[x] = 1, col[x] = 0;
  for (auto [b, $] : e[x])
    if (!ban[b]) dfscol(b, b);
  for (auto i : temp) {
    int a = qa[i], b = qb[i];
    if (col[a] == col[b])
      qry[col[a]].emplace_back(i);
    else
      tags[a].emplace_back(i, 1), tags[b].emplace_back(i, 0);
  }
  dfstag(x, 1, 1, 0, 0, 1, 1), ban[x] = 1;
  for (auto [b, $] : e[x])
    if (!ban[b]) finder(b);
}
}  // namespace geralt
namespace acmata {
void make(string s, int fa[], vector<int> ch[]) {
  s.insert(s.begin(), 0), fa[0] = -1;
  for (int i = 0; i < ((int)((s).size())); i++) ch[i].clear();
  for (int i = 1; i < ((int)((s).size())); i++) {
    int now = fa[i - 1];
    while (now >= 0 && s[now + 1] != s[i]) now = fa[now];
    now++, fa[i] = now, ch[fa[i]].emplace_back(i);
  }
}
int fa0[_], fa1[_];
vector<int> ch0[_], ch1[_], qry[_];
int dfn[_], ndf[_], dfncnt;
void dfs(int x) {
  dfn[x] = ++dfncnt;
  for (auto b : ch1[x]) dfs(b);
  ndf[x] = dfncnt;
}
tla f;
int len;
void dfs2(int x) {
  f.add(dfn[len - x], 1), f.add(ndf[len - x] + 1, -1);
  for (auto i : qry[x]) ans[i] += f.sum(dfn[qloc[i][1]]);
  for (auto b : ch0[x]) dfs2(b);
  qry[x].clear(), f.add(dfn[len - x], -1), f.add(ndf[len - x] + 1, 1);
}
void finder(string s0, string s1, vector<int> to) {
  make(s0, fa0, ch0), make(s1, fa1, ch1);
  for (auto i : to) qry[qloc[i][0]].emplace_back(i);
  dfncnt = 0, len = ((int)((s0).size())), dfs(0), dfs2(0);
}
}  // namespace acmata
vector<int> temp[_];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty(), qn = ty();
  for (int i = 1, a, b, c; i < n; i++)
    a = ty(), b = ty(), c = tc(), geralt::addde(a, b, c - 'a');
  for (int i = 1; i <= m; i++) {
    sp[i][0] = ts(), sp[i][1] = sp[i][0],
    reverse(sp[i][1].begin(), sp[i][1].end());
    at[i][0] = gs[0].pushstr(sp[i][0]), at[i][1] = gs[1].pushstr(sp[i][1]);
  }
  gs[0].make(), gs[1].make();
  for (int i = 1; i <= qn; i++)
    qa[i] = ty(), qb[i] = ty(), qc[i] = ty(), temp[qc[i]].emplace_back(i);
  for (int i = 1; i <= qn; i++) geralt::qry[1].emplace_back(i);
  geralt::finder(1);
  for (int i = 1; i <= m; i++) acmata::finder(sp[i][0], sp[i][1], temp[i]);
  for (int i = 1; i <= qn; i++) cout << ans[i] << lf;
  return 0;
}
