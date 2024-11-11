#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2000 + 10;
constexpr int M = 1 << 16;
struct Edge {
  int val, l;
  Edge(int _u, int _v, int _l) {
    val = (1 << _u) ^ (1 << _v);
    l = _l;
  }
  bool operator<(Edge rhs) { return l < rhs.l; }
};
long long n, m, u, v, w, sum, dp[M][2], d[N];
vector<int> node[N];
vector<Edge> ve;
bool mark[N];
void dfs(int v) {
  mark[v] = true;
  for (auto i : node[v])
    if (!mark[i]) dfs(i);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    sum += w;
    ve.push_back(Edge(u, v, w));
    node[u].push_back(v);
    node[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    if (!mark[i] && d[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  memset(dp, 63, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++)
    for (int mask = 0; mask < 1 << n; mask++)
      dp[mask][i & 1] =
          min(dp[mask][1 - (i & 1)],
              dp[mask ^ ve[i - 1].val][1 - (i & 1)] + ve[i - 1].l);
  int msk = 0;
  for (int i = 0; i < n; i++)
    if (d[i] & 1) msk ^= (1 << i);
  cout << dp[msk][m & 1] + sum << '\n';
  return 0;
}
