#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<ii>;
using graph = vector<vi>;
using matrix = graph;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll INFL = 1e18 + 4;
const ll mod = 1e9 + 7;
graph g;
int h[MAXN];
vi leafs;
bool seen[MAXN];
void dfs(int u) {
  seen[u] = 1;
  bool yes = 1;
  for (auto v : g[u])
    if (!seen[v]) {
      yes = 0;
      h[v] = h[u] + 1;
      dfs(v);
    }
  if (yes) leafs.push_back(h[u]);
}
int main() {
  int n;
  scanf("%d", &n);
  g.assign(n + 1, vi());
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 1;
  seen[1] = 1;
  for (auto v : g[1]) {
    leafs.clear();
    dfs(v);
    sort(leafs.begin(), leafs.end());
    for (int i = 1; i < (int)leafs.size(); ++i) {
      leafs[i] = max(leafs[i], leafs[i - 1] + 1);
    }
    ans = max(ans, leafs.back());
  }
  printf("%d\n", ans + 1);
}
