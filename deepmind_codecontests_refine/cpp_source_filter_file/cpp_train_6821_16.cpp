#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
vector<vector<vector<long long> > > res;
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  res.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    res[i].resize(m + 1);
    for (int j = 0; j <= m; j++) res[i][j].resize(2);
  }
  long long op, rc, a;
  for (int i = 0; i < k; i++) {
    cin >> op >> rc >> a;
    if (op == 1) {
      res[rc][0][0] = i;
      res[rc][0][1] = a;
    } else {
      res[0][rc][0] = i;
      res[0][rc][1] = a;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      res[i][j][0] = res[i][0][0];
      res[i][j][1] = res[i][0][1];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (res[i][j][0] < res[0][j][0]) {
        res[i][j][0] = res[0][j][0];
        res[i][j][1] = res[0][j][1];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << res[i][j][1] << " \n"[j == m];
    }
  }
  return 0;
}
