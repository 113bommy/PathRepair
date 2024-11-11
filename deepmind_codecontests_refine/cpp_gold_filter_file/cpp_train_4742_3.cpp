#include <bits/stdc++.h>
using namespace std;
int n;
string st;
struct node {
  char c;
  bool vis;
};
node b[102][102];
int mr[] = {1, -1, 0, 0}, mc[] = {0, 0, 1, -1};
void bfs(int r, int c, int row, int col) {
  queue<pair<int, int> > l;
  l.push(make_pair(r, c));
  b[r][c].vis = true;
  while (!l.empty()) {
    pair<int, int> a;
    a = l.front();
    l.pop();
    for (int i = 0; i < 4; i++) {
      int nr = mr[i] + a.first;
      int nc = mc[i] + a.second;
      if (nr >= 0 && nr < row && nc >= 0 && nc < col && b[nr][nc].c == 'B' &&
          b[nr][nc].vis == false) {
        b[nr][nc].vis = true;
        l.push(make_pair(nr, nc));
      }
    }
  }
}
int main() {
  int c, r;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> b[i][j].c;
      if (b[i][j].c == 'B') {
        b[i][j].vis = false;
      } else {
        b[i][j].vis = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (b[i][j].c == 'B' && b[i][j].vis == false) {
        ans++;
        bfs(i, j, r, c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
