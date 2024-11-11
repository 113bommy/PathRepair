#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
vector<vector<int> > g;
int64_t adding[N], substracting[N], vi[N];
void dfs(int u, int pr) {
  for (int v : g[u]) {
    if (v != pr) {
      dfs(v, u);
      adding[u] = max(adding[u], adding[v]);
      substracting[u] = max(substracting[u], substracting[v]);
    }
  }
  int64_t total = vi[u] + adding[u] - substracting[u];
  if (total > 0) substracting[u] += total;
  if (total < 0) adding[u] += -total;
}
int main() {
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) cin >> vi[i];
  dfs(1, -1);
  cout << adding[1] + substracting[1] << "\n";
}
