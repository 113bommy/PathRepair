#include <bits/stdc++.h>
using namespace std;
const int e = 100 + 2;
const int e1 = 1e6;
const long long mod = 1e9 + 7;
int dist[e][e];
int v[e1];
int mark[e1], trace[e1], dp[e1];
void track(int x) {
  if (!x) return;
  track(trace[x]);
  cout << v[x] << " ";
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    s = ' ' + s;
    for (int j = 1; j <= n; j++) {
      if (s[j] == '1') {
        dist[i][j] = 1;
      } else {
        dist[i][j] = 1000;
      }
    }
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i];
    dp[i] = 1e6 + 7;
  }
  dp[1] = 1;
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= n; i++) {
        if (dist[i][k] != 1000 && dist[k][j] != 1000) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[i] == j) continue;
      if (mark[j] == 0) continue;
      if (dist[j][v[i]] == 1000 || dist[j][v[i]] < i - mark[j]) continue;
      if (dp[i] > dp[mark[j]] + 1) {
        dp[i] = dp[mark[j]] + 1;
        trace[i] = mark[j];
      }
    }
    mark[v[i]] = i;
  }
  cout << dp[m] << "\n";
  track(m);
}
