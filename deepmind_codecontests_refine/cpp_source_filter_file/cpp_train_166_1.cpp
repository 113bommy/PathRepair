#include <bits/stdc++.h>
using namespace std;
struct Cell {
  char c;
  pair<int, int> a[4];
  Cell() : c(5) {}
};
vector<vector<Cell> > b;
int n, m;
inline void remove(int x, int y) {
  pair<int, int> u = b[x][y].a[0];
  b[u.first][u.second].a[2] = b[x][y].a[2];
  u = b[x][y].a[1];
  b[u.first][u.second].a[3] = b[x][y].a[3];
  u = b[x][y].a[2];
  b[u.first][u.second].a[0] = b[x][y].a[0];
  u = b[x][y].a[3];
  b[u.first][u.second].a[1] = b[x][y].a[1];
  b[x][y].c = 4;
}
int getNum(int x, int y) {
  int r = 0;
  while (x <= n && y <= m && x > 0 && y > 0) {
    ++r;
    pair<int, int> next = b[x][y].a[b[x][y].c];
    remove(x, y);
    x = next.first, y = next.second;
  }
  return r;
}
int main(int argc, char** argv) {
  char cc[256];
  cc['.'] = 4;
  cc['L'] = 0;
  cc['U'] = 1;
  cc['R'] = 2;
  cc['D'] = 3;
  if (argc > 1) freopen(argv[1], "r", stdin);
  scanf("%d%d\n", &n, &m);
  vector<vector<Cell> > a(n + 2, vector<Cell>(m + 2));
  for (int i = (1); i < (n + 1); ++i) {
    for (int j = (1); j < (m + 1); ++j) {
      scanf("%c", &a[i][j].c);
      a[i][j].c = cc[a[i][j].c];
      a[i][j].a[0] =
          (a[i][j - 1].c != 4) ? make_pair(i, j - 1) : a[i][j - 1].a[0];
      a[i][j].a[1] =
          (a[i - 1][j].c != 4) ? make_pair(i - 1, j) : a[i - 1][j].a[1];
    }
    scanf("\n");
  }
  for (int i = (n); i >= (1); --i)
    for (int j = (m); j >= (1); --j) {
      a[i][j].a[2] =
          (a[i][j + 1].c != 4) ? make_pair(i, j + 1) : a[i][j + 1].a[2];
      a[i][j].a[3] =
          (a[i + 1][j].c != 4) ? make_pair(i + 1, j) : a[i + 1][j].a[3];
    }
  int mx = 0, cnt = 0;
  for (int i = (1); i < (n + 1); ++i)
    for (int j = (1); j < (m + 1); ++j)
      if (a[i][j].c != '.') {
        b = a;
        int k = getNum(i, j);
        if (k > mx)
          mx = k, cnt = 1;
        else if (k == mx)
          ++cnt;
      }
  printf("%d %d\n", mx, cnt);
  return 0;
}
