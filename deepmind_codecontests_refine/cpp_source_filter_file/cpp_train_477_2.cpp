#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 5, lg = 20;
int level[Nmax], x, y, i, n, tip, type[Nmax], t[lg + 4][Nmax], dad[Nmax],
    go0[Nmax], go1[Nmax], q;
int get_lca(int x, int y) {
  if (level[x] < level[y]) swap(x, y);
  int i, dif = level[x] - level[y];
  for (i = 0; i <= lg && x != -1; ++i)
    if (dif & (1 << i)) x = t[i][x];
  if (x == y) return x;
  for (i = lg; i >= 0 && x != -1 && y != -1; --i)
    if (t[i][x] != t[i][y]) x = t[i][x], y = t[i][y];
  if (x == -1) return -1;
  return dad[x];
}
bool solve1(int x, int y) {
  int lca = get_lca(x, y);
  if (lca != x || lca == -1) return 0;
  return go0[y] >= level[y] - level[x];
}
bool solve2(int x, int y) {
  int lca = get_lca(x, y);
  if (lca == x || lca == -1) return 0;
  return go1[y] >= level[y] - level[lca] && go0[x] >= level[x] - level[lca];
}
void precompute() {
  int i, j;
  for (i = 1; i <= n; ++i) {
    t[0][i] = dad[i];
    if (dad[i] == -1)
      level[i] = 0;
    else
      level[i] = level[dad[i]] + 1;
  }
  for (i = 1; i <= lg; ++i)
    for (j = 1; j <= n; ++j)
      if (t[i - 1][j] == -1)
        t[i][j] = -1;
      else
        t[i][j] = t[i - 1][t[i - 1][j]];
  for (i = 1; i <= n; ++i)
    if (type[i] == 0)
      go0[i] = (dad[i] != -1 ? go0[dad[i]] + 1 : 1);
    else
      go1[i] = (dad[i] != -1 ? go1[dad[i]] + 1 : 1);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> dad[i] >> type[i];
  precompute();
  cin >> q;
  while (q--) {
    cin >> tip >> x >> y;
    if (x == y) {
      cout << "NO\n";
      continue;
    }
    if (tip == 1)
      cout << (solve1(x, y) ? "YES" : "NO") << '\n';
    else
      cout << (solve2(x, y) ? "YES" : "NO") << '\n';
  }
  return 0;
}
