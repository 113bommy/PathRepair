#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int parent[N];
vector<int> conn[N];
int r[N];
int par(int u) {
  if (parent[u] == u) return u;
  return parent[u] = par(parent[u]);
}
void merge(int u, int v) {
  int pu = par(u);
  int pv = par(v);
  if (pu == pv) return;
  if (r[pu] > r[pv])
    parent[pv] = pu;
  else
    parent[pu] = pv;
  if (r[pu] == r[pv]) r[pv]++;
}
int mp[N];
int dp[2][N];
int W[N];
int B[N];
pair<int, int> second[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, w;
  cin >> n >> m >> w;
  for (int i = 1; i <= n; i++) cin >> W[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i <= n; i++) parent[i] = i, r[i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  memset(mp, -1, sizeof mp);
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int p = par(i);
    if (mp[p] == -1) {
      mp[p] = c++;
    }
    conn[mp[p]].push_back(i);
    second[mp[p]] = {second[mp[p]].first + W[i], second[mp[p]].second + B[i]};
  }
  dp[1][0] = 0;
  for (int i = 0; i < c; i++) {
    int ind = i & 1;
    int prev = 1 - ind;
    for (int j = 0; j <= w; j++) dp[ind][j] = dp[prev][j];
    for (int j = 0; j <= w; j++) {
      if (j + second[i].first <= w)
        dp[ind][j + second[i].first] =
            max(dp[ind][j + second[i].first], dp[prev][j] + second[i].second);
      else
        break;
    }
    for (auto u : conn[i]) {
      for (int j = 0; j <= w; j++) {
        if (j + W[u] <= w)
          dp[ind][j + W[u]] = max(dp[ind][j + W[u]], dp[prev][j] + B[u]);
        else
          break;
      }
    }
  }
  int ind = (c - 1) & 1;
  int ans = 0;
  for (int i = 0; i <= w; i++) ans = max(ans, dp[ind][i]);
  cout << ans << endl;
}
