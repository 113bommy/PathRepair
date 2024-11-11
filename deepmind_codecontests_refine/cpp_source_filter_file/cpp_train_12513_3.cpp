#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 1e6 + 10;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int g[n];
  for (int i = 0; i < n; ++i) cin >> g[i];
  sort(g, g + (sizeof(g) / sizeof(*g)));
  int d[n];
  fill(d, d + (sizeof(d) / sizeof(*d)), 0);
  for (int i = m; i < n; ++i) d[i] = g[i - m] + d[i - m];
  long long sm = 0;
  for (int i = 0; i < n; ++i) {
    sm += g[i] + d[i];
    cout << sm << " ";
  }
  return 0;
}
