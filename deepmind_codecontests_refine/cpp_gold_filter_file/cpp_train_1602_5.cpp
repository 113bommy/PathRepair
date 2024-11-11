#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4e2 + 4;
constexpr int MAXK = 1e5 + 5;
constexpr int MOD = 1e9 + 7;
constexpr long long INF = 9187201950435737471;
constexpr int LOG = 11;
int n, q, a[MAXN], dp[MAXN][MAXK];
long long s, cnt, t;
vector<int> G[MAXN][2];
vector<long long> vc;
bool mark[MAXN], Cycle;
int add(int a, int b) {
  int c = a + b;
  if (c >= MOD) {
    c -= MOD;
  }
  return c;
}
void dfs(int u) {
  mark[u] = true;
  for (auto v : G[u][0]) {
    dfs(v);
  }
  s += cnt * a[u];
  cnt++;
}
void dfs1(int u, long long sum) {
  sum += a[u];
  vc.push_back(sum);
  for (auto v : G[u][0]) {
    dfs1(v, sum);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    int b, c;
    cin >> b >> c;
    G[b][0].push_back(c);
    G[c][1].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (G[i][1].empty() && !G[i][0].empty()) {
      cnt = 0;
      dfs(i);
      dfs1(i, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!G[i][1].empty() && !G[i][0].empty() && !mark[i]) {
      Cycle = true;
    }
  }
  t -= s;
  if (t < 0 || Cycle) {
    return cout << 0, 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      vc.push_back(a[i]);
    }
  }
  for (int i = 1; i <= vc.size(); i++) {
    for (int j = 0; j <= t; j++) {
      if (j < 0 || j >= MAXK) {
        return cout << s, 0;
      }
      dp[i][j] = dp[i - 1][j];
      if (j >= vc[i - 1]) {
        dp[i][j] = add(dp[i][j], dp[i][j - vc[i - 1]]);
      }
    }
  }
  cout << dp[vc.size()][t];
  return 0;
}
