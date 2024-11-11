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
const int N = 1e5 + 5;
int n, mod, k, x, pw[N], ipw[N], a[N], to[N << 1], nxt[N << 1], head[N], cnt;
int sz[N], w[N], root, sum, vis[N], val1[N], val2[N], in[N], out[N];
map<int, int> M1, M2;
int fastpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
void getroot(int u, int f) {
  sz[u] = 1;
  w[u] = 0;
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f && !vis[to[e]]) {
      getroot(to[e], u);
      sz[u] += sz[to[e]];
      w[u] = max(w[u], sz[to[e]]);
    }
  w[u] = max(w[u], sum - sz[u]);
  if (w[u] < w[root]) root = u;
}
void dfs1(int u, int f, int d) {
  ++M1[1ll * (x - val1[u] + mod) * ipw[d + 1] % mod];
  ++M2[val2[u]];
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f && !vis[to[e]]) {
      val1[to[e]] = (1ll * val1[u] * k + a[to[e]]) % mod;
      val2[to[e]] = (val2[u] + 1ll * pw[d] * a[to[e]]) % mod;
      dfs1(to[e], u, d + 1);
    }
}
void dfs2(int u, int f, int d, int op) {
  out[u] += op * M2[1ll * (x - val1[u] + mod) * ipw[d + 1] % mod];
  in[u] += op * M1[val2[u]];
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f && !vis[to[e]]) dfs2(to[e], u, d + 1, op);
}
void calc(int u, int d, int op, int s1, int s2) {
  M1.clear();
  M2.clear();
  val1[u] = s1;
  val2[u] = s2;
  dfs1(u, 0, d);
  dfs2(u, 0, d, op);
}
void solve(int u) {
  vis[u] = 1;
  calc(u, 0, 1, a[u], 0);
  for (int e = head[u]; e; e = nxt[e])
    if (!vis[to[e]]) {
      calc(to[e], 1, -1, (1ll * a[u] * k + a[to[e]]) % mod, a[to[e]]);
      getroot(to[e], 0);
      root = 0;
      sum = sz[to[e]];
      getroot(to[e], 0);
      solve(root);
    }
}
int main() {
  n = gi();
  mod = gi();
  k = gi();
  x = gi();
  for (int i = pw[0] = ipw[0] = 1, inv = fastpow(k, mod - 2); i <= n; ++i)
    pw[i] = 1ll * pw[i - 1] * k % mod, ipw[i] = 1ll * ipw[i - 1] * inv % mod;
  for (int i = 1; i <= n; ++i) a[i] = gi();
  for (int i = 1; i < n; ++i) {
    int u = gi(), v = gi();
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    to[++cnt] = u;
    nxt[cnt] = head[v];
    head[v] = cnt;
  }
  sum = w[0] = n;
  getroot(1, 0);
  solve(root);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1ll * in[i] * (n - out[i]) + 1ll * out[i] * (n - in[i]) +
           2ll * in[i] * (n - in[i]) + 2ll * out[i] * (n - out[i]);
  }
  printf("%I64d\n", 1ll * n * n * n - ans / 2);
  return 0;
}
