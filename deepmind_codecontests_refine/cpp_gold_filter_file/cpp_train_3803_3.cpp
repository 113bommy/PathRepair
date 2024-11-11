#include <bits/stdc++.h>
using namespace std;
int mp[105][105];
struct op {
  int op, a, b, x;
} o[10004];
int main() {
  memset(mp, 0, sizeof(mp));
  ios::sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  int op, a, b, x;
  for (int i = 0; i < q; i++) {
    cin >> o[i].op;
    if (o[i].op != 3)
      cin >> o[i].a;
    else
      cin >> o[i].a >> o[i].b >> o[i].x;
  }
  while (q--) {
    if (o[q].op == 1) {
      int x = o[q].a - 1;
      for (int i = m; i > 0; i--) mp[x][i] = mp[x][i - 1];
      mp[x][0] = mp[x][m];
    } else if (o[q].op == 2) {
      int y = o[q].a - 1;
      for (int i = n; i > 0; i--) mp[i][y] = mp[i - 1][y];
      mp[0][y] = mp[n][y];
    } else
      mp[o[q].a - 1][o[q].b - 1] = o[q].x;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d%c", mp[i][j], j == m - 1 ? '\n' : ' ');
    }
  }
}
