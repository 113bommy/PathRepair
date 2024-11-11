#include <bits/stdc++.h>
using namespace std;
char a[1006][1006];
bool was[1005][1005];
int num[1005][1004];
bool alone(int i, int j) {
  if (a[i][j] != '.') return 0;
  for (int ii = -1; ii < 2; ii++)
    for (int jj = -1; jj < 2; jj++)
      if ((ii == 0 || jj == 0) && (ii + jj != 0) && a[ii + i][jj + j] == '.')
        return 0;
  return 1;
}
int cnt = 0;
int cur = 1;
vector<int> ne[1000 * 1000];
int dfs(int i, int j) {
  if (was[i][j] || a[i][j] != '.') return num[i][j];
  was[i][j] = 1;
  a[i][j] = '#';
  num[i][j] = cur;
  cnt++;
  for (int ii = -1; ii < 2; ii++)
    for (int jj = -1; jj < 2; jj++)
      if ((ii == 0 || jj == 0) && (ii + jj != 0)) {
        if (alone(ii + i, jj + j)) {
          a[ii + i][jj + j] = '#';
          num[ii + i][jj + j] = cur;
          cnt++;
        }
      }
  int la_cur = cur;
  if (cnt > 1) {
    cnt = 0;
    cur++;
  }
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
  return la_cur;
}
int ans[1000 * 1000];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++) a[i][j] = '#';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ws >> a[i + 1][j + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (alone(i, j)) {
        cout << -1;
        return 0;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) was[i + 1][j + 1] = 0, num[i + 1][j + 1] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) dfs(i + 1, j + 1);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++) {
      if (num[i][j] != 0) {
        for (int ii = -1; ii < 2; ii++)
          for (int jj = -1; jj < 2; jj++) {
            if (ii + jj != 0 && (ii == 0 || jj == 0)) {
              ne[num[i][j]].push_back(num[i + ii][j + jj]);
            }
          }
      }
    }
  for (int i = 0; i < cur; i++) ans[i] = -1;
  for (int i = 1; i < cur; i++) {
    vector<bool> k;
    k.assign(11, 0);
    for (int j = 0; j < (int)ne[i].size(); j++) {
      if (ans[ne[i][j]] != -1) k[ans[ne[i][j]]] = 1;
    }
    int ind = 0;
    while (k[ind]) ind++;
    if (ind > 9) return 1;
    ans[i] = ind;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (num[i][j] == 0)
        cout << '#';
      else
        cout << ans[num[i][j]];
    }
    cout << '\n';
  }
  return 0;
}
