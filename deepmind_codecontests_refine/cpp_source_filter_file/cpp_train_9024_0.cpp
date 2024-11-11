#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005, MAXK = 75, mod = 998244353;
int a[MAXN], b[MAXN];
int n, m, k;
int N;
int C[80][80];
struct node {
  int to, next;
} edge[MAXN * 2];
int head[MAXN], top = 0;
inline void push(int i, int j) {
  edge[++top] = (node){j, head[i]}, head[i] = top;
}
int vis[MAXN], siz[MAXN];
void dfs_siz(int nd, int f) {
  siz[nd] = 1;
  for (int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to == f || vis[to]) continue;
    dfs_siz(to, nd), siz[nd] += siz[to];
  }
}
void dfs_find_center(int nd, int f, const int totsiz, int &cur, int &ans) {
  int maxsiz = totsiz - siz[nd];
  for (int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to == f || vis[to]) continue;
    maxsiz = max(maxsiz, siz[to]);
    dfs_find_center(to, nd, totsiz, cur, ans);
  }
  if (maxsiz < cur) cur = maxsiz, ans = nd;
}
int g[MAXK][MAXN], dp[MAXK][MAXN];
void dfs_clear(int nd, int f) {
  for (register int i = 0; i <= k; i++) dp[i][nd] = g[i][nd] = 0;
  for (register int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to == f || vis[to]) continue;
    dfs_clear(to, nd);
  }
}
void dfs_calc(int nd, int f, int pre[], int now[]) {
  if (f) (now[nd] += pre[f]) %= mod;
  for (int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to == f || vis[to]) continue;
    dfs_calc(to, nd, pre, now);
    (now[nd] += pre[to]) %= mod;
  }
}
void dfs_con(int nd, int f, int a[]) {
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= i; j++)
      a[i] = (a[i] + (long long)g[j][nd] * dp[i - j][nd]) % mod;
  for (int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to == f || vis[to]) continue;
    dfs_con(to, nd, a);
  }
}
void dfs(int nd, int a[]) {
  dfs_siz(nd, 0);
  int cur = 1e9, center;
  dfs_find_center(nd, 0, siz[nd], cur, center), nd = center;
  dfs_clear(nd, 0);
  dp[0][nd] = 1;
  for (int i = 1; i <= k; i++) dfs_calc(nd, 0, dp[i - 1], dp[i]);
  g[0][nd] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = head[nd]; j; j = edge[j].next) {
      int to = edge[j].to;
      if (vis[to]) continue;
      dfs_calc(to, nd, g[i - 1], g[i]);
    }
  dfs_con(nd, 0, a);
  vis[nd] = 1;
  for (int i = head[nd]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (vis[to]) continue;
    dfs(to, a);
  }
}
void solve_tree(int n, int a[]) {
  top = 0, memset(head, 0, sizeof head);
  N = n;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    push(u, v), push(v, u);
  }
  memset(vis, 0, sizeof vis);
  dfs(1, a);
  a[0] = n;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  solve_tree(n, a);
  solve_tree(m, b);
  C[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = (ans + (long long)C[k][i] * a[i] % mod * b[k - i]) % mod;
  cout << ans << endl;
  return 0;
}
