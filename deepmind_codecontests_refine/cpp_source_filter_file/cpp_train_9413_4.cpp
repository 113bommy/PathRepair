#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 7;
vector<pair<int, int> > ad[N];
int n, m, g1, g2, s1, s2;
int dis[N][N];
pair<int, int> mnd[N], mxd[N];
long long dp[N][N][N];
bool pos[N][4];
int res;
void chkpos(int a, int b) {
  for (int i = 1; i <= n; i++)
    if (i != a && i != b) {
      for (int j = 1; j <= n; j++)
        if (i != j) {
          pair<int, int> p = {dis[i][j], i};
          if (p < mnd[a]) pos[i][1] = 1;
          if (p > mxd[b]) pos[i][3] = 1;
          if (mnd[a] < p && p < mxd[b]) pos[i][2] = 1;
        }
    }
}
void solve(int a, int b) {
  if (mnd[a] > mxd[b]) return;
  memset(dp, 0, sizeof dp);
  memset(pos, 0, sizeof pos);
  chkpos(a, b);
  dp[0][0][0] = 1;
  int pnt = 1;
  for (int i = 1; i <= n; i++) {
    if (i == a || i == b) continue;
    for (int g = 0; g < g2; g++)
      for (int s = 0; s <= s2; s++) {
        if (pos[i][1] && g) dp[pnt][g][s] = dp[pnt - 1][g - 1][s];
        if (pos[i][2] && s) dp[pnt][g][s] += dp[pnt - 1][g][s - 1];
        if (pos[i][3]) dp[pnt][g][s] += dp[pnt - 1][g][s];
      }
    pnt++;
  }
  for (int g = g1 - 1; g < g2; g++)
    for (int s = s1; s <= s2; s++) res += dp[pnt - 1][g][s];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = 1e9;
    }
    dis[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    ad[v].push_back({v, w});
    ad[u].push_back({u, w});
    dis[v][u] = dis[u][v] = w;
  }
  cin >> g1 >> g2 >> s1 >> s2;
  for (int lim = 1; lim <= n; lim++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][lim] + dis[lim][j]);
  for (int i = 1; i <= n; i++) {
    mnd[i] = {1e9, i};
    mxd[i] = {0, i};
    for (int j = 1; j <= n; j++)
      if (i != j) {
        mnd[i].first = min(mnd[i].first, dis[i][j]);
        mxd[i].first = max(mxd[i].first, dis[i][j]);
      }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) solve(i, j);
  cout << res;
  return 0;
}
