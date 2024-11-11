#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int par[N], siz[N];
int find(int u) {
  if (par[u] == -1) return u;
  par[u] = find(par[u]);
  return par[u];
}
void uni(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (siz[u] > siz[v]) swap(u, v);
  par[u] = v, siz[v] += siz[u];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int u = 1; u <= n; u++) par[u] = -1, siz[u] = 1;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v, uni(u, v);
    }
    m == n - 1 && siz[find(1)] == n ? cout << "YES\n" : cout << "NO\n";
  }
}
