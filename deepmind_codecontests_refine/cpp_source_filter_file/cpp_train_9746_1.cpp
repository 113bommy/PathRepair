#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline bool Max(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool Min(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 1e5 + 7;
int n, m, edc = 1, q;
int head[N], son[N], dep[N], fa[N], sz[N], par[N];
long long ans, f[N];
struct edge {
  int last, to;
  edge() {}
  edge(int last, int to) : last(last), to(to) {}
} e[N * 4];
void Add(int a, int b) {
  e[++edc] = edge(head[a], b), head[a] = edc;
  e[++edc] = edge(head[b], a), head[b] = edc;
}
void dfs(int u) {
  for (int i = head[u], v = e[i].to; i; i = e[i].last, v = e[i].to)
    if (v ^ fa[u]) {
      fa[v] = u, dep[v] = dep[u] + 1, dfs(v);
      if (son[u]) f[u] += 1ll * son[u] * (son[v] + 1);
      son[u] += (son[v] + 1);
    }
  sz[u] = 1;
  ans += f[u] + 1ll * (n - son[u] - sz[u]) * son[u];
}
int g(int a) { return par[a] == a ? a : par[a] = g(par[a]); }
long long c2(int x) {
  if (x < 2) return 0;
  return 1ll * x * (x - 1);
}
long long c3(int x) {
  if (x < 3) return 0;
  return 1ll * x * (x - 1) * (x - 2);
}
void merge(int x, int y) {
  while (x ^ y) {
    if (dep[x] > dep[y]) swap(x, y);
    int p = g(fa[y]);
    ans -= c2(sz[y]) * (n - sz[y]) * 2 + c3(sz[y]) +
           2 * (f[y] + 1ll * (n - sz[y] - son[y]) * son[y]) * sz[y];
    ans -= c2(sz[p]) * (n - sz[p]) * 2 + c3(sz[p]) +
           2 * (f[p] + 1ll * (n - sz[p] - son[p]) * son[p]) * sz[p];
    f[p] -= 1ll * (son[p] - son[y] - sz[y]) * (son[y] + sz[y]);
    son[p] -= sz[y], sz[p] += sz[y];
    f[p] += (son[p] - son[y]) * son[y] + f[y];
    ans += c2(sz[p]) * (n - sz[p]) * 2 + c3(sz[p]) +
           2 * (f[p] + 1ll * (n - sz[p] - son[p]) * son[p]) * sz[p];
    par[y] = p;
    y = p;
  }
}
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) par[i] = i;
  for (int i = 1; i <= n - 1; ++i) Add(gi(), gi());
  dep[1] = 1, dfs(1);
  printf("%I64d\n", ans <<= 1);
  q = gi();
  while (q--) {
    int x = g(gi()), y = g(gi());
    merge(x, y);
    printf("%I64d\n", ans);
  }
  return 0;
}
