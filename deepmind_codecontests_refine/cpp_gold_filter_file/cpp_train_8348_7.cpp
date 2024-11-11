#include <bits/stdc++.h>
const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;
int n;
int l[maxn], r[maxn];
std::vector<int> adj[maxn];
long long g[maxn];
std::vector<int> ins[maxn];
std::vector<int> del[maxn];
int N = 0;
long long P = 1;
long long cur = 0, sum_g = 0, sum = 0;
int size[maxn], dep[maxn], fa[maxn], son[maxn];
int top[maxn], ind[maxn], idx;
int seg[maxn << 2], tag[maxn << 2];
long long fix(long long x) { return (x % mod + mod) % mod; }
long long powermod(long long x, long long y) {
  long long z = 1;
  while (y) {
    if (y & 1) z = z * x % mod;
    x = x * x % mod, y >>= 1;
  }
  return z;
}
void pre_dfs(int u, int fr) {
  size[u] = 1;
  dep[u] = dep[fr] + 1;
  fa[u] = fr;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != fr) {
      pre_dfs(v, u);
      if (size[v] > size[son[u]]) {
        son[u] = v;
      }
    }
  }
}
void dfs(int u, int fr) {
  ind[u] = ++idx;
  if (son[fa[u]] == u) {
    top[u] = top[fa[u]];
  } else {
    top[u] = u;
  }
  if (son[u]) {
    dfs(son[u], u);
  }
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != fr && v != son[u]) {
      dfs(v, u);
    }
  }
}
void atomic_modify(int l, int r, int v, int x) {
  seg[x] = fix(seg[x] + 1ll * (r - l + 1) * v);
  tag[x] = fix(tag[x] + v);
}
void pushdown(int ll, int rr, int x) {
  if (tag[x]) {
    int mid = (ll + rr) >> 1;
    atomic_modify(ll, mid, tag[x], x << 1);
    atomic_modify(mid + 1, rr, tag[x], x << 1 | 1);
    tag[x] = 0;
  }
}
void update(int x) { seg[x] = (seg[x << 1] + seg[x << 1 | 1]) % mod; }
void seg_modify(int l, int r, int v, int ll, int rr, int x) {
  if (l == ll && r == rr) {
    atomic_modify(l, r, v, x);
  } else {
    int mid = (ll + rr) >> 1;
    pushdown(ll, rr, x);
    if (r <= mid) {
      seg_modify(l, r, v, ll, mid, x << 1);
    } else if (l > mid) {
      seg_modify(l, r, v, mid + 1, rr, x << 1 | 1);
    } else {
      seg_modify(l, mid, v, ll, mid, x << 1);
      seg_modify(mid + 1, r, v, mid + 1, rr, x << 1 | 1);
    }
    update(x);
  }
}
long long seg_query(int l, int r, int ll, int rr, int x) {
  if (l == ll && r == rr) {
    return seg[x];
  } else {
    int mid = (ll + rr) >> 1;
    pushdown(ll, rr, x);
    if (r <= mid) {
      return seg_query(l, r, ll, mid, x << 1);
    } else if (l > mid) {
      return seg_query(l, r, mid + 1, rr, x << 1 | 1);
    } else {
      return seg_query(l, mid, ll, mid, x << 1) +
             seg_query(mid + 1, r, mid + 1, rr, x << 1 | 1);
    }
  }
}
void modify(int u, int val) {
  while (u) {
    seg_modify(ind[top[u]], ind[u], val, 1, n, 1);
    u = fa[top[u]];
  }
}
long long query(int u) {
  long long res = 0;
  while (u) {
    res += seg_query(ind[top[u]], ind[u], 1, n, 1);
    u = fa[top[u]];
  }
  return res % mod;
}
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    P = fix(P * (r[i] - l[i] + 1));
    N = std::max(N, r[i] + 1);
    ins[l[i]].push_back(i);
    del[r[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    g[i] = powermod(r[i] - l[i] + 1, mod - 2);
  }
  pre_dfs(1, 0);
  dfs(1, 0);
  long long ans = 0;
  for (int c = 0; c <= N; c++) {
    for (int i = 0; i < ins[c].size(); i++) {
      int u = ins[c][i];
      int tu = dep[u] * g[u] % mod;
      cur = fix(cur + g[u] * sum + tu * sum_g - 2 * query(u) * g[u]);
      sum_g = fix(sum_g + g[u]);
      sum = fix(sum + dep[u] * g[u]);
      modify(u, g[u]);
    }
    ans = fix(ans + cur * P);
    for (int i = 0; i < del[c].size(); i++) {
      int u = del[c][i];
      int tu = dep[u] * g[u] % mod;
      modify(u, mod - g[u]);
      sum = fix(sum - dep[u] * g[u]);
      sum_g = fix(sum_g - g[u]);
      cur = fix(cur - (g[u] * sum + tu * sum_g - 2 * query(u) * g[u]));
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
