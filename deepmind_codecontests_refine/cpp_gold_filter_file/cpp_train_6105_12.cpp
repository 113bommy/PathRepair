#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long MAXN = 500001;
int n, m;
vector<vector<pair<int, int> > > g;
int mx[101];
int used[101][101][27];
bool dfs(int v1, int v2, int k) {
  if (used[v1][v2][k]) {
    return used[v1][v2][k] - 1;
  }
  bool fl = false;
  for (int i = 0; i < g[v1].size(); i++) {
    int to = g[v1][i].first;
    int w = g[v1][i].second;
    if (w >= k) {
      fl |= !dfs(v2, to, w);
    }
  }
  used[v1][v2][k] = fl + 1;
  return fl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int v, u;
    char c;
    cin >> v >> u >> c;
    v--, u--;
    g[v].push_back({u, (int)(c - 'a' + 1)});
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(i, j, 0)) {
        cout << "A";
      } else {
        cout << "B";
      }
    }
    cout << endl;
  }
  return 0;
}
