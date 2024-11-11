#include <bits/stdc++.h>
const int INF = 1e6;
using namespace std;
const long long int maxa = 10000000000000ll;
const int maxn = 2e5 + 5;
const int N = 1e6;
pair<int, int> temp[105][105];
int ans[105][105];
int main() {
  int n, m, q, i, j, r, c, val, t;
  cin >> n >> m >> q;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) temp[i][j] = make_pair(i, j);
  }
  for (i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> r;
      r--;
      pair<int, int> p = temp[r][0];
      for (j = 1; j < m; j++) temp[r][i - 1] = temp[r][i];
      temp[r][m - 1] = p;
    } else if (t == 2) {
      cin >> c;
      c--;
      pair<int, int> p = temp[0][c];
      for (j = 1; j < n; j++) temp[j - 1][c] = temp[j][c];
      temp[n - 1][c] = p;
    } else {
      cin >> r >> c >> val;
      r--;
      c--;
      pair<int, int> p = temp[r][c];
      ans[p.first][p.second] = val;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
