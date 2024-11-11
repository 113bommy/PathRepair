#include <bits/stdc++.h>
using namespace std;
bitset<2007> used[2007];
int a, b, m, d;
int x[2007];
int y[2007];
int col[2007][2007];
int sec[2007][2007];
vector<int> G[2007];
void dfs(int v, int teraz, int chce) {
  int u = sec[v][teraz];
  used[v][teraz] = used[u][teraz] = 0;
  col[v][u] = col[u][v] = 0;
  if (used[u][chce]) dfs(u, chce, teraz);
  col[v][u] = col[u][v] = chce;
  used[v][chce] = used[u][chce] = 1;
  sec[v][chce] = u;
  sec[u][chce] = v;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> a >> b >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x[i] >> y[i];
    y[i] += a;
    G[x[i]].push_back(y[i]);
    G[y[i]].push_back(x[i]);
    d = max(d, (int)G[x[i]].size());
    d = max(d, (int)G[y[i]].size());
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= d; ++j) {
      if (!used[x[i]][j] && !used[y[i]][j]) {
        col[x[i]][y[i]] = col[y[i]][x[i]] = j;
        used[x[i]][j] = used[y[i]][j] = 1;
        sec[x[i]][j] = y[i];
        sec[y[i]][j] = x[i];
        break;
      }
    }
    if (!col[x[i]][y[i]]) {
      int cx = -1, cy = -1;
      for (int j = 1; j <= d; ++j) {
        if (used[x[i]][j] && !used[y[i]][j])
          cx = j;
        else if (!used[x[i]][j] && used[y[i]][j])
          cy = j;
      }
      dfs(x[i], cx, cy);
      col[x[i]][y[i]] = col[y[i]][x[i]] = cx;
      used[x[i]][cx] = used[y[i]][cx] = 1;
      sec[x[i]][cx] = y[i];
      sec[y[i]][cx] = x[i];
    }
  }
  cout << d << '\n';
  for (int i = 1; i <= m; ++i) {
    cout << col[x[i]][y[i]] << " ";
  }
}
