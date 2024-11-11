#include <bits/stdc++.h>
using namespace std;
int gi() {
  char ch = '!';
  int res = 0, f = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
    if (ch == '-') f = 1;
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return f ? -res : res;
}
const int N = 5e5 + 100;
int n, m, c[N], tfa[N], fa[N], ch[N][2], sz[N], vsz[N];
long long vsz2[N], ans[N], val;
vector<pair<int, int> > mdf[N];
vector<int> nxt[N];
long long sqr(int x) { return 1ll * x * x; }
void dfs(int u, int lst) {
  tfa[u] = lst, sz[u] = 1;
  for (auto v : nxt[u])
    if (v != lst) dfs(v, u), sz[u] += sz[v], vsz2[u] += sqr(sz[v]);
}
bool nrt(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
bool get(int x) { return ch[fa[x]][1] == x; }
void pushup(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + vsz[x] + 1; }
void rot(int x) {
  int y = fa[x], z = fa[y], k = get(x);
  if (nrt(y)) ch[z][get(y)] = x;
  fa[x] = z;
  if (ch[x][k ^ 1]) fa[ch[x][k ^ 1]] = y;
  ch[y][k] = ch[x][k ^ 1];
  ch[x][k ^ 1] = y, fa[y] = x;
  pushup(y);
}
void splay(int x) {
  while (nrt(x)) {
    int y = fa[x];
    if (nrt(y)) get(x) ^ get(y) ? rot(x) : rot(y);
    rot(x);
  }
  pushup(x);
}
void access(int x) {
  for (int y = 0; x; y = x, x = fa[x])
    splay(x), vsz[x] += sz[ch[x][1]] - sz[y],
        vsz2[x] += sqr(sz[ch[x][1]]) - sqr(sz[y]), ch[x][1] = y;
}
int findrt(int x) {
  access(x), splay(x);
  while (ch[x][0]) x = ch[x][0];
  splay(x);
  return x;
}
void cut(int x) {
  int temp = sz[ch[findrt(x)][1]];
  splay(x);
  val += -sqr(temp) + sqr(temp - sz[ch[x][1]] - vsz[x] - 1) + vsz2[x] +
         sqr(sz[ch[x][1]]);
  fa[ch[x][0]] = ch[x][0] = 0;
  pushup(x);
}
void link(int x) {
  int f = tfa[x], siz = sz[ch[findrt(f)][1]];
  splay(x), splay(f);
  val += -vsz2[x] - sqr(siz) - sqr(sz[ch[x][1]]) + sqr(sz[x] + siz);
  fa[x] = f, sz[f] += sz[x], vsz[f] += sz[x], vsz2[f] += sqr(sz[x]);
}
int main() {
  n = gi(), m = gi();
  for (int i = 1; i <= n; ++i)
    c[i] = gi(), mdf[c[i]].push_back(make_pair(i, 0));
  for (int i = 1; i < n; ++i) {
    int p = gi(), q = gi();
    nxt[p].push_back(q), nxt[q].push_back(p);
  }
  nxt[n + 1].push_back(1);
  dfs(n + 1, 0);
  for (int i = 1; i <= n + 1; ++i) fa[i] = tfa[i], vsz[i] = sz[i] - 1;
  for (int i = 1; i <= m; ++i) {
    int p = gi(), q = gi();
    mdf[c[p]].push_back(make_pair(-p, i)),
        mdf[c[p] = q].push_back(make_pair(p, i));
  }
  val = sqr(n);
  for (int i = 1; i <= n; ++i) {
    int las = 0;
    for (auto p : mdf[i]) {
      ans[las] += sqr(n) - val, ans[las = p.second] -= sqr(n) - val;
      p.first > 0 ? cut(p.first) : link(-p.first);
    }
    ans[las] += sqr(n) - val, reverse(mdf[i].begin(), mdf[i].end());
    for (auto p : mdf[i]) p.first > 0 ? link(p.first) : cut(-p.first);
  }
  for (int i = 1; i <= m; ++i) ans[i] += ans[i - 1];
  for (int i = 0; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
