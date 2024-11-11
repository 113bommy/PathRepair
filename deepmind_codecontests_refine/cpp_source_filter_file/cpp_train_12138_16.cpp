#include <bits/stdc++.h>
using namespace std;
int n, m;
int sx, sy, tx, ty;
char ch;
bool s1[1010];
bool s2[1010];
bool t1[1010];
bool t2[1010];
char mat[1010][1010];
bool check(int j) {
  int x = sx;
  int y = tx;
  if (x > y) swap(x, y);
  for (int k = x; k <= y; k++) {
    if (mat[k][j] != '.') return 0;
  }
  return 1;
}
bool check2(int i) {
  int x = sy;
  int y = ty;
  if (x > y) swap(x, y);
  for (int k = x; k <= y; k++) {
    if (mat[i][k] != '.') return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      while (ch != '.' && ch != '*' && ch != 'S' && ch != 'T') {
        cin >> ch;
      }
      if (ch == 'S') {
        sx = i;
        sy = j;
        ch == '.';
      }
      if (ch == 'T') {
        tx = i;
        ty = j;
        ch == '.';
      }
      mat[i][j] = ch;
    }
  }
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  memset(t1, 0, sizeof(t1));
  memset(t2, 0, sizeof(t2));
  s1[sy] = 1;
  for (int j = sy + 1; j < m; j++) {
    if (mat[sx][j] == '.') {
      s1[j] = 1;
    } else
      break;
  }
  for (int j = sy - 1; j >= 0; j--) {
    if (mat[sx][j] == '.') {
      s1[j] = 1;
    } else
      break;
  }
  s2[sx] = 1;
  for (int i = sx + 1; i < n; i++) {
    if (mat[i][sy] == '.') {
      s2[i] = 1;
    } else
      break;
  }
  for (int i = sx - 1; i >= 0; i--) {
    if (mat[i][sy] == '.') {
      s2[i] = 1;
    } else
      break;
  }
  t1[ty] = 1;
  for (int j = ty + 1; j < m; j++) {
    if (mat[tx][j] == '.') {
      t1[j] = 1;
    } else
      break;
  }
  for (int j = ty - 1; j >= 0; j--) {
    if (mat[tx][j] == '.') {
      t1[j] = 1;
    } else
      break;
  }
  t2[tx] = 1;
  for (int i = tx + 1; i < n; i++) {
    if (mat[i][ty] == '.') {
      t2[i] = 1;
    } else
      break;
  }
  for (int i = tx - 1; i >= 0; i--) {
    if (mat[i][ty] == '.') {
      t2[i] = 1;
    } else
      break;
  }
  bool flag = 0;
  for (int j = 0; j < m; j++) {
    if (s1[j] && t1[j] && check(j)) {
      flag = 1;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s2[i] && t2[i] && check2(i)) {
      flag = 1;
      break;
    }
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
