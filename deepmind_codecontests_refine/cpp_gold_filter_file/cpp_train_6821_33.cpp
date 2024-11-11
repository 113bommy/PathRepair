#include <bits/stdc++.h>
using namespace std;
int op[101000][3];
int mp[5010][5010];
bool rvis[5010], cvis[5010];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < 3; j++) cin >> op[i][j];
  for (int i = k - 1; ~i; i--) {
    if (op[i][0] == 1) {
      int r = op[i][1], cor = op[i][2];
      if (rvis[r]) continue;
      rvis[r] = 1;
      for (int i = 1; i <= m; i++)
        if (!mp[r][i]) mp[r][i] = cor;
    } else {
      int c = op[i][1], cor = op[i][2];
      if (cvis[c]) continue;
      cvis[c] = 1;
      for (int i = 1; i <= n; i++)
        if (!mp[i][c]) mp[i][c] = cor;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", mp[i][j]);
    }
    puts("");
  }
}
