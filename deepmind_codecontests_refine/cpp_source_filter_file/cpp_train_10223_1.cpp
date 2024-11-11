#include <bits/stdc++.h>
using namespace std;
int deg[100010], par[100010];
map<int, int> M[100010];
bool taken[100010];
std::vector<int> v;
int findpar(int u) { return par[u] = (par[u] == u) ? u : findpar(par[u]); }
int main() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    deg[x]++, deg[y]++;
    M[x][y] = M[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (n - deg[i] > (n + 1) / 2) {
      taken[i] = 1;
      v.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    par[v[i]] = v[0];
  }
  for (int i = 1; i <= n; i++) {
    if (taken[i]) continue;
    par[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (taken[i]) continue;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (M[i].find(j) == M[i].end()) {
        int v = findpar(j), u = findpar(i);
        par[v] = u;
      }
    }
  }
  set<int> ans;
  for (int i = 1; i <= n; i++) ans.insert(par[i]);
  cout << ans.size() - 1 << endl;
  return 0;
}
