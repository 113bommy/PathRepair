#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7, oo = 1e9 + 7, OO = 1e18 + 7;
int n, m, ans, mv[5][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 0}, {1, 0}};
char ch[20][20], tmp[20][20];
void rot() {
  for (int i = 0; i < 5; i++) {
    pair<int, int> tmp = {mv[i][0], mv[i][1]};
    mv[i][0] = tmp.second;
    mv[i][1] = -tmp.first;
  }
}
void bt(int r, int c, int cnt) {
  if (r == n) {
    if (cnt <= ans) return;
    ans = cnt;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ch[i][j] = tmp[i][j];
    return;
  }
  if ((m * n - (r - 1) * m - c + 1) / 5 + cnt <= ans) return;
  if (tmp[r][c] != '.') {
    if (c == m - 1)
      bt(r + 1, 2, cnt);
    else
      bt(r, c + 1, cnt);
    return;
  }
  for (int k = 0; k < 4; k++) {
    bool is = true;
    for (int i = 0; i < 5; i++)
      is = is & (tmp[r + mv[i][0]][c + mv[i][1]] == '.');
    if (is) {
      for (int i = 0; i < 5; i++)
        tmp[r + mv[i][0]][c + mv[i][1]] = char(cnt + 'A');
      if (c == m - 1)
        bt(r + 1, 2, cnt + 1);
      else
        bt(r, c + 1, cnt + 1);
      for (int i = 0; i < 5; i++) tmp[r + mv[i][0]][c + mv[i][1]] = '.';
    }
    rot();
  }
  if (c == m - 1)
    bt(r + 1, 2, cnt);
  else
    bt(r, c + 1, cnt);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ch[i][j] = tmp[i][j] = '.';
  if (m > 2 && n > 2) bt(2, 2, 0);
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << ch[i][j];
    cout << '\n';
  }
  return 0;
}
