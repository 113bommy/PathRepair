#include <bits/stdc++.h>
using namespace std;
int alldp[41][41][41][41];
int endatdp[41][41][41][41];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  char arr[n][m];
  int left[n][m], up[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> arr[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i > 0) {
        up[i][j] = (arr[i][j] == '1' ? i : up[i - 1][j]);
      } else
        up[i][j] = (arr[i][j] == '1' ? i : -1);
      if (j > 0) {
        left[i][j] = (arr[i][j] == '1' ? j : left[i][j - 1]);
      } else
        left[i][j] = (arr[i][j] == '1' ? j : -1);
    }
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      for (int i1 = i; i1 < n; ++i1)
        for (int j1 = j; j1 < m; ++j1) {
          int &ans = endatdp[i][j][i1][j1] = 0;
          if (arr[i1][j1] != '1') {
            int left0 = max(left[i1][j1] + 1, j), up0 = max(up[i1][j1] + 1, i);
            ans += j1 - left0 + 1 + i1 - up0 + 1 - 1;
            if (up0 < i1 and left0 < j1)
              ans += endatdp[up0][left0][i1 - 1][j1 - 1];
          }
        }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int i1 = i; i1 < n; ++i1)
        for (int j1 = j; j1 < m; ++j1) {
          int &ans = alldp[i][j][i1][j1] = endatdp[i][j][i1][j1];
          if (i1 > i) ans += alldp[i][j][i1 - 1][j1];
          if (j1 > j) ans += alldp[i][j][i1][j1 - 1];
          if (i1 > i and j1 > j) ans -= alldp[i][j][i1 - 1][j1 - 1];
        }
  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    cout << alldp[a][b][c][d] << "\n";
  }
  return 0;
}
