#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
const int inf = 0x3f3f3f3f;
int n;
int a, p[maxn], x[maxn], use[2][maxn];
int b, q[maxn], y[maxn];
vector<int> G[maxn], H[maxn];
int low[2][maxn], up[2][maxn];
int dp[maxn];
int dfs(int u, int p, vector<int> S[], int tp) {
  if (use[tp][u]) {
    low[tp][u] = up[tp][u] = use[tp][u];
    return 0;
  }
  low[tp][u] = inf;
  up[tp][u] = -1;
  for (auto v : S[u])
    if (v != p) {
      dfs(v, u, S, tp);
      low[tp][u] = min(low[tp][u], low[tp][v]);
      up[tp][u] = max(up[tp][u], up[tp][v]);
    }
  return 0;
}
struct BIT {
  int c[maxn];
  inline int lowbit(int x) { return x & -x; }
  int sum(int pos, int n) {
    int ret = 0;
    for (; pos >= 1; pos -= lowbit(pos)) ret += c[pos];
    return ret;
  }
  void insert(int pos, int val, int n) {
    for (; pos <= n; pos += lowbit(pos)) c[pos] += val;
  }
} bi[2];
int main() {
  ios::sync_with_stdio(false);
  int T(1), cas(0);
  while (T--) {
    cin >> n;
    cin >> a;
    for (int i = (2); i <= int(a); ++i) cin >> p[i];
    for (int i = (1); i <= int(n); ++i) cin >> x[i], use[0][x[i]] = i;
    ;
    cin >> b;
    for (int i = (2); i <= int(b); ++i) cin >> q[i];
    for (int i = (1); i <= int(n); ++i) cin >> y[i], use[1][y[i]] = i;
    for (int i = (2); i <= int(a); ++i) G[p[i]].push_back(i);
    for (int i = (2); i <= int(b); ++i) H[q[i]].push_back(i);
    dfs(1, 0, G, 0);
    dfs(1, 0, H, 1);
    for (int i = (1); i <= int(a); ++i) G[i].clear();
    for (int i = (1); i <= int(b); ++i) H[i].clear();
    for (int i = (2); i <= int(a); ++i) G[up[0][i]].push_back(low[0][i]);
    for (int i = (2); i <= int(b); ++i) H[up[1][i]].push_back(low[1][i]);
    for (int i = (1); i <= int(n); ++i)
      sort(G[i].begin(), G[i].end()), sort(H[i].begin(), H[i].end());
    for (int i = (1); i <= int(n); ++i) {
      int num = G[i].size();
      for (auto x : G[i]) bi[0].insert(x, 1, n);
      for (auto x : H[i]) bi[1].insert(x, 1, n);
      for (int j = (0); j <= int(G[i].size() - 1); ++j) {
        int val = G[i][j];
        dp[i] =
            max(dp[i], dp[val - 1] + bi[0].sum(i, n) - bi[0].sum(val - 1, n));
      }
      for (int j = (0); j <= int(H[i].size() - 1); ++j) {
        int val = H[i][j];
        dp[i] =
            max(dp[i], dp[val - 1] + bi[1].sum(i, n) - bi[1].sum(val - 1, n));
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}
