#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n;
vector<int> g[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  cout << n - 1 << '\n';
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].push_back(i);
    g[v].push_back(i);
    cout << "2 " << u << ' ' << v << '\n';
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < (int)g[i].size(); ++j)
      cout << g[i][j - 1] << ' ' << g[i][j] << '\n';
  return 0;
}
