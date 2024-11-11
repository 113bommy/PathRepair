#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int> > mat(20, vector<int>(20, 0));
    long long res = -m;
    while (m--) {
      int x, y;
      scanf("%d %d", &x, &y);
      ;
      mat[x - 1][y - 1] = mat[y - 1][x - 1] = 1;
    }
    vector<vector<long long> > dp((1 << n), vector<long long>(n, 0));
    for (int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
    for (int i = 1; i < (1 << n); i++) {
      int tmp = -1;
      for (int j = 0; j < n; j++) {
        if (!(i & (1 << j))) continue;
        if (tmp == -1) tmp = j;
        if (mat[j][tmp]) res += dp[i][j];
        for (int k = tmp + 1; k < n; k++) {
          if (mat[j][k] && !(i & (1 << k))) dp[i | (1 << k)][k] += dp[i][j];
        }
      }
    }
    cout << res / 2 << endl;
  }
  return 0;
}
