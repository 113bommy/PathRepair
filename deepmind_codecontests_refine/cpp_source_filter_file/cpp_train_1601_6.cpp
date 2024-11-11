#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e3 + 5;
int d[305][305];
int n, k;
int res = 0;
void combine(int i, int j, int u, int v, int w) {
  if (d[i][u] + d[v][j] + w < d[i][j]) {
    res -= d[i][j];
    d[i][j] = d[j][i] = d[i][u] + d[v][j] + w;
    res += d[i][j];
  }
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> d[i][j];
      if (i < j) res += d[i][j];
    }
  }
  cin >> k;
  while (k--) {
    int u, v, w;
    cin >> u >> v >> w;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        combine(i, j, u, v, w);
        combine(i, j, v, u, w);
      }
    }
    cout << res << ' ';
  }
}
