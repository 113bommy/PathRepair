#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
long long sum1[maxn], sum2[maxn], size[maxn];
int dfn[maxn], dfncnt, f[maxn][20], d[maxn][20], n, dep[maxn];
vector<int> side[maxn], w[maxn];
int trans(int u, int val) {
  return (sum2[u] + size[u] * val % mod * val % mod + 2 * val * sum1[u] % mod) %
         mod;
}
void dfs1(int u, int fa) {
  f[u][0] = fa;
  dfn[u] = ++dfncnt;
  size[u] = 1;
  dep[u] = dep[fa] + 1;
  for (int i = 0; i < side[u].size(); i++) {
    int v = side[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    size[u] += size[v];
    d[v][0] = w[u][i];
    sum1[u] = (sum1[u] + sum1[v] + w[u][i] * size[v] % mod) % mod;
    sum2[u] = (sum2[u] + trans(v, w[u][i])) % mod;
  }
}
void init() {
  for (int i = (1), iend = (19); i <= iend; i++)
    for (int j = (1), jend = (n); j <= jend; j++)
      f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = (1), iend = (19); i <= iend; i++)
    for (int j = (1), jend = (n); j <= jend; j++)
      d[j][i] = (d[j][i - 1] + d[f[j][i - 1]][i - 1]) % mod;
}
int get_dis(int u, int v) {
  long long ans = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (dep[f[u][i]] >= dep[v]) ans = (ans + d[u][i]) % mod, u = f[u][i];
  if (u == v) return ans;
  for (int i = 19; i >= 0; i--)
    if (f[u][i] != f[v][i])
      ans = (1ll * ans + d[u][i] + d[v][i]) % mod, u = f[u][i], v = f[v][i];
  return (1ll * ans + d[u][0] + d[v][0]) % mod;
}
struct Query {
  int u, v, idx;
  bool insubtree;
} q[maxn];
int ans[maxn];
bool cmp(Query a, Query b) { return dfn[a.u] < dfn[b.u]; }
int now = 1, t;
void dfs2(int u, int fa) {
  while (now <= t && q[now].u == u) {
    int v = q[now].v, idx = q[now].idx;
    if (q[now].insubtree) {
      ans[idx] = (sum2[u] - 2 * trans(f[v][0], get_dis(f[v][0], u))) % mod;
      ans[idx] = (ans[idx] + mod) % mod;
    } else {
      ans[idx] = (2 * trans(v, get_dis(u, v)) - sum2[u]) % mod;
      ans[idx] = (ans[idx] + mod) % mod;
    }
    now++;
  }
  for (int i = 0; i < side[u].size(); i++) {
    int v = side[u][i];
    if (v == fa) continue;
    long long bku1 = sum1[u], bku2 = sum2[u], bku3 = size[u];
    long long bkv1 = sum1[v], bkv2 = sum2[v], bkv3 = size[v];
    int tmp1 = trans(v, w[u][i]),
        tmp2 = trans(u, w[u][i]) - trans(v, 2 * w[u][i]);
    tmp2 = (tmp2 % mod + mod) % mod;
    sum1[u] = (bku1 - (bkv1 + w[u][i] * bkv3) % mod) % mod;
    sum1[u] = (sum1[u] % mod + mod) % mod;
    sum1[v] = ((bku1 - (bkv1 + w[u][i] * bkv3) % mod) +
               (bku3 - bkv3) * w[u][i] % mod + bkv1) %
              mod;
    sum1[v] = (sum1[v] % mod + mod) % mod;
    sum2[u] = (bku2 - tmp1) % mod;
    sum2[u] = (sum2[u] % mod + mod) % mod;
    sum2[v] = tmp2 + bkv2;
    sum2[v] = (sum2[v] % mod + mod) % mod;
    size[u] = bku3 - bkv3;
    size[v] = bku3;
    dfs2(v, u);
    sum1[u] = bku1, sum2[u] = bku2, size[u] = bku3;
    sum1[v] = bkv1, sum2[v] = bkv2, size[v] = bkv3;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = (1), iend = (n - 1); i <= iend; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    side[u].push_back(v);
    w[u].push_back(val);
    side[v].push_back(u);
    w[v].push_back(val);
  }
  dfs1(1, 0);
  init();
  cin >> t;
  for (int i = (1), iend = (t); i <= iend; i++) {
    cin >> q[i].u >> q[i].v;
    q[i].idx = i;
    if (dfn[q[i].v] <= dfn[q[i].u] &&
        dfn[q[i].u] <= dfn[q[i].v] + size[q[i].v] - 1)
      q[i].insubtree = 1;
  }
  sort(q + 1, q + 1 + t, cmp);
  dfs2(1, 0);
  for (int i = (1), iend = (t); i <= iend; i++) {
    cout << (ans[i] % mod + mod) % mod << endl;
  }
  return 0;
}
