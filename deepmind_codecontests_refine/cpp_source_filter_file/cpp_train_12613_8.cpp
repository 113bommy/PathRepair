#include <bits/stdc++.h>
const int N = 4e5 + 10;
int ri() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
long long ans[N];
int c[N], pr[N], nx[N << 1], to[N << 1], tp, n, m;
void add(int u, int v) {
  to[++tp] = v;
  nx[tp] = pr[u];
  pr[u] = tp;
}
void adds(int u, int v) {
  add(u, v);
  add(v, u);
}
std::vector<int> ini[N];
std::vector<std::pair<int, int> > mod[N];
namespace LCT {
long long ans = 0, isz2[N];
int isz[N], sz[N], rfa[N], fa[N], ch[N][2];
int tp, st[N << 1];
bool wt[N];
bool wh(int p) { return ch[fa[p]][1] == p; }
bool Ir(int p) { return ch[fa[p]][0] != p && ch[fa[p]][1] != p; }
long long sqr(long long n) { return n * n; }
void Build(int u, int f) {
  fa[u] = f;
  rfa[u] = f;
  sz[u] = 1;
  isz2[u] = 0;
  for (int i = pr[u]; i; i = nx[i])
    if (to[i] != f)
      Build(to[i], u), sz[u] += sz[to[i]], isz2[u] += sqr(sz[to[i]]);
  isz[u] = sz[u] - 1;
}
void Up(int p) { sz[p] = isz[p] + sz[ch[p][0]] + sz[ch[p][1]] + 1; }
void Rotate(int p) {
  int f = fa[p], g = fa[f], c = wh(p);
  if (!Ir(f)) ch[g][wh(f)] = p;
  fa[p] = g;
  ch[f][c] = ch[p][c ^ 1];
  if (ch[f][c]) fa[ch[f][c]] = f;
  ch[p][c ^ 1] = f;
  fa[f] = p;
  Up(f);
}
void Splay(int p) {
  for (; !Ir(p); Rotate(p))
    if (!Ir(fa[p])) Rotate(wh(fa[p]) == wh(p) ? fa[p] : p);
  Up(p);
}
void Access(int u) {
  for (int pr = 0, p = u; p; pr = p, p = fa[p]) {
    Splay(p);
    if (ch[p][1]) {
      isz[p] += sz[ch[p][1]];
      isz2[p] += sqr(sz[ch[p][1]]);
    }
    if (pr) {
      isz[p] -= sz[pr];
      isz2[p] -= sqr(sz[pr]);
    }
    ch[p][1] = pr;
    Up(p);
  }
  Splay(u);
}
int Find(int p) {
  Access(p);
  for (; ch[p][0]; p = ch[p][0])
    ;
  return p;
}
long long Qry(int u) {
  int p = Find(u);
  return Access(p), isz2[p];
}
void Cut(int u) {
  ans -= Qry(u);
  Access(u);
  int v = ch[u][0];
  ch[u][0] = fa[v] = 0;
  Up(u);
  ans += Qry(u) + Qry(v);
}
void Link(int u, int v) {
  ans -= Qry(u) + Qry(v);
  Access(u);
  Access(v);
  fa[u] = v;
  isz[v] += sz[u];
  isz2[v] += sqr(sz[u]);
  Up(v);
  ans += Qry(u);
}
void Rev(int u, bool p) {
  if (p) st[++tp] = u;
  if (!wt[u]) {
    wt[u] = true;
    Cut(u);
  } else {
    wt[u] = false;
    Link(u, rfa[u]);
  }
}
void Restore() {
  for (int i = 1; i <= tp; ++i)
    if (wt[st[i]]) Rev(st[i], 0);
  tp = 0;
}
}  // namespace LCT
int main() {
  n = ri();
  m = ri();
  for (int i = 1; i <= n; ++i) c[i] = ri(), ini[c[i]].push_back(i);
  for (int i = 1; i < n; ++i) adds(ri(), ri());
  adds(1, n + 1);
  LCT::Build(n + 1, 0);
  LCT::ans = 1LL * n * n;
  long long all = LCT::ans;
  for (int i = 1; i <= m; ++i) {
    int u = ri(), x = ri();
    mod[c[u]].push_back(std::make_pair(u, i));
    c[u] = x;
    mod[c[u]].push_back(std::make_pair(u, i));
  }
  for (int x = 1; x <= n; ++x) {
    for (auto i : ini[x]) LCT::Rev(i, 1);
    ans[0] += all - LCT::ans;
    for (auto i : mod[x]) {
      ans[i.second] -= all - LCT::ans;
      LCT::Rev(i.first, 1);
      ans[i.second] += all - LCT::ans;
    }
    LCT::Restore();
  }
  for (int i = 1; i <= m; ++i) ans[i] += ans[i - 1];
  for (int i = 0; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
