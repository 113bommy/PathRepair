#include <bits/stdc++.h>
using namespace std;
const int M = 500 + 10;
int a[M][M];
int vis[M][M];
int rowleft[M];
int rowright[M];
int colup[M];
int coldown[M];
int n;
char ans[3000000];
int cnt = 0;
void dfs(int row, int col) {
  if (a[row][col] == 0) {
    a[row][col] = 1;
    ans[cnt++] = '1';
    if (rowleft[row] == 0) {
      rowleft[row] = col;
    }
    rowleft[row] = min(rowleft[row], col);
    rowright[row] = max(rowright[row], col);
    if (colup[col] == 0) {
      colup[col] = row;
    }
    colup[col] = min(colup[col], row);
    coldown[col] = max(coldown[col], row);
  }
  vis[row][col] = 1;
  int nxtrow = 0;
  int nxtcol = 0;
  nxtrow = row;
  nxtcol = col - 1;
  if (nxtcol >= 1 && rowleft[row] != 0 && rowleft[row] <= nxtcol &&
      vis[nxtrow][nxtcol] == 0) {
    ans[cnt++] = 'L';
    dfs(nxtrow, nxtcol);
    ans[cnt++] = 'R';
  }
  nxtrow = row;
  nxtcol = col + 1;
  if (nxtcol <= n && rowright[row] != 0 && rowright[row] >= nxtcol &&
      vis[nxtrow][nxtcol] == 0) {
    ans[cnt++] = 'R';
    dfs(nxtrow, nxtcol);
    ans[cnt++] = 'L';
  }
  nxtrow = row - 1;
  nxtcol = col;
  if (nxtrow >= 1 && colup[col] != 0 && colup[col] <= nxtrow &&
      vis[nxtrow][nxtcol] == 0) {
    ans[cnt++] = 'U';
    dfs(nxtrow, nxtcol);
    ans[cnt++] = 'D';
  }
  nxtrow = row + 1;
  nxtcol = col;
  if (nxtrow <= n && coldown[col] != 0 && coldown[col] >= nxtrow &&
      vis[nxtrow][nxtcol] == 0) {
    ans[cnt++] = 'D';
    dfs(nxtrow, nxtcol);
    ans[cnt++] = 'U';
  }
  ans[cnt++] = '2';
  a[row][col] = 0;
  if (rowleft[row] == col) {
    rowleft[row] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[row][j] == 1) {
        rowleft[row] = j;
        break;
      }
    }
  }
  if (rowright[row] == col) {
    rowright[row] = 0;
    for (int j = n; j >= 1; j--) {
      if (a[row][j] == 1) {
        rowright[row] = j;
        break;
      }
    }
  }
  if (colup[col] == row) {
    colup[col] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j][col] == 1) {
        colup[col] = j;
        break;
      }
    }
  }
  if (coldown[col] == row) {
    coldown[col] = 0;
    for (int j = n; j >= 1; j--) {
      if (a[j][col] == 1) {
        coldown[col] = j;
        break;
      }
    }
  }
  return;
}
int main() {
  time_t t_start, t_end;
  t_start = clock();
  cin >> n;
  int x0, y0;
  cin >> x0 >> y0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      if (a[row][col] == 1) {
        if (rowleft[row] == 0) {
          rowleft[row] = col;
        }
        rowleft[row] = min(rowleft[row], col);
        rowright[row] = max(rowright[row], col);
      }
    }
  }
  for (int col = 1; col <= n; col++) {
    for (int row = 1; row <= n; row++) {
      if (a[row][col] == 1) {
        if (colup[col] == 0) {
          colup[col] = row;
        }
        colup[col] = min(colup[col], row);
        coldown[col] = max(coldown[col], row);
      }
    }
  }
  dfs(x0, y0);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 1) {
        ok = false;
      }
    }
  }
  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < cnt; i++) {
      cout << ans[i];
    }
    cout << endl;
  }
  t_end = clock();
  return 0;
}
