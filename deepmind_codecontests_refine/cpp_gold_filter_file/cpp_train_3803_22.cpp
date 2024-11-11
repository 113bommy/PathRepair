#include <bits/stdc++.h>
using namespace std;
int n, m, q;
struct node {
  int x, y;
};
int a[110][110];
node idx[110][110];
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) idx[i][j].x = i, idx[i][j].y = j;
  for (int i = 1; i <= q; i++) {
    int t, u, v, e;
    cin >> t;
    if (t == 1) {
      cin >> u;
      idx[u][m + 1] = idx[u][1];
      for (int j = 1; j <= m; j++) idx[u][j] = idx[u][j + 1];
    }
    if (t == 2) {
      cin >> v;
      idx[n + 1][v] = idx[1][v];
      for (int j = 1; j <= n; j++) idx[j][v] = idx[j + 1][v];
    }
    if (t == 3) {
      cin >> u >> v >> e;
      a[idx[u][v].x][idx[u][v].y] = e;
    }
  }
  for (int i = 1; i <= n; i++, cout << endl)
    for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
  return 0;
}
