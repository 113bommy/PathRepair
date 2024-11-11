#include <bits/stdc++.h>
using namespace std;
int n, m, a[60][60], len;
string s;
struct node {
  int x, y;
} mp[60][60][9];
void solve(int x, int y, int k) {
  int xx = x, yy = y;
  if (k == 1 || k == 2) {
    for (int i = yy + 1; i <= len; i++)
      if (a[xx][i] == a[xx][i - 1])
        yy = i;
      else
        break;
    if (k == 1)
      for (int i = xx - 1; i >= 1; i--)
        if (a[i][yy] == a[i + 1][yy])
          xx = i;
        else
          break;
    else
      for (int i = xx + 1; i <= m; i++)
        if (a[i][yy] == a[i - 1][yy])
          xx = i;
        else
          break;
  } else if (k == 3 || k == 4) {
    for (int i = xx + 1; i <= m; i++)
      if (a[i][yy] == a[i - 1][yy])
        xx = i;
      else
        break;
    if (k == 3)
      for (int i = yy + 1; i <= len; i++)
        if (a[xx][i] == a[xx][i - 1])
          yy = i;
        else
          break;
    else
      for (int i = yy - 1; i >= 1; i--)
        if (a[xx][i] == a[xx][i + 1])
          yy = i;
        else
          break;
  } else if (k == 5 || k == 6) {
    for (int i = yy - 1; i >= 1; i--)
      if (a[xx][i] == a[xx][i + 1])
        yy = i;
      else
        break;
    if (k == 5)
      for (int i = xx + 1; i <= m; i++)
        if (a[i][yy] == a[i - 1][yy])
          xx = i;
        else
          break;
    else
      for (int i = xx - 1; i >= 1; i--)
        if (a[i][yy] == a[i + 1][yy])
          xx = i;
        else
          break;
  } else if (k == 7 || k == 8) {
    for (int i = xx - 1; i >= 1; i--)
      if (a[i][yy] == a[i + 1][yy])
        xx = i;
      else
        break;
    if (k == 7)
      for (int i = yy - 1; i >= 1; i--)
        if (a[xx][i] == a[xx][i + 1])
          yy = i;
        else
          break;
    else
      for (int i = yy + 1; i <= len; i++)
        if (a[xx][i] == a[xx][i - 1])
          yy = i;
        else
          break;
  }
  if (k == 1 || k == 2) {
    if (yy + 1 > len || a[xx][yy + 1] == 0) {
      mp[x][y][k].x = -1;
      mp[x][y][k].y = k + 1;
    } else {
      mp[x][y][k].x = xx;
      mp[x][y][k].y = yy + 1;
    }
  } else if (k == 3 || k == 4) {
    if (xx + 1 > m || a[xx + 1][yy] == 0) {
      mp[x][y][k].x = -1;
      mp[x][y][k].y = k + 1;
    } else {
      mp[x][y][k].x = xx + 1;
      mp[x][y][k].y = yy;
    }
  } else if (k == 5 || k == 6) {
    if (yy - 1 == 0 || a[xx][yy - 1] == 0) {
      mp[x][y][k].x = -1;
      mp[x][y][k].y = k + 1;
    } else {
      mp[x][y][k].x = xx;
      mp[x][y][k].y = yy - 1;
    }
  } else if (k == 7 || k == 8) {
    if (xx - 1 == 0 || a[xx - 1][yy] == 0) {
      mp[x][y][k].x = -1;
      mp[x][y][k].y = k + 1;
      if (mp[x][y][k].y == 9) mp[x][y][k].y = 1;
    } else {
      mp[x][y][k].x = xx - 1;
      mp[x][y][k].y = yy;
    }
  }
}
int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    len = s.length();
    for (int j = 0; j < len; j++) a[i][j + 1] = s[j] - '0';
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= len; j++)
      if (a[i][j])
        for (int k = 1; k <= 8; k++) solve(i, j, k);
  int k = 1, x = 1, y = 1, t;
  for (int i = 1; i <= n; i++) {
    if (mp[x][y][k].x > 0) {
      t = x;
      x = mp[x][y][k].x;
      y = mp[t][y][k].y;
    } else
      k = mp[x][y][k].y;
  }
  cout << a[x][y];
}
