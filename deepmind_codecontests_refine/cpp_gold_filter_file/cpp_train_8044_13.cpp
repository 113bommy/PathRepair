#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char t[N][N], ans_t[N][N];
int n, m, ans, cur, left_room;
int dx[4][5] = {
    {0, 0, 0, 1, 2}, {0, 0, 0, -1, -2}, {1, -1, 0, 0, 0}, {1, -1, 0, 0, 0}};
int dy[4][5] = {
    {1, -1, 0, 0, 0}, {1, -1, 0, 0, 0}, {0, 0, 0, 1, 2}, {0, 0, 0, -1, -2}};
void ans_check() {
  if (ans >= cur) return;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans_t[i][j] = t[i][j];
  ans = cur;
}
bool is_val(int i, int j) {
  return i < n && j < m && min(i, j) > -1 && t[i][j] == '.';
}
bool put(int i, int j, int dir, char fill) {
  bool res = true;
  for (int d = 0; d < 5; d++) res &= is_val(i + dx[dir][d], j + dy[dir][d]);
  if (res) {
    for (int d = 0; d < 5; d++) t[i + dx[dir][d]][j + dy[dir][d]] = fill;
    cur++;
  }
  return res;
}
void pick(int i, int j, int dir) {
  for (int d = 0; d < 5; d++) t[i + dx[dir][d]][j + dy[dir][d]] = '.';
  cur--;
}
void bt(int i, int j, char fill) {
  if (i == n || (((n - i) * m) / 5) + cur <= ans) {
    ans_check();
    return;
  }
  if (j == m) {
    bt(i + 1, 0, fill);
    return;
  }
  bt(i, j + 1, fill);
  if ((((n - i) * m) / 5) + cur <= ans) return;
  for (int d = 0; d < 4; d++)
    if (put(i, j, d, fill)) {
      bt(i, j + 1, fill + 1);
      pick(i, j, d);
    }
}
void bt_init() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) t[i][j] = ans_t[i][j] = '.';
  ans = cur = 0;
  left_room = n * m;
}
int main() {
  cin >> n >> m;
  bt_init();
  bt(0, 0, 'A');
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ans_t[i][j];
    cout << endl;
  }
}
