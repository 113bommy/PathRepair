#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline int lb(int x) { return x & -x; }
long long qpow(long long base, int n) {
  if (base == 0) return 0;
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= base;
    n >>= 1;
    base *= base;
  }
  return ans;
}
int n, q, K;
vector<int> adj[maxn];
vector<int> g[maxn];
int dfn[maxn], cnt, dep[maxn], k[maxn], f[maxn][23];
bool vis[maxn];
int dp[maxn][2];
void dfs(int rt, int fa) {
  dep[rt] = dep[fa] + 1;
  for (int i = 1; (1 << i) <= dep[rt]; ++i) f[rt][i] = f[f[rt][i - 1]][i - 1];
  for (auto x : adj[rt]) {
    if (x == fa) continue;
    f[x][0] = rt;
    dfs(x, rt);
  }
  dfn[rt] = ++cnt;
}
inline bool cmp(const int &i, const int &j) { return dfn[i] < dfn[j]; }
inline int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; --i) {
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
  }
  for (int i = 20; i >= 0; --i) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
inline void build() {
  static int stk[maxn];
  int sz = 0;
  stk[sz++] = 0;
  for (int i = (1); i <= (K); ++i) {
    int u = k[i], lca = LCA(u, stk[sz - 1]);
    if (lca == stk[sz - 1])
      stk[sz++] = u;
    else {
      while (sz - 2 >= 0 && dep[stk[sz - 2]] >= dep[lca]) {
        int x = stk[sz - 2], y = stk[sz - 1];
        g[x].push_back(y);
        g[y].push_back(x);
        sz--;
      }
      if (stk[sz - 1] != lca) {
        g[lca].push_back(stk[sz - 1]);
        g[stk[sz - 1]].push_back(lca);
        --sz;
        stk[sz++] = lca;
      }
      if (stk[sz - 1] != u) stk[sz++] = u;
    }
  }
  for (int i = 0; i < sz - 1; ++i) {
    g[stk[i]].push_back(stk[i + 1]);
    g[stk[i + 1]].push_back(stk[i]);
  }
}
void DP(int u, int p) {
  for (auto x : g[u]) {
    if (x == p) continue;
    DP(x, u);
    dp[x][1] += dp[x][1];
    dp[u][0] += dp[x][0];
  }
  if (vis[u]) {
    dp[u][0] += dp[u][1];
    dp[u][1] = 1;
  } else {
    dp[u][0] += (dp[u][1] > 1);
    dp[u][1] = (dp[u][1] == 1);
  }
}
void Clear(int rt, int p) {
  for (auto x : g[rt]) {
    if (x == p) continue;
    Clear(x, rt);
  }
  g[rt].clear();
  vis[rt] = 0;
  dp[rt][0] = dp[rt][1] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = (2); i <= (n); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  scanf("%d", &q);
  for (int i = (1); i <= (q); ++i) {
    bool flag = 1;
    scanf("%d", &K);
    for (int i = (1); i <= (K); ++i) {
      scanf("%d", &k[i]);
      vis[k[i]] = 1;
    }
    sort(k + 1, k + K + 1, cmp);
    for (int j = (1); j <= (K); ++j)
      if (vis[f[k[j]][0]] == 1) {
        flag = 0;
        break;
      }
    build();
    if (!flag) {
      printf("-1\n");
    } else {
      DP(g[0][0], 0);
      printf("%d\n", dp[g[0][0]][0]);
    }
    Clear(g[0][0], 0);
    g[0].clear();
  }
}
