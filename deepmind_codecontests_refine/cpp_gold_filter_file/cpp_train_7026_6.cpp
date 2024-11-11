#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[4000];
set<pair<int, int>> edges;
void here_we_go_again() {
  int i, j, n, m, a, b, k, ans = 1e9;
  cin >> n >> m;
  int h[n];
  bool isConnected[n][n];
  memset(isConnected, false, sizeof isConnected);
  memset(h, 0, sizeof h);
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    isConnected[a][b] = true;
    isConnected[b][a] = true;
    h[a]++, h[b]++;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (isConnected[j][i] or isConnected[i][j]) {
        for (k = j + 1; k < n; k++) {
          if (isConnected[i][k] and isConnected[k][j])
            ans = min(ans, h[i] + h[j] + h[k]);
        }
      }
    }
  }
  if (ans == 1e9)
    cout << "-1"
         << "\n";
  else
    cout << ans - 6 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) here_we_go_again();
  return 0;
}
