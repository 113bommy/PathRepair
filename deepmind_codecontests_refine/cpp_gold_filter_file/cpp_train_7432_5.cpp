#include <bits/stdc++.h>
using namespace std;
int piece[110][4] = {}, p = 0;
void add_piece(int x1, int y1, int x2, int y2) {
  piece[p][0] = x1;
  piece[p][1] = y1;
  piece[p][2] = x2;
  piece[p++][3] = y2;
}
bool check(int k, int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    if (piece[k][1] == y1 && piece[k][3] == y2 && piece[k][0] < x1 &&
        x1 < piece[k][2]) {
      add_piece(piece[k][0], piece[k][1], x1, piece[k][3]);
      piece[k][0] = x1;
      return true;
    }
  } else if (y1 == y2) {
    if (piece[k][0] == x1 && piece[k][2] == x2 && piece[k][1] < y1 &&
        y1 < piece[k][3]) {
      add_piece(piece[k][0], piece[k][1], piece[k][2], y1);
      piece[k][1] = y1;
      return true;
    }
  }
  return false;
}
int q[110][4];
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  add_piece(0, 0, w, h);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) cin >> q[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < p; k++)
        if (check(k, q[j][0], q[j][1], q[j][2], q[j][3])) break;
    }
  }
  int ans[110] = {}, s = 0;
  for (int i = 0; i < p; i++)
    ans[s++] = (piece[i][2] - piece[i][0]) * (piece[i][3] - piece[i][1]);
  sort(ans, ans + s);
  for (int i = 0; i < s; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
