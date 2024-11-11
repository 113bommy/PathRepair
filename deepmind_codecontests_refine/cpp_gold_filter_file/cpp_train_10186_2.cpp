#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> p(r);
  for (int i = 0; i < r; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int>> g(n, vector<int>(n, INF));
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a][b] = c;
    g[b][a] = c;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  sort(p.begin(), p.end());
  int ans = INF;
  do {
    int dist = 0;
    for (int i = 0; i < r - 1; ++i) {
      dist += g[p[i]][p[i + 1]];
    }
    ans = min(ans, dist);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
}
