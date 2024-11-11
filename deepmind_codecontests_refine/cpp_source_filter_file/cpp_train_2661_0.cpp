#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, i, j, a, b, t, fx[5005], p;
vector<pair<int, int> > v[5005];
pair<int, int> dp[5005][5005];
vector<int> res;
void dfs(int x, int tim, int val) {
  fx[x] = 1;
  if (tim > t) {
    fx[x] = 0;
    return;
  }
  for (int i = 0; i < v[x].size(); i++) {
    int to = v[x][i].first;
    if (dp[to][val + (fx[to] ^ 1)].first > tim + v[x][i].second) {
      dp[to][val + (fx[to] ^ 1)] = {tim + v[x][i].second, x};
      dfs(to, tim + v[x][i].second, val + (fx[to] ^ 1));
    }
  }
  fx[x] = 0;
  return;
}
int main() {
  cin >> n >> m >> t;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> k;
    v[a].push_back({b, k});
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      dp[i][j].first = 1000000000;
    }
  }
  dp[1][1].first = 0;
  dfs(1, 0, 1);
  for (i = n; i >= 1; i--) {
    if (dp[n][i].first <= t) {
      cout << i << endl;
      break;
    }
  }
  while (i != 0) {
    res.push_back(n);
    n = dp[n][i].second;
    i--;
  }
  for (i = res.size() - 1; i >= 0; i--) {
    cout << res[i] << " ";
  }
}
