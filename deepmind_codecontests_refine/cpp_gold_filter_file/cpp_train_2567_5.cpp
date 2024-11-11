#include <bits/stdc++.h>
using namespace std;
const int N = 312345;
int n, x, y;
vector<int> g[N];
long long sz[N];
long long val;
bool ok;
void dfs1(int u, int p) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (u == x) ok = 0;
    if (v != p) {
      dfs1(v, u);
      sz[u] += sz[v];
    }
  }
  if (u == y) ok = 1;
  if (u != y and p == x and ok) {
    val = sz[u] - sz[y];
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> x >> y;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs1(x, 0);
  long long ans = 1LL * n * (n - 1) - sz[y] * (n - sz[y]) + val * sz[y];
  cout << ans << endl;
  return 0;
}
