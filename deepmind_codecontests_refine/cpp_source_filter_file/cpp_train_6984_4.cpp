#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char a[maxn][maxn];
int ok[maxn][maxn];
int n, m;
inline bool isin(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
bool center(int x, int y) {
  for (int i = (-1); i < (2); i++) {
    if (!isin(x + i, y) || a[x + i][y] != '*') {
      return false;
    }
    if (!isin(x, y + i) || a[x][y + i] != '*') {
      return false;
    }
  }
  return true;
}
int star(int x, int y) {
  for (int i = (-1); i < (2); i++) {
    ok[x + i][y] = ok[x][y + i] = 1;
  }
  for (int i = 2;; i++) {
    if (!isin(x + i, y) || a[x + i][y] != '*') {
      return i - 1;
    }
    if (!isin(x, y + i) || a[x][y + i] != '*') {
      return i - 1;
    }
    if (!isin(x - i, y) || a[x - i][y] != '*') {
      return i - 1;
    }
    if (!isin(x, y - i) || a[x][y - i] != '*') {
      return i - 1;
    }
    ok[x + i][y] = ok[x][y + i] = ok[x - i][y] = ok[x][y - i] = 1;
  }
}
int ans[10005][3], cnt;
int main() {
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (a[i][j] == '.') ok[i][j] = 1;
    }
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
      if (center(i, j)) {
        ans[cnt][0] = i + 1;
        ans[cnt][1] = j + 1;
        ans[cnt++][2] = star(i, j);
      }
    }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (!ok[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  cout << cnt << '\n';
  for (int i = 0; i < (cnt); ++i) {
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  }
}
