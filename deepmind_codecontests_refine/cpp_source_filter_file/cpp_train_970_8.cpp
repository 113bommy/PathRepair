#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9 + 7;
int siz[N], par[N];
int _find(int x) {
  if (x == par[x]) return x;
  return par[x] = _find(par[x]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) siz[i] = 1, par[i] = i;
  while (m--) {
    int u, v;
    cin >> u >> v;
    int p = _find(u);
    int q = _find(v);
    if (p == q) continue;
    par[p] = q;
    siz[q] += siz[p];
  }
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    int p = _find(u);
    int q = _find(v);
    if (p == q) continue;
    siz[q] = 0;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, siz[_find(i)]);
  cout << res << "\n";
}
