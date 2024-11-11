#include <bits/stdc++.h>
using namespace std;
inline int getval() {
  char c = getchar();
  int x;
  bool p;
  x = p = 0;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') p = 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (p) x = -x;
  return x;
}
const int N = 1e5 + 10, M = 1e6 + 10, V = 1e7 + 10, LOG = 18, LOG2 = 25;
const int MOD = 1e9 + 7;
inline int Pow(int a, int k) {
  int ans = 1;
  for (int x = a; k; k >>= 1, x = 1ll * x * x % MOD)
    if (k & 1) ans = 1ll * ans * x % MOD;
  return ans;
}
struct node {
  int u, v, next;
} edge[N << 1];
int last[N], le, a[N];
void add(int u, int v) {
  edge[++le].u = u, edge[le].v = v, edge[le].next = last[u], last[u] = le;
  edge[++le].u = v, edge[le].v = u, edge[le].next = last[v], last[v] = le;
}
int dp[LOG][N], n, deep[N];
void dfs1(int u, int fa) {
  dp[0][u] = fa, deep[u] = deep[fa] + 1;
  for (int i = last[u]; i; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa) continue;
    dfs1(v, u);
  }
}
void getdp() {
  for (int i = 1; i < LOG; ++i) {
    for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][dp[i - 1][j]];
  }
}
int getlca(int u, int v) {
  if (deep[u] < deep[v]) swap(u, v);
  for (int i = LOG - 1; ~i; --i)
    if (deep[dp[i][u]] >= deep[v]) u = dp[i][u];
  if (u == v) return u;
  for (int i = LOG - 1; ~i; --i)
    if (dp[i][u] != dp[i][v]) u = dp[i][u], v = dp[i][v];
  return dp[0][u];
}
int id[V], cnt[M][LOG2], lp, x[N], tans[N];
vector<int> qnum[N], qtype[N];
int *s[N * LOG2], ls, pre[N * LOG2];
void qadd(int d, int c) {
  if (!id[d]) id[d] = ++lp;
  s[++ls] = &cnt[id[d]][c], pre[ls] = cnt[id[d]][c];
  ++cnt[id[d]][c];
}
void pop(int to) {
  while (ls != to) *s[ls] = pre[ls], --ls;
}
int qask(int d, int c) {
  if (!id[d]) return 1;
  int now = 1, ans = 1;
  for (int i = 1; i <= c; ++i) {
    now = 1ll * now * d % MOD;
    ans = 1ll * ans * Pow(now, cnt[id[d]][i]) % MOD;
  }
  for (int i = c + 1; i < LOG2; ++i)
    ans = 1ll * ans * Pow(now, cnt[id[d]][i]) % MOD;
  return ans;
}
void dfs2(int u, int fa) {
  int lst = ls;
  for (int d = 2; d * d <= a[u]; ++d)
    if (a[u] % d == 0) {
      int c = 0;
      while (a[u] % d == 0) ++c, a[u] /= d;
      qadd(d, c);
    }
  if (a[u] > 1) qadd(a[u], 1);
  int sz = qnum[u].size();
  for (int i = 0; i < sz; ++i) {
    int num = qnum[u][i], nowx = x[num], type = qtype[u][i], sum = 1;
    for (int d = 2; d * d <= nowx; ++d)
      if (nowx % d == 0) {
        int c = 0;
        while (nowx % d == 0) ++c, nowx /= d;
        sum = 1ll * sum * qask(d, c) % MOD;
      }
    if (nowx > 1 && id[nowx]) sum = 1ll * sum * qask(nowx, 1) % MOD;
    tans[num] = 1ll * tans[num] * (type == 1 ? sum : Pow(sum, MOD - 2)) % MOD;
  }
  for (int i = last[u]; i; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa) continue;
    dfs2(v, u);
  }
  pop(lst);
}
int main() {
  n = getval();
  for (int i = 1; i < n; ++i) {
    int u = getval(), v = getval();
    add(u, v);
  }
  dfs1(1, 0);
  getdp();
  for (int i = 1; i <= n; ++i) a[i] = getval();
  int q = getval();
  for (int i = 1; i <= q; ++i) {
    int u = getval(), v = getval(), lca = getlca(u, v);
    x[i] = getval(), tans[i] = 1;
    qnum[u].push_back(i), qtype[u].push_back(1);
    qnum[v].push_back(i), qtype[v].push_back(1);
    qnum[lca].push_back(i), qtype[lca].push_back(-1);
    qnum[dp[0][lca]].push_back(i), qtype[dp[0][lca]].push_back(1);
  }
  dfs2(1, 0);
  for (int i = 1; i <= q; ++i) printf("%d\n", tans[i]);
  return 0;
}
