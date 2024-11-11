#include <bits/stdc++.h>
using namespace std;
int base = 1145141;
const long long mod = 1004535809;
long long p[600001], inv[600001], has[2][300001];
int n, m;
int d[300001];
int v[600001];
int nxt[600001];
int tot;
int up[20][300001];
int depth[300001];
int dep[600005];
int md[300001];
int son[300001];
int top[300001];
int lg[600005];
int dfn[600005];
int num[300001];
int f[600005][21];
string s;
vector<int> q[2][300001];
inline void add(int x, int y) {
  v[++tot] = y;
  nxt[tot] = d[x];
  d[x] = tot;
  return;
}
void dfs(int x, int fa) {
  up[0][x] = fa;
  md[x] = depth[x] = depth[fa] + 1;
  has[0][x] = ((s[x] - 'a' + 1) * p[depth[x] - 1] % mod + has[0][fa]) % mod;
  has[1][x] = (has[1][fa] * base % mod + s[x] - 'a' + 1) % mod;
  dfn[++dfn[0]] = x;
  dep[dfn[0]] = depth[x];
  num[x] = dfn[0];
  f[dfn[0]][0] = dfn[0];
  for (int i = d[x]; i; i = nxt[i]) {
    if (v[i] != fa) {
      dfs(v[i], x);
      if (md[v[i]] > md[x]) {
        md[x] = md[v[i]];
        son[x] = v[i];
      }
      dfn[++dfn[0]] = x;
      dep[dfn[0]] = depth[x];
      f[dfn[0]][0] = dfn[0];
    }
  }
  return;
}
inline int LCA(int x, int y) {
  x = num[x];
  y = num[y];
  if (x > y) {
    swap(x, y);
  }
  int s = lg[y - x + 1];
  return dep[f[x][s]] < dep[f[y - (1 << s) + 1][s]]
             ? dfn[f[x][s]]
             : dfn[f[y - (1 << s) + 1][s]];
}
inline int kasumi(int a, int t) {
  int ans = 1;
  while (t) {
    if (t % 2) {
      ans = (long long)ans * a % mod;
    }
    a = (long long)a * a % mod;
    t /= 2;
  }
  return ans;
}
inline void dfs2(int x, int t, int fa) {
  top[x] = t;
  if (x == t) {
    int now = x;
    for (int i = 0; i <= md[x] - depth[x]; ++i) {
      q[0][x].push_back(now);
      now = up[0][now];
    }
    now = x;
    for (int i = 0; i <= md[x] - depth[x]; ++i) {
      q[1][x].push_back(now);
      now = son[now];
    }
  }
  if (son[x]) {
    dfs2(son[x], t, x);
  }
  for (int i = d[x]; i; i = nxt[i]) {
    if (v[i] != fa && v[i] != son[x]) {
      dfs2(v[i], v[i], x);
    }
  }
  return;
}
inline int find_kth(int x, int k) {
  if (!k) {
    return x;
  }
  x = up[lg[k]][x];
  k -= (1 << lg[k]) + (depth[x] - depth[top[x]]);
  x = top[x];
  return k >= 0 ? q[0][x][k] : q[1][x][-k];
}
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return x;
}
int main() {
  n = read();
  p[0] = inv[0] = 1;
  lg[0] = -1;
  for (int i = 1; i <= 600000; i++) {
    p[i] = p[i - 1] * base % mod;
    inv[i] = kasumi(p[i], mod - 2);
    lg[i] = lg[i >> 1] + 1;
  }
  cin >> s;
  s = " " + s;
  for (int i = 1; i < n; i++) {
    int a = read(), b = read();
    add(a, b);
    add(b, a);
  }
  dfs(1, 0);
  dfs2(1, 1, 0);
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << i) - 1 <= dfn[0]; j++) {
      f[j][i] = (dep[f[j][i - 1]] < dep[f[j + (1 << (i - 1))][i - 1]]
                     ? f[j][i - 1]
                     : f[j + (1 << (i - 1))][i - 1]);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read(), c = read(), d = read();
    int lca1 = LCA(a, b), lca2 = LCA(c, d);
    int l = 1, r = min(depth[a] + depth[b] - 2 * depth[lca1] + 1,
                       depth[c] + depth[d] - 2 * depth[lca2] + 1);
    int mid;
    int ans = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      long long hash1 = 0, hash2 = 0;
      if (depth[a] - depth[lca1] + 1 >= mid) {
        int ta = up[0][find_kth(a, mid - 1)];
        hash1 = (has[0][a] - has[0][ta] + mod) * inv[depth[ta]] % mod;
      } else {
        hash1 = (has[0][a] - has[0][up[0][lca1]] + mod) *
                inv[depth[up[0][lca1]]] % mod;
        int tb = find_kth(
            b, depth[b] - (depth[lca1] + mid - (depth[a] - depth[lca1] + 1)));
        hash1 = (hash1 * p[mid - (depth[a] - depth[lca1] + 1)] +
                 (has[1][tb] -
                  has[1][lca1] * p[mid - (depth[a] - depth[lca1] + 1)] % mod +
                  mod)) %
                mod;
      }
      if (depth[c] - depth[lca2] + 1 >= mid) {
        int tc = up[0][find_kth(c, mid - 1)];
        hash2 = (has[0][c] - has[0][tc] + mod) * inv[depth[tc]] % mod;
      } else {
        hash2 = (has[0][c] - has[0][up[0][lca2]] + mod) *
                inv[depth[up[0][lca2]]] % mod;
        int td = find_kth(
            d, depth[d] - (depth[lca2] + mid - (depth[c] - depth[lca2] + 1)));
        hash2 = (hash2 * p[mid - (depth[c] - depth[lca2] + 1)] +
                 (has[1][td] -
                  has[1][lca2] * p[mid - (depth[c] - depth[lca2] + 1)] % mod +
                  mod)) %
                mod;
      }
      if (hash1 != hash2) {
        r = mid - 1;
      } else {
        l = mid + 1;
        ans = mid;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
