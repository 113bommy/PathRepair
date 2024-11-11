#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e2 + 69;
vector<vector<pair<int, char> > > v;
int dp[nax][nax][26];
int fun(int i, int j, char baap) {
  if (dp[i][j][baap - 'a'] != -1) return dp[i][j][baap - 'a'];
  int res = 0;
  for (auto to : v[i]) {
    if (to.second >= baap) {
      res |= !fun(j, to.first, to.second);
    }
  }
  return dp[i][j][baap] = res;
}
int main() {
  int n, m, x, y;
  cin >> n >> m;
  v.resize(n + 1);
  char val;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> val;
    v[x].push_back({y, val});
  }
  memset(dp, -1, sizeof(dp));
  int res[n][n];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cout << (fun(i, j, 'a') ? 'A' : 'B');
    cout << endl;
  }
  return 0;
}
