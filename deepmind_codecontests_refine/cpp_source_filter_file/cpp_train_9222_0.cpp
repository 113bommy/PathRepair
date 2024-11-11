#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 2e5 + 5, P = 1e9 + 7;
int n, a[N], p[N], ecnt, head[N], cnt, pri[N], phi[N], mu[N], f[N], dfn[N],
    dep[N], lg[N << 1], stk[N], top, fa[N], in[N], q[N], siz[N];
struct ST {
  int p, d;
  inline bool friend operator<(ST a, ST b) { return a.d < b.d; }
} st[N << 1][19];
inline bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
struct Edge {
  int v, nxt;
} e[N << 1];
inline void add(int u, int v) {
  e[++ecnt] = (Edge){v, head[u]};
  head[u] = ecnt;
}
inline int pow(int b, int k) {
  int a = 1;
  while (k) {
    if (k & 1) a = 1LL * a * b % P;
    b = 1LL * b * b % P;
    k >>= 1;
  }
  return a;
}
void dfs(int u, int fa, int d) {
  st[dfn[u] = ++cnt][0] = (ST){u, dep[u] = d};
  for (int i = head[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
    if (v != fa) {
      dfs(v, u, d + 1);
      st[++cnt][0] = (ST){u, d};
    }
}
inline void init(int n) {
  phi[1] = mu[1] = 1;
  for (int i = (2); i <= (n); ++i) {
    if (!phi[i]) {
      pri[++cnt] = i;
      mu[i] = -1;
      phi[i] = i - 1;
    }
    for (int j = (1); j <= (cnt); ++j) {
      if (i * pri[j] > n) break;
      if (!(i % pri[j])) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      mu[i * pri[j]] = -mu[i];
    }
  }
  for (int i = (1); i <= (n); ++i) {
    int x = 1LL * i * pow(phi[i], P - 2) % P;
    for (int j = (1); j <= (n / i); ++j) f[i * j] = (f[i * j] + x * mu[j]) % P;
  }
  cnt = 0;
  dfs(1, 0, 1);
  in[0] = lg[0] = -1;
  for (int i = (1); i <= (cnt); ++i) lg[i] = lg[i >> 1] + 1;
  for (int j = (1); j <= (18); ++j)
    for (int i = (1); i <= (cnt - (1 << j) + 1); ++i)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
inline int LCA(int x, int y) {
  x = dfn[x];
  y = dfn[y];
  if (x > y) swap(x, y);
  int k = lg[y - x + 1];
  return min(st[x][k], st[y - (1 << k) + 1][k]).p;
}
inline void ins(int x) {
  if (top < 2) {
    stk[++top] = x;
    return;
  }
  int lca = LCA(x, stk[top]);
  while (dfn[lca] < dfn[stk[top]]) {
    if (dfn[lca] > dfn[stk[top - 1]]) {
      ++in[fa[stk[top--]] = lca];
      break;
    }
    ++in[fa[stk[top]] = stk[top - 1]];
    --top;
  }
  if (stk[top] != lca) stk[++top] = lca;
  if (x != lca) stk[++top] = x;
}
inline int solve(int k) {
  int res = cnt = 0, tail = 0, s = 0;
  for (int i = (1); i <= (n / k); ++i) siz[a[++cnt] = p[i * k]] = phi[i * k];
  sort(a + 1, a + cnt + 1, cmp);
  if (a[1] != 1) ins(1);
  for (int i = (1); i <= (cnt); ++i) ins(a[i]);
  while (top) {
    fa[stk[top]] = stk[top - 1];
    ++in[stk[--top]];
  }
  for (int i = (1); i <= (cnt); ++i) {
    if (!in[a[i]]) q[++tail] = a[i];
    s = (s + siz[a[i]]) % P;
  }
  for (int i = (1); i <= (tail); ++i) {
    int v = q[i], u = fa[v];
    if (!(--in[u])) q[++tail] = u;
    res = (res + 1LL * siz[v] * (s - siz[v]) * (dep[v] - dep[u]) % P) % P;
    siz[u] = (siz[u] + siz[v]) % P;
    siz[v] = fa[v] = 0;
  }
  return res;
}
void main() {
  n = read();
  for (int i = (1); i <= (n); ++i) p[read()] = i;
  for (int i = (1); i <= (n - 1); ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  init(n);
  int ans = 0;
  for (int i = (1); i <= (n); ++i) ans = (ans + 1LL * f[i] * solve(i) % P) % P;
  printf("%d\n",
         (2LL * ans * pow(n, P - 2) % P * pow(n - 1, P - 2) % P + P) % P);
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
