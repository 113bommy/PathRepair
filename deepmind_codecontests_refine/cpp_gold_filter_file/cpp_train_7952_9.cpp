#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool vis[N];
int main() {
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    vis[u] = vis[v] = 1;
  }
  int root = -1;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      root = i;
      break;
    }
  cout << n - 1 << endl;
  for (int i = 1; i <= n; ++i)
    if (i != root) cout << root << " " << i << endl;
}
