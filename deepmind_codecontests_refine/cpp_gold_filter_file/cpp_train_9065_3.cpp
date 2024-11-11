#include <bits/stdc++.h>
const int kei[] = {-1, 0, 1, 0};
const int kej[] = {0, 1, 0, -1};
const int N = 1005;
using namespace std;
int n, m, i, j, t;
int ans[N * N][3], top;
char T[N][N];
bool check[N][N];
bool kt(pair<int, int> u) {
  return u.first >= 0 && u.first < n && u.second >= 0 && u.second < m &&
         T[u.first][u.second] == '*';
}
int dfs(pair<int, int> u) {
  int sz = 0;
  while (1) {
    sz++;
    for (int i = 0; i < 4; i++) {
      pair<int, int> v =
          pair<int, int>(u.first + kei[i] * sz, u.second + kej[i] * sz);
      if (!kt(v)) return sz - 1;
    }
    for (int i = 0; i < 4; i++) {
      pair<int, int> v =
          pair<int, int>(u.first + kei[i] * sz, u.second + kej[i] * sz);
      check[v.first][v.second] = 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    scanf("\n");
    for (j = 0; j < m; j++) scanf("%c", &T[i][j]);
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (T[i][j] == '*') {
        if (t = dfs(pair<int, int>(i, j))) {
          check[i][j] = 1;
          ans[top][0] = i;
          ans[top][1] = j;
          ans[top][2] = t;
          top++;
        }
      }
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (T[i][j] == '*' && !check[i][j]) {
        cout << -1;
        return 0;
      }
    }
  printf("%d\n", top);
  while (top--)
    printf("%d %d %d\n", ans[top][0] + 1, ans[top][1] + 1, ans[top][2]);
}
