#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int N = 100 + 1, mod = 1e9 + 7;
int D[N], H[N][N];
vector<int> G[N];
void add(int& a, int b) { a = (a + b) % mod; }
void bfs(int v, int h) {
  int q[N], l = 0, r = 0;
  q[r++] = v;
  D[v] = 1;
  H[h][1]++;
  while (l < r) {
    int u = q[l++];
    for (auto to : G[u]) {
      if (D[to] != -1) continue;
      q[r++] = to;
      D[to] = D[u] + 1;
      H[h][D[to]]++;
    }
  }
}
int cnt(int v, int k) {
  memset(D, -1, sizeof(D));
  ;
  memset(H, 0, sizeof(H));
  ;
  D[v] = 0;
  int m = G[v].size();
  if (m < k) return 0;
  for (int h = 0; h < m; ++h) {
    auto to = G[v][h];
    bfs(to, h);
  }
  int c = 0;
  for (int d = 1; d < N; ++d) {
    int dp[m + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    ;
    dp[0][0] = 1;
    for (int h = 1; h <= m; ++h) {
      dp[h][0] = 1;
      for (int j = 1; j <= k; ++j) {
        add(dp[h][j], dp[h - 1][j]);
        add(dp[h][j], ((LL)dp[h - 1][j - 1] * H[h - 1][d]) % mod);
      }
    }
    add(c, dp[m][k]);
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  ;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) add(res, cnt(i, k));
    cout << res << '\n';
  }
}
