#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[200005][13];
pair<int, int> p[100005][13];
int col[200005][12], bl[200005], br[200005];
bool ok(int x, int y, int bl, int br) {
  return (!(x < bl || x > br || y <= 0 || y > m));
}
void dfs(int i, int j, int bl, int br) {
  col[i][j] = 1;
  int cx = i, cy = j;
  if (a[i][j] == '>') {
    cy++;
  } else if (a[i][j] == '<') {
    cy--;
  } else {
    cx--;
  }
  if (!ok(cx, cy, bl, br)) {
    p[i][j] = {cx, cy};
    col[i][j] = 2;
    return;
  }
  if (col[cx][cy] == 1) {
    p[i][j] = {-1, -1};
    col[i][j] = 2;
    return;
  }
  if (!col[cx][cy]) dfs(cx, cy, bl, br);
  p[i][j] = p[cx][cy];
  col[i][j] = 2;
}
void recalc(int num) {
  for (int i = bl[num]; i <= br[num]; i++) {
    for (int j = 1; j <= m; j++) {
      col[i][j] = 0;
    }
  }
  for (int i = bl[num]; i <= br[num]; i++) {
    for (int j = 1; j <= m; j++) {
      if (!col[i][j]) {
        dfs(i, j, bl[num], br[num]);
      }
    }
  }
}
int main() {
  int q;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  int len = 200;
  for (int i = 1; i <= n; i++) {
    br[i / len] = i;
    if (bl[i / len] == 0) {
      bl[i / len] = i;
    }
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i <= len; i++) {
    if (br[i] != 0) {
      recalc(i);
    }
  }
  while (q--) {
    char type;
    cin >> type;
    if (type == 'A') {
      int x, y;
      cin >> x >> y;
      while (1) {
        pair<int, int> curr = p[x][y];
        x = curr.first;
        y = curr.second;
        if (x == -1 || x <= 0 || y <= 0 || x > n || y > m) {
          break;
        }
      }
      cout << x << " " << y << "\n";
    } else {
      int x, y;
      char val;
      cin >> x >> y >> val;
      a[x][y] = val;
      recalc(x / len);
    }
  }
  return 0;
}
