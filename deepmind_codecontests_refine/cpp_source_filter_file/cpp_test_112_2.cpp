#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 1e5 + 5;
int n, m, q, len[maxn], cur[maxn];
char s[maxn];
struct edge {
  int v, w;
};
vector<edge> g[maxn];
int fa[maxn], dep[maxn], size[maxn], hson[maxn], w[maxn];
void dfs1(int u) {
  dep[u] = dep[fa[u]] + 1;
  size[u] = 1;
  for (edge e : g[u])
    if (e.v != fa[u]) {
      fa[e.v] = u;
      w[e.v] = e.w;
      dfs1(e.v);
      size[u] += size[e.v];
      if (size[e.v] > size[hson[u]]) hson[u] = e.v;
    }
}
vector<int> f;
int pos[maxn], top[maxn];
void dfs2(int u) {
  pos[u] = f.size();
  f.push_back(u);
  if (!hson[u]) return;
  top[hson[u]] = top[u];
  dfs2(hson[u]);
  for (edge e : g[u])
    if (e.v != fa[u] && e.v != hson[u]) {
      top[e.v] = e.v;
      dfs2(e.v);
    }
}
template <int maxn>
struct SAM {
  int sz = 1, last = 0, len[maxn * 2], fa[maxn * 2], nxt[maxn * 2][26];
  SAM() { fa[0] = -1; }
  void extend(int c) {
    if (nxt[last][c]) {
      int p = last, q = nxt[p][c];
      if (len[q] == len[p] + 1)
        last = q;
      else {
        int clone = sz++;
        fa[clone] = fa[q];
        memcpy(nxt[clone], nxt[q], sizeof(nxt[0]));
        len[clone] = len[p] + 1;
        while (p >= 0 && nxt[p][c] == q) {
          nxt[p][c] = clone;
          p = fa[p];
        }
        last = fa[q] = clone;
      }
    } else {
      int cur = sz++;
      len[cur] = len[last] + 1;
      int p = last;
      while (p >= 0 && !nxt[p][c]) {
        nxt[p][c] = cur;
        p = fa[p];
      }
      if (p >= 0) {
        int q = nxt[p][c];
        if (len[q] == len[p] + 1)
          fa[cur] = q;
        else {
          int clone = sz++;
          fa[clone] = fa[q];
          memcpy(nxt[clone], nxt[q], sizeof(nxt[0]));
          len[clone] = len[p] + 1;
          while (p >= 0 && nxt[p][c] == q) {
            nxt[p][c] = clone;
            p = fa[p];
          }
          fa[cur] = fa[q] = clone;
        }
      }
      last = cur;
    }
  }
};
namespace SAM1 {
SAM<maxn> t;
int ord[maxn * 2], p[maxn];
long long g[maxn * 2], h[maxn * 2];
vector<int> f;
int pos[maxn * 2], top[maxn * 2], bot[maxn * 2];
void dfs1(int u) {
  pos[u] = f.size();
  f.push_back(u);
  int hson = -1;
  for (int i = 0; i < 26; i++) {
    int v = t.nxt[u][i];
    if (!v) continue;
    if (g[v] * 2 > g[u] && h[u] * 2 > h[v]) hson = v;
  }
  if (hson < 0)
    bot[u] = u;
  else {
    top[hson] = top[u];
    dfs1(hson);
    bot[u] = bot[hson];
  }
}
vector<int> g2[maxn * 2];
int cnt = 0, pos2[maxn * 2], size[maxn * 2];
void dfs2(int u) {
  pos2[u] = ++cnt;
  size[u] = 1;
  for (int v : g2[u]) {
    dfs2(v);
    size[u] += size[v];
  }
}
}  // namespace SAM1
int cur1[maxn];
namespace SAM2 {
SAM<maxn * 3> t;
vector<int> g[maxn * 6];
int dep[maxn * 6], size[maxn * 6], hson[maxn * 6];
void dfs1(int u) {
  dep[u] = u ? dep[t.fa[u]] + 1 : 1;
  size[u] = 1;
  hson[u] = -1;
  for (int v : g[u]) {
    dfs1(v);
    size[u] += size[v];
    if (hson[u] < 0 || size[v] > size[hson[u]]) hson[u] = v;
  }
}
int top[maxn * 6];
void dfs2(int u) {
  if (hson[u] < 0) return;
  top[hson[u]] = top[u];
  dfs2(hson[u]);
  for (int v : g[u])
    if (v != hson[u]) {
      top[v] = v;
      dfs2(v);
    }
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = t.fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  return y;
}
}  // namespace SAM2
int cur2[maxn], cur3[maxn], cur4[maxn];
vector<pair<int, int> > q1[maxn], q2[maxn];
void trans(int& u, int l, int r) {
  if (u < 0) return;
  int v = SAM1::bot[u], ml = SAM1::pos[v] - SAM1::pos[u], res = 0;
  if (ml)
    res = SAM2::t.len[SAM2::lca(cur4[SAM1::p[v] - ml + 1],
                                l <= r ? cur3[l] : cur2[l])];
  res = min(res, min(ml, abs(r - l) + 1));
  u = SAM1::f[SAM1::pos[u] + res];
  if (l <= r) {
    l += res;
    if (l > r) return;
    u = SAM1::t.nxt[u][w[f[l]]];
    if (!u)
      u = -1;
    else if (l < r)
      trans(u, l + 1, r);
  } else {
    l -= res;
    if (l < r) return;
    u = SAM1::t.nxt[u][w[f[l]]];
    if (!u)
      u = -1;
    else if (l > r)
      trans(u, l - 1, r);
  }
}
int c[maxn * 2];
inline int lowbit(int x) { return x & -x; }
void modify(int x, int k) {
  while (x <= SAM1::t.sz) {
    c[x] += k;
    x += lowbit(x);
  }
}
int query(int x) {
  int s = 0;
  while (x) {
    s += c[x];
    x -= lowbit(x);
  }
  return s;
}
int ans[maxn];
int main() {
  n = readint();
  m = readint();
  q = readint();
  for (int i = 1; i < n; i++) {
    int u, v;
    u = readint();
    v = readint();
    char c[5];
    scanf("%s", c);
    g[u].push_back({v, c[0] - 'a'});
    g[v].push_back({u, c[0] - 'a'});
  }
  dfs1(1);
  top[1] = 1;
  dfs2(1);
  for (int i = 1; i < n; i++) {
    if (fa[f[i]] != f[i - 1]) SAM2::t.last = 0;
    SAM2::t.extend(w[f[i]]);
    cur2[i] = SAM2::t.last;
  }
  SAM2::t.last = 0;
  for (int i = n - 1; i > 0; i--) {
    SAM2::t.extend(w[f[i]]);
    cur3[i] = SAM2::t.last;
    if (fa[f[i]] != f[i - 1]) SAM2::t.last = 0;
  }
  SAM2::t.last = 0;
  cur[0] = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%s", s + 1);
    len[i] = strlen(s + 1);
    cur[i] = cur[i - 1] + len[i - 1];
    for (int j = 1; j <= len[i]; j++) {
      SAM1::t.extend(s[j] - 'a');
      cur1[cur[i] + j - 1] = SAM1::t.last;
      SAM1::p[SAM1::t.last] = cur[i] + j - 1;
    }
    for (int j = len[i]; j > 0; j--) {
      SAM2::t.extend(s[j] - 'a');
      cur4[cur[i] + j - 1] = SAM2::t.last;
    }
    SAM1::t.last = SAM2::t.last = 0;
  }
  for (int i = 0; i < SAM1::t.sz; i++) SAM1::ord[i] = i;
  sort(SAM1::ord, SAM1::ord + SAM1::t.sz,
       [](int a, int b) { return SAM1::t.len[a] < SAM1::t.len[b]; });
  for (int i = SAM1::t.sz - 1; i >= 0; i--) {
    int u = SAM1::ord[i];
    SAM1::g[u] = 1;
    for (int j = 0; j < 26; j++) {
      int v = SAM1::t.nxt[u][j];
      if (!v) continue;
      SAM1::g[u] += SAM1::g[v];
    }
    if (u) SAM1::p[SAM1::t.fa[u]] = SAM1::p[u];
  }
  for (int i = 0; i < SAM1::t.sz; i++) {
    int u = SAM1::ord[i];
    SAM1::h[u]++;
    for (int j = 0; j < 26; j++) {
      int v = SAM1::t.nxt[u][j];
      if (!v) continue;
      SAM1::h[v] += SAM1::h[u];
    }
  }
  for (int i = 0; i < SAM1::t.sz; i++) {
    int u = SAM1::ord[i];
    if (!SAM1::pos[u]) SAM1::dfs1(u);
  }
  for (int i = 1; i < SAM2::t.sz; i++) SAM2::g[SAM2::t.fa[i]].push_back(i);
  SAM2::dfs1(0);
  SAM2::dfs2(0);
  for (int i = 1; i <= q; i++) {
    int u, v, l, r;
    u = readint();
    v = readint();
    l = readint();
    r = readint();
    vector<pair<int, int> > vec1, vec2;
    while (top[u] != top[v])
      if (dep[top[u]] > dep[top[v]]) {
        vec1.push_back({pos[u], pos[top[u]]});
        u = fa[top[u]];
      } else {
        vec2.push_back({pos[top[v]], pos[v]});
        v = fa[top[v]];
      }
    if (dep[u] < dep[v])
      vec1.push_back({pos[u] + 1, pos[v]});
    else if (dep[u] > dep[v])
      vec2.push_back({pos[u], pos[v] + 1});
    u = 0;
    for (pair<int, int> x : vec1) trans(u, x.first, x.second);
    reverse(vec2.begin(), vec2.end());
    for (pair<int, int> x : vec2) trans(u, x.first, x.second);
    if (u >= 0) {
      q1[r].push_back({i, u});
      q2[l - 1].push_back({i, u});
    }
  }
  for (int i = 1; i < SAM1::t.sz; i++) SAM1::g2[SAM1::t.fa[i]].push_back(i);
  SAM1::dfs2(0);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= len[i]; j++)
      modify(SAM1::pos2[cur1[cur[i] + j - 1]], 1);
    for (pair<int, int> x : q1[i]) {
      int u = x.second;
      ans[x.first] +=
          query(SAM1::pos2[u] + SAM1::size[u] - 1) - query(SAM1::pos2[u] - 1);
    }
    for (pair<int, int> x : q2[i]) {
      int u = x.second;
      ans[x.first] -=
          query(SAM1::pos2[u] + SAM1::size[u] - 1) - query(SAM1::pos2[u] - 1);
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
