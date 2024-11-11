#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
namespace Tree {
int f[maxn], top[maxn], son[maxn], sz[maxn], id[maxn], rnk[maxn], depth[maxn];
int tot;
std::vector<int> vec[maxn];
int n, q;
void dfs1(int u) {
  sz[u] = 1;
  depth[u] = depth[f[u]] + 1;
  for (const auto &v : vec[u]) {
    if (v == f[u]) continue;
    f[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) {
      son[u] = v;
    }
  }
}
void dfs2(int u, int tp) {
  id[u] = ++tot;
  rnk[tot] = u;
  top[u] = tp;
  if (son[u]) {
    dfs2(son[u], tp);
  }
  for (const auto &v : vec[u]) {
    if (v == f[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
long long sum[maxn << 2];
void pushup(int o) { sum[o] = sum[o << 1] + sum[o << 1 | 1]; }
void update(int o, int L, int R, int pos, int v) {
  if (L == R) {
    sum[o] = v;
    return;
  }
  int mid = (L + R) / 2;
  if (pos <= mid)
    update(o << 1, L, mid, pos, v);
  else
    update(o << 1 | 1, mid + 1, R, pos, v);
  pushup(o);
}
long long query(int o, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    return sum[o];
  }
  int mid = (L + R) / 2;
  long long ret = 0;
  if (l <= mid) ret += query(o << 1, L, mid, l, r);
  if (r > mid) ret += query(o << 1 | 1, mid + 1, R, l, r);
  return ret;
}
long long query(int x, int y) {
  long long ret = 0;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      std::swap(x, y);
    }
    ret += query(1, 1, n, id[top[x]], id[x]);
    x = f[top[x]];
  }
  if (depth[x] > depth[y]) {
    std::swap(x, y);
  }
  ret += query(1, 1, n, id[x], id[y]);
  return ret;
}
};  // namespace Tree
using namespace Tree;
int arr[maxn];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    arr[i] = std::abs(arr[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    vec[u].emplace_back(v);
    vec[v].emplace_back(u);
  }
  dfs1(1);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, id[i], arr[i]);
  }
  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    v = std::abs(v);
    if (op == 1) {
      arr[u] = v;
      update(1, 1, n, id[u], v);
    } else {
      long long ans = query(u, v);
      ans *= 2;
      ans -= arr[u] + arr[v];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
