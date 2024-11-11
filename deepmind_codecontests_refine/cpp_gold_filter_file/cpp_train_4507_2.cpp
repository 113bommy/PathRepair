#include <bits/stdc++.h>
using namespace std;
char cur[9][9];
char ret[9][9];
int r, c;
int ans = -1;
int px[][5] = {
    {0, 1, 2, 2, 2}, {0, 0, 0, 1, 2}, {0, 1, 1, 1, 2}, {0, 1, 1, 1, 2}};
int py[][5] = {
    {0, 0, -1, 0, 1}, {0, 1, 2, 1, 1}, {0, 0, 1, 2, 0}, {0, -2, -1, 0, 0}};
bool check(int x, int y, int k) {
  for (int i = 0; i < (int)(5); i++) {
    int xx = x + px[k][i];
    int yy = y + py[k][i];
    if (xx < 0 || yy < 0) return false;
    if (xx >= r || yy >= c) return false;
    if (cur[xx][yy] != '.') return false;
  }
  return true;
}
void putBlock(int x, int y, int k, char c) {
  for (int i = 0; i < (int)(5); i++) {
    int xx = x + px[k][i];
    int yy = y + py[k][i];
    cur[xx][yy] = c;
  }
}
void solve(int x, int y, int acc, int rm) {
  if (rm / 5 + acc <= ans) return;
  if (y == c) y = 0, ++x;
  if (x == r) {
    if (acc > ans) {
      ans = acc;
      memcpy(ret, cur, sizeof(ret));
    }
    return;
  }
  char block = 'A' + acc;
  for (int k = 0; k < (int)(4); k++) {
    if (check(x, y, k)) {
      putBlock(x, y, k, block);
      solve(x, y + 1, acc + 1, rm - 5);
      putBlock(x, y, k, '.');
    }
  }
  solve(x, y + 1, acc, rm - (cur[x][y] == '.'));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> r >> c;
  memset(cur, '.', sizeof(cur));
  solve(0, 0, 0, r * c);
  cout << ans << endl;
  for (int i = 0; i < (int)(r); i++) {
    for (int j = 0; j < (int)(c); j++) cout << ret[i][j];
    cout << endl;
  }
  return 0;
}
