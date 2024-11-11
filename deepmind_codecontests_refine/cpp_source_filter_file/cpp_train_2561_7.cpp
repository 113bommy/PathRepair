#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n, q, f[20][100005], dep[100005];
vector<int> son[100005];
void dfs(int x, int d) {
  dep[x] = d;
  for (int i = 0; i < son[x].size(); i++) {
    dfs(son[x][i], d + 1);
  }
}
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int k = 0; k < 18; k++) {
    if ((dep[y] - dep[x]) & (1 << k)) y = f[k][y];
  }
  if (x == y) return x;
  for (int k = 18; k >= 0; k--) {
    if (f[k][x] != f[k][y]) {
      x = f[k][x];
      y = f[k][y];
    }
  }
  return f[0][x];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  f[0][0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> f[0][i];
    f[0][i]--;
    son[f[0][i]].push_back(i);
  }
  dfs(0, 1);
  for (int k = 1; k < 18; k++) {
    for (int i = 0; i < n; i++) {
      f[k][i] = f[k - 1][f[k - 1][i]];
    }
  }
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    if (dep[a] > dep[b]) swap(a, b);
    if (dep[a] > dep[c]) swap(a, c);
    if (dep[b] > dep[c]) swap(b, c);
    int d = lca(b, c), e = lca(a, d);
    if (dep[d] >= dep[a])
      cout << max(dep[d] + dep[a] - 2 * dep[e],
                  max(dep[b] - dep[d], dep[c] - dep[d])) +
                  1
           << endl;
    else {
      if (dep[lca(a, b)] > dep[d]) {
        int g = lca(a, b);
        cout << max(dep[c] + dep[g] - 2 * dep[d],
                    max(dep[a] - dep[g], dep[b] - dep[g])) +
                    1
             << endl;
      } else {
        int g = lca(a, c);
        cout << max(dep[b] + dep[g] - 2 * dep[d],
                    max(dep[a] - dep[g], dep[c] - dep[g])) +
                    1
             << endl;
      }
    }
  }
  return 0;
}
