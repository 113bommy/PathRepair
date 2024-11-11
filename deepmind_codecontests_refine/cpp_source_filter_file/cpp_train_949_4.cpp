#include <bits/stdc++.h>
const int N = 4e5 + 10, M = 2e3 + 10;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
namespace LCT {
int par[N], ch[N][2], rev[N];
inline int get(int u) { return ch[par[u]][1] == u; }
inline int rot(int u) { return ch[par[u]][0] != u && ch[par[u]][1] != u; }
inline void Rev(int u) { rev[u] ^= 1, std::swap(ch[u][0], ch[u][1]); }
inline void down(int u) {
  if (rev[u]) {
    if (ch[u][0]) Rev(ch[u][0]);
    if (ch[u][1]) Rev(ch[u][1]);
    rev[u] ^= 1;
  }
}
inline void Down(int u) {
  if (!rot(u)) Down(par[u]);
  down(u);
}
inline void rotate(int u) {
  int v = par[u], w = par[v], k = get(u);
  if (!rot(v)) ch[w][ch[w][1] == v] = u;
  par[ch[v][k] = ch[u][k ^ 1]] = v;
  par[ch[u][k ^ 1] = v] = u, par[u] = w;
}
inline void splay(int u) {
  Down(u);
  for (int f; f = par[u], !rot(u); rotate(u))
    if (!rot(f)) rotate(get(u) == get(f) ? f : u);
}
inline void access(int u) {
  for (int v = 0; u; u = par[v = u]) splay(u), ch[u][1] = v;
}
inline void mkt(int u) { access(u), splay(u), Rev(u); }
inline int find(int u) {
  access(u), splay(u);
  while (ch[u][0]) down(u), u = ch[u][0];
  return splay(u), u;
}
inline int link(int u, int v) {
  mkt(u);
  if (find(u) == find(v)) return 0;
  return par[u] = v, 1;
}
inline void cut(int u, int v) {
  mkt(u);
  if (find(v) == u && par[v] == u && !ch[v][0]) par[v] = ch[u][1] = 0;
}
}  // namespace LCT
using LCT::cut;
using LCT::link;
int Min[N << 2], num[N << 2], tag[N];
inline void upd(int k) {
  int lc = k << 1, rc = k << 1 | 1;
  if (Min[lc] < Min[rc]) Min[k] = Min[lc], num[k] = num[lc];
  if (Min[lc] > Min[rc]) Min[k] = Min[rc], num[k] = num[rc];
  if (Min[lc] == Min[rc]) Min[k] = Min[lc], num[k] = num[lc] + num[rc];
}
inline void build(int k, int l, int r) {
  if (l == r) return num[k] = 1, void();
  build(k << 1, l, ((l + r) >> 1)), build(k << 1 | 1, ((l + r) >> 1) + 1, r),
      upd(k);
}
inline void down(int u, int dat) { Min[u] += dat, tag[u] += dat; }
inline void down(int k) {
  if (tag[k]) {
    down(k << 1, tag[k]);
    down(k << 1 | 1, tag[k]);
    tag[k] = 0;
  }
}
inline void mod(int k, int l, int r, int ql, int qr, int dat) {
  if (l > r || l > qr || ql > r) return;
  if (ql <= l && r <= qr) return down(k, dat);
  down(k);
  mod(k << 1, l, ((l + r) >> 1), ql, qr, dat);
  mod(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, dat);
  upd(k);
}
inline int ask(int k, int l, int r, int ql, int qr) {
  if (l > r || l > qr || ql > r) return 0;
  if (ql <= l && r <= qr) return Min[k] ? 0 : num[k];
  return down(k), ask(k << 1, l, ((l + r) >> 1), ql, qr) +
                      ask(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
}
int a[M][M], l[N], x[N], y[N];
int main() {
  int n = read(), m = read(), N = n * m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) x[a[i][j]] = i, y[a[i][j]] = j;
  const int way[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int64_t ans = 0;
  build(1, 1, N);
  for (int i = 1, j = 1; i <= N; ++i) {
    if (i != 1) mod(1, 1, N, 1, i - 1, 1);
    std::vector<int> vec;
    for (int k = 0; k < 4; ++k) {
      int x = ::x[i] + way[k][0], y = ::y[i] + way[k][1];
      if (j <= a[x][y] && a[x][y] <= i) {
        mod(1, 1, N, 1, a[x][y], -1);
        vec.push_back(a[x][y]);
      }
    }
    for (;;) {
      std::vector<int> tmp;
      for (auto u : vec)
        if (j <= u && !link(i, u)) tmp.push_back(u);
      vec = tmp;
      if (vec.empty()) break;
      for (int k = 0; k < 4; ++k) {
        int x = ::x[j] + way[k][0], y = ::y[j] + way[k][1];
        if (j <= a[x][y] && a[x][y] <= i) cut(j, a[x][y]);
      }
      j = j + 1;
    }
    ans += ask(1, 1, N, j, i);
  }
  std::cout << ans << std::endl;
  return 0;
}
