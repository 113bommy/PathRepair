#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
struct Edge {
  int v;
  int w;
};
vector<Edge> e[N];
vector<vector<int> > vec;
int dfn[N], low[N], f[N], w[N], tot, ans;
void solve(int v, int u, int val) {
  int xans = val;
  for (int i = v; i != u; i = f[i]) {
    xans ^= w[i];
  }
  vector<int> ve;
  ve.push_back(xans ^ val);
  for (int i = v; i != u; i = f[i]) {
    ve.push_back(xans ^ w[i]);
  }
  vec.push_back(ve);
}
void dfs(int u, int pre) {
  f[u] = pre;
  dfn[u] = low[u] = ++tot;
  for (Edge edge : e[u]) {
    int v = edge.v;
    if (!dfn[v]) {
      w[v] = edge.w;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else if (v != pre) {
      low[u] = min(low[u], dfn[v]);
    }
    if (low[v] > dfn[u]) {
      ans ^= edge.w;
    }
  }
  for (Edge edge : e[u]) {
    int v = edge.v;
    if (f[v] != u && dfn[v] > dfn[u]) {
      solve(v, u, edge.w);
    }
  }
}
void FWT_xor(int *a, int opt, int N, int mod, int inv2) {
  for (int i = 1; i < N; i <<= 1)
    for (int p = i << 1, j = 0; j < N; j += p)
      for (int k = 0; k < i; ++k) {
        int X = a[j + k], Y = a[i + j + k];
        a[j + k] = (X + Y) % mod;
        a[i + j + k] = (X + mod - Y) % mod;
        if (opt == -1)
          a[j + k] = 1ll * a[j + k] * inv2 % mod,
                a[i + j + k] = 1ll * a[i + j + k] * inv2 % mod;
      }
}
int a[1 << 20], b[1 << 20];
int c[1 << 20], d[1 << 20];
int main() {
  int n, m, u, v, val;
  ans = tot = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &val);
    e[u].push_back({v, val});
    e[v].push_back({u, val});
  }
  dfs(1, 0);
  a[ans]++;
  c[ans]++;
  int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
  FWT_xor(a, 1, 1 << 17, mod1, (mod1 + 1) / 2);
  FWT_xor(c, 1, 1 << 17, mod2, (mod2 + 1) / 2);
  for (auto &v : vec) {
    memset(b, 0, sizeof(int) * ((1 << 17) + 5));
    memset(d, 0, sizeof(int) * ((1 << 17) + 5));
    for (auto &t : v) b[t]++, d[t]++;
    FWT_xor(b, 1, 1 << 17, mod1, (mod1 + 1) / 2);
    FWT_xor(d, 1, 1 << 17, mod2, (mod2 + 1) / 2);
    for (int i = 0; i < (1 << 17); i++) {
      a[i] = 1LL * a[i] * b[i] % mod1;
      c[i] = 1LL * c[i] * d[i] % mod2;
    }
  }
  FWT_xor(a, -1, 1 << 17, mod1, (mod1 + 1) / 2);
  FWT_xor(c, -1, 1 << 17, mod1, (mod1 + 1) / 2);
  for (int i = 0; i < (1 << 17); i++) {
    if (a[i] || c[i]) {
      printf("%d %d\n", i, a[i]);
      break;
    }
  }
}
