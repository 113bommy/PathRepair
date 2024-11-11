#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
const int INF = 0x7FFFFFFF;
const double eps = 1e-10;
const double pi = acos(-1.0);
const int fx[4][5][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
                         {{0, 0}, {1, 0}, {2, 0}, {1, -1}, {1, -2}},
                         {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {2, 1}},
                         {{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}}};
int n, m, ret;
int a[MAXN][MAXN], ans[MAXN][MAXN];
void dfs(int t, int lasti, int lastj) {
  if (t > ret) {
    ret = t;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i][j] = a[i][j];
  }
  bool flag;
  for (int i = max(lasti - 3, 0); i < n; i++)
    for (int j = max(lastj - 3, 0); j < m; j++)
      if (a[i][j] == 0) {
        flag = true;
        for (int k = 0; k < 4; k++) {
          flag = true;
          for (int x = 0; x < 5; x++) {
            int nx = i + fx[k][x][0], ny = j + fx[k][x][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] != 0) {
              flag = false;
              break;
            }
          }
          if (flag) {
            for (int x = 0; x < 5; x++) {
              int nx = i + fx[k][x][0], ny = j + fx[k][x][1];
              a[nx][ny] = t + 1;
            }
            dfs(t + 1, i, j);
            for (int x = 0; x < 5; x++) {
              int nx = i + fx[k][x][0], ny = j + fx[k][x][1];
              a[nx][ny] = 0;
            }
          }
        }
        if (flag) return;
      }
}
int main() {
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  ret = 0;
  dfs(0, 0, 0);
  cout << ret << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (ans[i][j] != 0)
        cout << (char)('A' + ans[i][j] - 1);
      else
        cout << '.';
    cout << endl;
  }
  return 0;
}
