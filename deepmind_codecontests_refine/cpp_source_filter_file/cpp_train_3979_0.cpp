#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const long long INF = 1e16;
const int MOD = 998244353;
long long b[MAXN], w[MAXN], size[MAXN];
pair<long long, long long> dp[MAXN][MAXN], tmp[MAXN];
int n, m, T;
vector<int> e[MAXN];
void dfs(int u, int fa) {
  dp[u][0] = make_pair(0, b[u]);
  size[u] = 1;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs(v, u);
    for (int j = 0; j <= min((long long)m, size[u] + size[v]); ++j)
      tmp[j] = make_pair(0, -INF);
    for (int j = 0; j <= min((long long)m, size[u]); ++j)
      for (int k = 0; k <= min((long long)(m - j), size[v]); ++k) {
        tmp[k + j] =
            max(tmp[k + j], make_pair(dp[v][k].first + dp[u][j].first,
                                      dp[v][k].second + dp[u][j].second));
        tmp[k + j + 1] = max(
            tmp[k + j + 1],
            make_pair(dp[v][k].first + dp[u][j].first + (dp[v][k].second > 0),
                      dp[u][j].second));
      }
    size[u] += size[v];
    for (int j = 0; j <= min((long long)m, size[u]); ++j) dp[u][j] = tmp[j];
  }
}
int main() {
  scanf("%d", &T);
  while (T) {
    --T;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      size[i] = 0, tmp[i] = make_pair(0, 0), e[i].clear();
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) dp[i][j] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      b[i] -= w[i];
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v), e[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][m - 1].first + (dp[1][m - 1].second > 0) << endl;
  }
  return 0;
}
