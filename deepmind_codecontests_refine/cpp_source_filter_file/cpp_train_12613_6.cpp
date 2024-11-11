#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 4e5 + 5;
int n, m, col[N], fa[N];
long long ans[N];
vector<int> E[N];
vector<pair<int, int> > vec[N];
namespace lct {
int fa[N], ch[2][N], sz[N], si[N];
long long sz2[N], si2[N];
bool son(int x) { return x == ch[1][fa[x]]; }
bool isrt(int x) { return x != ch[0][fa[x]] && x != ch[1][fa[x]]; }
void up(int x) {
  sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + si[x];
  sz2[x] = 1ll * sz[ch[0][x]] * sz[ch[0][x]] +
           1ll * sz[ch[1][x]] * sz[ch[1][x]] + si2[x];
}
void rotate(int x) {
  int y = fa[x], z = fa[y], c = son(x);
  ch[c][y] = ch[c ^ 1][x];
  if (ch[c][y]) fa[ch[c][y]] = y;
  fa[x] = z;
  if (!isrt(y)) ch[son(y)][z] = x;
  ch[c ^ 1][x] = y;
  fa[y] = x;
  up(y);
}
void splay(int x) {
  for (int y = fa[x]; !isrt(x); rotate(x), y = fa[x])
    if (!isrt(y)) rotate(son(x) ^ son(y) ? x : y);
  up(x);
}
void access(int x) {
  for (int y = 0; x; y = x, x = fa[x]) {
    splay(x);
    si[x] += sz[ch[1][x]];
    si2[x] += 1ll * sz[ch[1][x]] * sz[ch[1][x]];
    ch[1][x] = y;
    si[x] -= sz[y];
    si2[x] -= 1ll * sz[y] * sz[y];
    up(x);
  }
}
void link(int x, int y) {
  access(y);
  splay(x);
  splay(x);
  fa[x] = y;
  si[y] += sz[x];
  si2[y] += 1ll * sz[x] * sz[x];
  up(y);
}
void cut(int x, int y) {
  access(x);
  access(y);
  splay(y);
  splay(x);
  fa[x] = 0;
  si[y] -= sz[x];
  si2[y] -= 1ll * sz[x] * sz[x];
  up(y);
}
int findrt(int x) {
  access(x);
  splay(x);
  while (ch[0][x]) x = ch[0][x];
  splay(x);
  return x;
}
long long query(int x) {
  splay(x);
  return sz2[x];
}
void init() {
  for (int i = 1; i <= n + 1; ++i) sz[i] = si[i] = 1;
  for (int i = 1; i <= n; ++i) link(i, ::fa[i]);
}
}  // namespace lct
void dfs(int u) {
  for (int v : E[u])
    if (v != fa[u]) fa[v] = u, dfs(v);
}
int main() {
  n = gi();
  m = gi();
  for (int i = 1; i <= n; ++i) col[i] = gi();
  for (int i = 1; i < n; ++i) {
    int x = gi(), y = gi();
    E[x].push_back(y);
    E[y].push_back(x);
  }
  fa[1] = n + 1;
  dfs(1);
  for (int i = 1; i <= n; ++i) vec[col[i]].push_back(make_pair(0, i << 1 | 1));
  for (int i = 1; i <= m; ++i) {
    int x = gi(), y = gi();
    vec[col[x]].push_back(make_pair(i, x << 1));
    col[x] = y;
    vec[col[x]].push_back(make_pair(i, x << 1 | 1));
  }
  for (int i = 1; i <= n; ++i) vec[col[i]].push_back(make_pair(m + 1, i << 1));
  lct::init();
  for (int i = 1; i <= n; ++i)
    for (auto x : vec[i]) {
      int u = x.second >> 1, f = lct::findrt(fa[u]);
      if (x.second & 1) {
        ans[x.first] += lct::query(f);
        lct::cut(u, fa[u]);
        ans[x.first] -= lct::query(u) + lct::query(f);
      } else {
        ans[x.first] += lct::query(u) + lct::query(f);
        lct::link(u, fa[u]);
        ans[x.first] -= lct::query(f);
      }
    }
  for (int i = 1; i <= m; ++i) ans[i] += ans[i - 1];
  for (int i = 0; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
