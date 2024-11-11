#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> g[N];
int idGroup[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) idGroup[i] = 1;
  for (int v : g[1]) idGroup[v] = 2;
  int foo = 0;
  for (int i = 1; i <= n; ++i)
    if (idGroup[i] == 2) foo = i;
  if (!foo) return cout << -1, 0;
  for (int v : g[foo])
    if (idGroup[v] == 2) idGroup[v] = 3;
  int bar = 0, magic = 0;
  foo = 0;
  for (int i = 1; i <= n; ++i) {
    if (idGroup[i] == 1)
      foo++;
    else if (idGroup[i] == 2)
      bar++;
    else
      magic++;
  }
  if (!magic) return cout << -1, 0;
  if (1ll * foo * bar + 1ll * foo * magic + 1ll * bar * magic != 1ll * m)
    return cout << -1, 0;
  for (int i = 1; i <= n; ++i) {
    for (int v : g[i])
      if (idGroup[v] == idGroup[i]) return cout << -1, 0;
  }
  for (int i = 1; i <= n; ++i) cout << idGroup[i] << " ";
  return 0;
}
