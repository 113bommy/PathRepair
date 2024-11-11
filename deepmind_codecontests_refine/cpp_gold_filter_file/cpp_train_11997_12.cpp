#include <bits/stdc++.h>
using namespace std;
int m, n;
int step;
bool visit[151][151][4][2];
char a[151][151];
int f[151][151][4];
int fx, fy, dp, cp;
void movedp();
void movecp();
void movenext();
int main() {
  cin >> m >> step;
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) a[i][j + 1] = s[j];
    n = s.length();
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 0; k < 4; k++) {
        visit[i][j][k][0] = visit[i][j][k][1] = false;
        f[i][j][k] = 0;
      }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '0') continue;
      if (i == 1)
        f[i][j][0] = 0;
      else if (a[i - 1][j] == a[i][j])
        f[i][j][0] = f[i - 1][j][0] + 1;
      else if (a[i - 1][j] != a[i][j])
        f[i][j][0] = 0;
      if (j == 1)
        f[i][j][3] = 0;
      else if (a[i][j - 1] == a[i][j])
        f[i][j][3] = f[i][j - 1][3] + 1;
      else if (a[i][j - 1] != a[i][j])
        f[i][j][3] = 0;
    }
  for (int i = m; i >= 1; i--)
    for (int j = n; j >= 1; j--) {
      if (a[i][j] == '0') continue;
      if (i == m)
        f[i][j][2] = 0;
      else if (a[i + 1][j] == a[i][j])
        f[i][j][2] = f[i + 1][j][2] + 1;
      else if (a[i + 1][j] != a[i][j])
        f[i][j][2] = 0;
      if (j == n)
        f[i][j][1] = 0;
      else if (a[i][j + 1] == a[i][j])
        f[i][j][1] = f[i][j + 1][1] + 1;
      else if (a[i][j + 1] != a[i][j])
        f[i][j][1] = 0;
    }
  fx = fy = 1;
  dp = 1;
  cp = 0;
  visit[fx][fy][dp][cp] = true;
  for (int nstep = 1; nstep <= step; nstep++) {
    movedp();
    movecp();
    movenext();
  }
  cout << a[fx][fy] << endl;
  return 0;
}
void movedp() {
  int t = f[fx][fy][dp];
  if (dp == 0) {
    fx = fx - t;
  } else if (dp == 1) {
    fy = fy + t;
  } else if (dp == 2) {
    fx = fx + t;
  } else if (dp == 3) {
    fy = fy - t;
  }
}
int adjust() {
  if (dp == 0) {
    if (cp == 0)
      return 3;
    else
      return 1;
  } else if (dp == 1) {
    if (cp == 0)
      return 0;
    else
      return 2;
  } else if (dp == 2) {
    if (cp == 0)
      return 1;
    else
      return 3;
  } else if (dp == 3) {
    if (cp == 0)
      return 2;
    else
      return 0;
  }
}
void movecp() {
  int tt = adjust();
  int t = f[fx][fy][tt];
  if (tt == 0) {
    fx = fx - t;
  } else if (tt == 1) {
    fy = fy + t;
  } else if (tt == 2) {
    fx = fx + t;
  } else if (tt == 3) {
    fy = fy - t;
  }
}
void movenext() {
  int t = 1;
  int x = fx;
  int y = fy;
  if (dp == 0) {
    x = x - t;
  } else if (dp == 1) {
    y = y + t;
  } else if (dp == 2) {
    x = x + t;
  } else if (dp == 3) {
    y = y - t;
  }
  if (x < 1 || y < 1 || x > m || y > n || (a[x][y] == '0')) {
    if (cp == 0)
      cp = 1;
    else {
      cp = 0;
      dp = (dp + 1) % 4;
    }
  } else {
    fx = x;
    fy = y;
  }
}
