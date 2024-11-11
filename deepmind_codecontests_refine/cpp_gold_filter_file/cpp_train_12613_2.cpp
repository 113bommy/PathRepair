#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 6;
int n, m, head[N], cnt, fa[N], dep[N], c[N];
long long ans[N], Num;
bool col[N];
vector<unsigned long long> E[N];
namespace lct {
int ch[N][2], fa[N], sz[N], sm[N], _v[N];
long long szz[N];
bool tag[N];
inline bool ckr(int x, int p = 1) { return ch[fa[x]][p] == x; }
inline bool isroot(int x) { return !(ckr(x) || ckr(x, 0)); }
inline long long calc(int x) { return (long long)sm[x] * sm[x]; }
inline void update(int x) {
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
  sm[x] = sm[ch[x][0]] + sm[ch[x][1]] + _v[x] + 1;
}
inline void flip(int x) { swap(ch[x][0], ch[x][1]), tag[x] ^= 1; }
inline void pushdown(int x) {
  if (tag[x]) {
    if (ch[x][0]) flip(ch[x][0]);
    if (ch[x][1]) flip(ch[x][1]);
    tag[x] = 0;
  }
}
void rotate(int x) {
  int y = fa[x], z = fa[y], k = ckr(x);
  if (!isroot(y)) ch[z][ckr(y)] = x;
  fa[x] = z, fa[y] = x, fa[ch[x][!k]] = y;
  ch[y][k] = ch[x][!k], ch[x][!k] = y;
  update(y);
}
void splay(int x) {
  static int sta[N], top;
  sta[top = 1] = x;
  for (int y = x; !isroot(y); sta[++top] = y = fa[y])
    ;
  while (top) pushdown(sta[top--]);
  for (; !isroot(x); rotate(x))
    if (!isroot(fa[x])) rotate((ckr(x) ^ ckr(fa[x])) ? x : fa[x]);
  update(x);
}
void access(int x) {
  for (int t = 0; x; ch[x][1] = t, t = x, x = fa[x]) {
    splay(x);
    _v[x] -= sm[t], _v[x] += sm[ch[x][1]];
    szz[x] -= calc(t), szz[x] += calc(ch[x][1]);
  }
}
void makeroot(int x) { access(x), splay(x), flip(x); }
int findroot(int x) {
  access(x);
  for (splay(x); ch[x][0]; x = ch[x][0])
    ;
  splay(x);
  return x;
}
void link(int x, int y) {
  splay(x);
  Num -= szz[x] + calc(ch[x][1]);
  access(y), splay(y);
  int z = findroot(y);
  splay(z);
  Num -= calc(ch[z][1]);
  splay(y), fa[x] = y;
  _v[y] += sm[x], szz[y] += calc(x), update(y);
  access(x), splay(z);
  Num += calc(ch[z][1]);
}
void cut(int x, int y) {
  access(x);
  Num += szz[x];
  int z = findroot(x);
  splay(z);
  Num -= calc(ch[z][1]);
  splay(y), ch[y][1] = fa[x] = 0, update(y);
  access(y), splay(z);
  Num += calc(ch[z][1]);
}
}  // namespace lct
struct edge {
  int to, nxt;
} e[N << 1];
void dfs(int now, int pre) {
  for (int i = head[now]; i; i = e[i].nxt)
    if (e[i].to != pre) fa[e[i].to] = now, dfs(e[i].to, now);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> c[i], E[c[i]].push_back(i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[++cnt] = (edge){v, head[u]}, head[u] = cnt;
    e[++cnt] = (edge){u, head[v]}, head[v] = cnt;
  }
  dfs(1, 0);
  for (int i = 1; i <= m; ++i) {
    int u, x;
    cin >> u >> x;
    E[c[u]].push_back((unsigned long long)i << 32 | u);
    c[u] = x;
    E[x].push_back((unsigned long long)i << 32 | u);
  }
  fa[1] = n + 1;
  for (int i = 1; i <= n + 1; ++i) lct::sm[i] = lct::sz[i] = 1;
  for (int i = 1; i <= n; ++i) lct::link(i, fa[i]);
  for (int i = 1; i <= n; ++i) {
    long long dlt = 0;
    for (unsigned long long t : E[i]) {
      int tm = t >> 32, u = (int)t;
      if (col[u])
        lct::link(u, fa[u]);
      else
        lct::cut(u, fa[u]);
      col[u] ^= 1;
      ans[tm] += (long long)n * n - Num - dlt;
      dlt = (long long)n * n - Num;
    }
    for (int u : E[i])
      if (col[u]) col[u] = 0, lct::link(u, fa[u]);
  }
  for (int i = 0; i <= m; ++i) cout << (ans[i] += i ? ans[i - 1] : 0) << '\n';
  return 0;
}
