#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[1005][1005];
int vis[1005][1005];
int w, h, x, y;
int min(int a, int b) { return a < b ? a : b; }
bool check(int a, int b) {
  memset(vis, 0, sizeof(vis));
  int i, j, k, cx = x, cy = y;
  int have_move = 0, move;
  for (i = cx; i < cx + a; i++) {
    for (j = cy; j < cy + b; j++) vis[i][j] = 0;
  }
  if (arr[cx + a][cy] == 'X')
    have_move = 1, move = 0;
  else if (arr[cx][cy + b] == 'X')
    have_move = 1, move = 1;
  while (have_move) {
    if (move == 1)
      cy++;
    else
      cy++;
    for (i = cx; i < cx + a; i++) {
      for (j = cy; j < cy + b; j++) vis[i][j] = 0;
    }
    if (arr[cx + a][cy] == 'X')
      have_move = 1, move = 0;
    else if (arr[cx][cy + b] == 'X')
      have_move = 1, move = 1;
    else
      have_move = 0;
  }
  bool bb = true;
  for (i = 0; i < n && bb; i++) {
    for (j = 0; j < m && bb; j++) {
      if (arr[i][j] == 'X' && !vis[i][j]) bb = false;
      if (arr[i][j] != 'X' && vis[i][j]) bb = false;
    }
  }
  return bb;
}
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> arr[i];
  bool bb = true;
  for (i = 0; i < n && bb; i++) {
    for (j = 0; j < m && bb; j++) {
      if (arr[i][j] == 'X') {
        x = i;
        y = j;
        bb = false;
      }
    }
  }
  int p = 1, q = 1;
  for (i = y + 1; i < m; i++) {
    if (arr[x][i] == 'X')
      q++;
    else
      break;
  }
  for (i = x + 1; i < n; i++) {
    if (arr[i][y] == 'X')
      p++;
    else
      break;
  }
  int a, b;
  a = p;
  b = 1;
  int cx = x, cy = y;
  int have_move;
  for (i = x; i < x + p; i++) {
    vis[i][y] = 1;
  }
  if (arr[x][y + 1] == 'X')
    have_move = 1;
  else
    have_move = 0;
  int move = 1;
  while (have_move) {
    if (move == 1) {
      for (i = cx; i < cx + a; i++) vis[i][cy + b] = 1;
      cy++;
    } else if (move == 0) {
      for (i = cy; i < cy + b; i++) vis[cx + a][i] = 1;
      cx++;
    }
    if (arr[cx + a][cy] == 'X') {
      for (i = cy + b; i < m; i++) {
        if (arr[cx][i] == 'X') {
          b++;
          for (j = cx; j < cx + a; j++) vis[j][i] = 1;
        } else
          break;
      }
      move = 0;
    } else if (arr[cx][cy + b] == 'X')
      move = 1;
    else
      have_move = 0;
  }
  int ansa = 100000000, ansb = 100000000;
  if (check(a, b)) ansa = a * b;
  a = 1;
  b = q;
  cx = x;
  cy = y;
  memset(vis, 0, sizeof(vis));
  for (i = y; i < y + q; i++) {
    vis[x][i] = 1;
  }
  if (arr[x + 1][y] == 'X')
    have_move = 1;
  else
    have_move = 0;
  move = 0;
  while (have_move) {
    if (move == 1) {
      for (i = cx; i < cx + a; i++) vis[i][cy + b] = 1;
      cy++;
    } else if (move == 0) {
      for (i = cy; i < cy + b; i++) vis[cx + a][i] = 1;
      cx++;
    }
    if (arr[cx][cy + b] == 'X') {
      for (i = cx + a; i < n; i++) {
        if (arr[i][cy] == 'X') {
          a++;
          for (j = cy; j < cy + b; j++) vis[i][j] = 1;
        } else
          break;
      }
      move = 1;
    } else if (arr[cx + a][cy] == 'X')
      move = 0;
    else
      have_move = 0;
  }
  bb = true;
  if (check(a, b)) ansb = a * b;
  int ans = min(ansa, ansb);
  if (ans != 100000000)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
