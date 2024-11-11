#include <bits/stdc++.h>
using namespace std;
int n, m;
string grid[2222];
queue<int> qr, qc;
int cntAdj(int r, int c) {
  int res = 0;
  if (r < n - 1 && grid[r + 1][c] == '.') res++;
  if (c < m - 1 && grid[r][c + 1] == '.') res++;
  if (r > 0 && grid[r - 1][c] == '.') res++;
  if (c > 0 && grid[r][c - 1] == '.') res++;
  return res;
}
bool isValid(int r, int c) {
  return r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '.';
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (cntAdj(i, j) == 1) {
        qr.push(i);
        qc.push(j);
      }
  while (!qr.empty()) {
    int r = qr.front();
    int c = qc.front();
    qr.pop();
    qc.pop();
    if (grid[r][c] != '.') continue;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int rr = -1, cc = -1;
    if (r > 0 && grid[r - 1][c] == '.') {
      grid[r][c] = 'v';
      rr = r - 1;
      cc = c;
      grid[rr][cc] = '^';
    } else if (c > 0 && grid[r][c - 1] == '.') {
      grid[r][c] = '>';
      rr = r;
      cc = c - 1;
      grid[rr][cc] = '<';
    } else if (c < m - 1 && grid[r][c + 1] == '.') {
      grid[r][c] = '<';
      rr = r;
      cc = c + 1;
      grid[rr][cc] = '>';
    } else if (r < n - 1 && grid[r + 1][c] == '.') {
      grid[r][c] = '^';
      rr = r + 1;
      cc = c;
      grid[rr][cc] = 'v';
    }
    for (int dd = 0; dd < 4; dd++) {
      int nr = rr + dr[dd];
      int nc = cc + dc[dd];
      if (isValid(nr, nc) && cntAdj(nr, nc) == 1) {
        qr.push(nr);
        qc.push(nc);
      }
    }
    if (rr == -1) {
      cout << "Not unique";
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] == '.') {
        cout << "Not unique";
        return 0;
      }
  for (int i = 0; i < n; i++) cout << grid[i] << endl;
}
