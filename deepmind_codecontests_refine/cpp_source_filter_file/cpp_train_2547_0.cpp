#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool checkMax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMax(T &a, const Args... arg) {
  checkMax(a, max(arg...));
}
template <class T>
inline bool checkMin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMin(T &a, const Args... arg) {
  checkMin(a, min(arg...));
}
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 3e5 + 5;
const int LOG = 20;
const int MOD1 = 1004535809;
const int MOD2 = 1e9 + 7;
const int BASE1 = 131;
const int BASE2 = 233;
void addmod(int &x, int y, int MOD) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void submod(int &x, int y, int MOD) {
  x -= y;
  if (x < 0) x += MOD;
}
int add(int x, int y, int MOD) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int sub(int x, int y, int MOD) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}
int power(int x, int y, int MOD) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % MOD;
    x = 1ll * x * x % MOD;
    y >>= 1;
  }
  return res;
}
int n, Q, len, tot;
int head[MAXN], top[MAXN], dep[MAXN], son[MAXN], f[MAXN][LOG], lg[MAXN],
    maxdep[MAXN];
int pow1[MAXN], pow2[MAXN], inv1[MAXN], inv2[MAXN], dfn[MAXN],
    st[MAXN << 1][LOG];
char s[MAXN];
vector<int> up[MAXN], down[MAXN];
struct Edge {
  int to, next;
} e[MAXN << 1];
struct HashInt {
  int val1, val2, len;
  HashInt() {}
  HashInt(int _val1, int _val2, int _len)
      : val1(_val1), val2(_val2), len(_len) {}
  HashInt operator+(const HashInt &rhs) const {
    return HashInt(((long long)val1 * pow1[rhs.len] + rhs.val1) % MOD1,
                   ((long long)val2 * pow2[rhs.len] + rhs.val2) % MOD2,
                   len + rhs.len);
  }
  bool operator==(const HashInt &rhs) const {
    return val1 == rhs.val1 && val2 == rhs.val2 && len == rhs.len;
  }
  void push_back(int x) {
    val1 = (val1 + (long long)x * pow1[len]) % MOD1;
    val2 = (val2 + (long long)x * pow2[len]) % MOD2;
    len += 1;
  }
  void push_front(int x) {
    val1 = ((long long)val1 * BASE1 + x) % MOD1;
    val2 = ((long long)val2 * BASE2 + x) % MOD2;
    len += 1;
  }
} a[MAXN], b[MAXN];
void add_edge(int u, int v) {
  e[++len] = (Edge){v, head[u]};
  head[u] = len;
}
void dfs1(int u, int fa) {
  maxdep[u] = dep[u] = dep[fa] + 1;
  f[u][0] = fa;
  st[dfn[u] = ++tot][0] = u;
  for (int i = 1; i < LOG; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  a[u] = a[fa];
  a[u].push_front(s[u]);
  b[u] = b[fa];
  b[u].push_back(s[u]);
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs1(v, u);
    st[++tot][0] = u;
    if (maxdep[v] > maxdep[u]) son[u] = v, maxdep[u] = maxdep[v];
  }
}
void dfs2(int u, int t) {
  top[u] = t;
  if (u == t) {
    for (int i = 0, v = u; i <= maxdep[u] - dep[u]; i++)
      up[u].push_back(v), v = f[v][0];
    for (int i = 0, v = u; i <= maxdep[u] - dep[u]; i++)
      down[u].push_back(v), v = son[v];
  }
  if (son[u]) dfs2(son[u], t);
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v != son[u] && v != f[u][0]) dfs2(v, v);
  }
}
int query(int u, int k) {
  if (k >= dep[u]) return 0;
  if (!k) return u;
  u = f[u][lg[k]];
  k -= 1 << lg[k];
  k -= dep[u] - dep[top[u]];
  u = top[u];
  return k >= 0 ? up[u][k] : down[u][-k];
}
int getLCA(int u, int v) {
  int l = dfn[u], r = dfn[v];
  if (l > r) swap(l, r);
  int k = lg[r - l + 1];
  return min(st[l][k], st[r - (1 << k) + 1][k],
             [&](const int &x, const int &y) { return dep[x] < dep[y]; });
}
HashInt getUp(int u, int v) {
  int val1 = (long long)(b[u].val1 - b[v].val1 + MOD1) * inv1[b[v].len] % MOD1;
  int val2 = (long long)(b[u].val2 - b[v].val2 + MOD2) * inv2[b[v].len] % MOD2;
  return HashInt(val1, val2, b[u].len - b[v].len);
}
HashInt getDown(int u, int v) {
  int val1 = sub(a[v].val1,
                 (long long)a[u].val1 * pow1[a[v].len - a[u].len] % MOD1, MOD1);
  int val2 = sub(a[v].val2,
                 (long long)a[u].val2 * pow2[a[v].len - a[u].len] % MOD2, MOD2);
  return HashInt(val1, val2, a[v].len - a[u].len);
}
void Init() {
  pow1[0] = pow2[0] = 1;
  inv1[0] = inv2[0] = 1;
  int iBASE1 = power(BASE1, MOD1 - 2, MOD1);
  int iBASE2 = power(BASE2, MOD2 - 2, MOD2);
  for (int i = 1; i <= n; i++) {
    pow1[i] = (long long)pow1[i - 1] * BASE1 % MOD1;
    pow2[i] = (long long)pow2[i - 1] * BASE2 % MOD2;
    inv1[i] = (long long)inv1[i - 1] * iBASE1 % MOD1;
    inv2[i] = (long long)inv2[i - 1] * iBASE2 % MOD2;
  }
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 2; i <= tot; i++) lg[i] = lg[i >> 1] + 1;
  for (int j = 1; (1 << j) <= tot; j++) {
    for (int i = 1; i + (1 << j) - 1 <= tot; i++)
      st[i][j] =
          min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1],
              [&](const int &x, const int &y) { return dep[x] < dep[y]; });
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%s", &n, s + 1);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  Init();
  scanf("%d", &Q);
  while (Q--) {
    int u1, v1, u2, v2;
    scanf("%d%d%d%d", &u1, &v1, &u2, &v2);
    int lca1 = getLCA(u1, v1), lca2 = getLCA(u2, v2);
    int len1 = dep[u1] + dep[v1] - 2 * dep[lca1] + 1;
    int len2 = dep[u2] + dep[v2] - 2 * dep[lca2] + 1;
    int l = 1, r = min(len1, len2), res = 0;
    HashInt t1 = getUp(u1, lca1), t2 = getUp(u2, lca2);
    while (l <= r) {
      int mid = (l + r) >> 1;
      HashInt x = dep[u1] - mid + 1 >= dep[lca1]
                      ? getUp(u1, query(u1, mid))
                      : t1 + getDown(f[lca1][0], query(v1, len1 - mid));
      HashInt y = dep[u2] - mid + 1 >= dep[lca2]
                      ? getUp(u2, query(u2, mid))
                      : t2 + getDown(f[lca2][0], query(v2, len2 - mid));
      if (x == y)
        res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    printf("%d\n", res);
  }
  return 0;
}
