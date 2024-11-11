#include <bits/stdc++.h>
using namespace std;
char grid[60][60];
int conf[60][60][4][2];
map<int, pair<pair<int, int>, pair<int, int> > > mp;
int drow[] = {0, +1, 0, -1};
int dcol[] = {+1, 0, -1, 0};
int main() {
  int m, n;
  scanf("%d%d\n", &m, &n);
  for (int i = 0; i < m; ++i) {
    gets(grid[i]);
  }
  int nrow, ncol;
  nrow = m;
  ncol = strlen(grid[0]);
  pair<pair<int, int>, pair<int, int> > head;
  int looplen;
  memset(conf, -1, sizeof conf);
  int r = 0, c = 0, DP = 0, CP = 0;
  int cnt = 0;
  mp[cnt] = pair<pair<int, int>, pair<int, int> >(pair<int, int>(r, c),
                                                  pair<int, int>(DP, CP));
  conf[r][c][DP][CP] = cnt++;
  while (true) {
    char color = grid[r][c];
    while (true) {
      int rr = r + drow[DP], cc = c + dcol[DP];
      if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol &&
          grid[rr][cc] == color) {
        r = rr;
        c = cc;
      } else {
        break;
      }
    }
    int x = DP;
    if (CP == 0)
      x = (x - 1 + 4) % 4;
    else
      x = (x + 1) % 4;
    while (true) {
      int rr = r + drow[x], cc = c + dcol[x];
      if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol &&
          grid[rr][cc] == color) {
        r = rr;
        c = cc;
      } else {
        break;
      }
    }
    int rr = r + drow[DP], cc = c + dcol[DP];
    if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol && grid[rr][cc] != '0') {
      r = rr;
      c = cc;
    } else {
      if (CP == 0) {
        CP = 1 - CP;
      } else {
        DP = (DP + 1) % 4;
        CP = 1 - CP;
      }
    }
    if (conf[r][c][DP][CP] >= 0) {
      head.first.first = r;
      head.first.second = c;
      head.second.first = DP;
      head.second.second = CP;
      looplen = cnt - conf[r][c][DP][CP];
      break;
    } else {
      mp[cnt] = pair<pair<int, int>, pair<int, int> >(pair<int, int>(r, c),
                                                      pair<int, int>(DP, CP));
      conf[r][c][DP][CP] = cnt++;
    }
  }
  int idx = conf[head.first.first][head.first.second][head.second.first]
                [head.second.second];
  int index = (n - idx) % looplen + idx;
  pair<pair<int, int>, pair<int, int> > last = mp[index];
  int rlast = last.first.first, clast = last.first.second;
  char ans[2] = {0};
  ans[0] = grid[rlast][clast];
  puts(ans);
}
