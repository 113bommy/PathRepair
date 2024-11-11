#include <bits/stdc++.h>
using namespace std;
const int N = 513;
int lc[N], rc[N], val[N], f[N][2][3], n, T, sz[N];
void dfs(int x) {
  if (val[x] != -1) {
    sz[x] = 0;
    for (int y = 0; y < 2; ++y)
      for (int z = 0; z < 3; ++z) f[x][y][z] = val[x];
    return;
  }
  dfs(lc[x]);
  dfs(rc[x]);
  if (sz[rc[x]] & 1) swap(lc[x], rc[x]);
  sz[x] = sz[lc[x]] + sz[rc[x]] + 1;
  if (sz[x] == 1) {
    for (int y = 0; y < 2; ++y)
      for (int z = 0; z < 3; ++z)
        if (y ^ (z == 2))
          f[x][y][z] = min(val[lc[x]], val[rc[x]]);
        else
          f[x][y][z] = max(val[lc[x]], val[rc[x]]);
    return;
  }
  if (sz[x] & 1)
    f[x][0][0] = max(f[lc[x]][0][sz[lc[x]] & 1], f[rc[x]][0][sz[lc[x]] & 1]),
    f[x][1][0] = min(f[lc[x]][1][sz[lc[x]] & 1], f[rc[x]][1][sz[lc[x]] & 1]);
  else
    f[x][0][0] = max(min(f[lc[x]][0][0], f[rc[x]][1][0]),
                     min(f[lc[x]][1][1], f[rc[x]][0][1])),
    f[x][1][0] = min(max(f[lc[x]][1][0], f[rc[x]][0][1]),
                     max(f[lc[x]][0][1], f[rc[x]][1][1]));
  for (int z = 1; z <= 2; ++z)
    if (sz[x] & 1) {
      f[x][0][z] = f[x][1][0];
      f[x][1][z] = f[x][0][0];
      if (sz[lc[x]] & 1)
        f[x][0][z] = max(f[x][0][z],
                         max(min(f[lc[x]][0][0],
                                 f[rc[x]][1][sz[lc[x]] == 1 && z == 1 ? 2 : 1]),
                             min(f[lc[x]][1][sz[rc[x]] == 1 && z == 1 ? 2 : 1],
                                 f[rc[x]][0][0]))),
        f[x][1][z] = min(f[x][1][z],
                         min(max(f[lc[x]][1][0],
                                 f[rc[x]][0][sz[lc[x]] == 1 && z == 1 ? 2 : 1]),
                             max(f[lc[x]][0][sz[rc[x]] == 1 && z == 1 ? 2 : 1],
                                 f[rc[x]][1][0])));
      else {
        if (sz[rc[x]])
          f[x][0][z] = max(
              f[x][0][z],
              min(f[lc[x]][1][0], f[rc[x]][0][!sz[lc[x]] && z == 1 ? 2 : 1])),
          f[x][1][z] = min(
              f[x][1][z],
              max(f[lc[x]][0][0], f[rc[x]][1][!sz[lc[x]] && z == 1 ? 2 : 1]));
        if (sz[lc[x]])
          f[x][0][z] = max(
              f[x][0][z],
              min(f[lc[x]][0][!sz[rc[x]] && z == 1 ? 2 : 1], f[rc[x]][1][0])),
          f[x][1][z] = min(
              f[x][1][z],
              max(f[lc[x]][1][!sz[rc[x]] && z == 1 ? 2 : 1], f[rc[x]][0][0]));
      }
    } else
      f[x][0][z] =
          max(f[lc[x]][0][!sz[rc[x]] && z == 1 ? 2 : 1], f[rc[x]][0][0]),
      f[x][1][z] =
          min(f[lc[x]][1][!sz[rc[x]] && z == 1 ? 2 : 1], f[rc[x]][1][0]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> T; T-- > 0;) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> val[i];
      if (val[i] == -1)
        cin >> lc[i] >> rc[i];
      else
        lc[i] = rc[i] = 0;
    }
    dfs(0);
    cout << f[0][0][0] << '\n';
  }
  return 0;
}
