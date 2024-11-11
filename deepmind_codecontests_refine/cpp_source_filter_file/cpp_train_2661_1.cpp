#include <bits/stdc++.h>
using namespace std;
int n, m, T, ans, DP[(int)(5e3 + 5)][(int)(5e3 + 5)],
    road[(int)(5e3 + 5)][(int)(5e3 + 5)];
vector<pair<int, int> > streets[(int)(5e3 + 5)];
void read() {
  cin >> n >> m >> T;
  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    streets[u].push_back(pair<int, int>(v, t));
  }
}
void initialize() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) DP[i][j] = (int)(1e9);
  DP[1][1] = 0;
}
void solve() {
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n; j++) {
      if (DP[i][j] == (int)(1e9)) continue;
      for (int k = 0; k < streets[j].size(); k++) {
        int v = streets[j][k].first;
        int t = streets[j][k].second;
        if (DP[i][j] + t <= T && DP[i + 1][v] > DP[i][j] + t) {
          DP[i + 1][v] = DP[i][j] + t;
          road[i + 1][v] = j;
        }
        if (v == n && DP[i + 1][v] <= T) ans = max(ans, i + 1);
      }
    }
  cout << ans << '\n';
}
void print() {
  if (ans) {
    stack<int> path;
    while (ans) {
      path.push(n);
      n = road[ans--][n];
    }
    cout << path.top(), path.pop();
    while (path.size()) cout << " " << path.top(), path.pop();
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  read();
  initialize();
  solve();
  print();
  return 0;
}
