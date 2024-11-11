#include <bits/stdc++.h>
using namespace std;
int movi[] = {0, -1, 0, 1};
int movj[] = {1, 0, -1, 0};
int n, m;
string board[51];
int mem[51][51];
int corn[2550][4];
pair<pair<int, int>, pair<int, int> > ret;
void dfs(int i, int j, int cnt) {
  mem[i][j] = cnt;
  corn[cnt][0] = max(corn[cnt][0], j);
  corn[cnt][1] = min(corn[cnt][1], i);
  corn[cnt][2] = min(corn[cnt][2], j);
  corn[cnt][3] = max(corn[cnt][3], i);
  for (int k = 0; k < 4; k++) {
    int ni = i + movi[k], nj = j + movj[k];
    if (0 <= ni && ni < n && 0 <= nj && nj < m &&
        board[i][j] == board[ni][nj] && mem[ni][nj] == 0)
      dfs(ni, nj, cnt);
  }
}
int movei[4][2] = {
    {1, 3},
    {1, 1},
    {3, 1},
    {3, 3},
};
int movej[4][2] = {
    {0, 0},
    {2, 0},
    {2, 2},
    {0, 2},
};
int main() {
  int steps;
  cin >> n >> steps;
  for (int i = 0; i < n; i++) cin >> board[i];
  memset(mem, 0, sizeof(mem));
  m = board[0].size();
  int cnt = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mem[i][j] == 0 && board[i][j] != '0') {
        corn[cnt][0] = -100;
        corn[cnt][1] = 100;
        corn[cnt][2] = 100;
        corn[cnt][3] = -100;
        dfs(i, j, cnt++);
      }
  int curr = 1, dp = 0, cp = 0;
  int i = corn[curr][movei[dp][cp]];
  int j = corn[curr][movej[dp][cp]];
  for (int s = 0; s < steps; s++) {
    int ni = i + movi[dp], nj = j + movj[dp];
    if (0 <= ni && ni < n && 0 <= nj && nj < m && mem[ni][nj] != 0) {
      curr = mem[ni][nj];
    } else {
      if (cp == 1) dp = (dp + 3) % 4;
      cp = 1 - cp;
    }
    i = corn[curr][movei[dp][cp]];
    j = corn[curr][movej[dp][cp]];
  }
  cout << board[i][j] << endl;
  return 0;
}
