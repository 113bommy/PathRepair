#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long int d[n + 1][n + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> d[i][j];
  int k;
  cin >> k;
  int u, v;
  long long int w, ans;
  while (k--) {
    cin >> u >> v >> w;
    ans = 0;
    if (d[u][v] > w) {
      d[u][v] = w;
      d[v][u] = w;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          d[i][j] = min(d[i][j], d[i][u] + d[u][v] + d[v][j]);
          d[i][j] = min(d[i][j], d[i][v] + d[u][v] + d[u][j]);
          ans += d[i][j];
        }
      }
    } else {
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) ans += d[i][j];
    }
    cout << ans / 2 << " ";
  }
}
