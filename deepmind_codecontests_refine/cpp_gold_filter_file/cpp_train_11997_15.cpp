#include <bits/stdc++.h>
using namespace std;
const int M = 200;
const int N = 100200;
const int kind = 26;
const int inf = 1 << 29;
const double eps = 1e-6;
const double pi = acos(-1.0);
const double sq2 = sqrt(2.0);
bool cal[60][60][4][2];
bool poss[60][60][4][2];
pair<int, int> go[60][60][4][2];
int mp[60][60];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string s;
int n, m;
int main() {
  while (scanf("%d%d", &m, &n) == 2) {
    memset(cal, 0, sizeof(cal));
    memset(poss, 0, sizeof(poss));
    for (int i = 0; i < m; i++) {
      cin >> s;
      mp[i + 1][0] = 0;
      mp[i + 1][s.size() + 1] = 0;
      for (int j = 0; j < s.size(); j++) {
        mp[i + 1][j + 1] = s[j] - '0';
      }
    }
    for (int i = 0; i < 60; i++) {
      mp[0][i] = mp[m + 1][i] = 0;
    }
    pair<int, int> cur = make_pair(1, 1);
    int dp = 0, cp = 0;
    while (n--) {
      pair<int, int> tmp = cur;
      if (cal[cur.first][cur.second][dp][cp]) {
        if (poss[cur.first][cur.second][dp][cp]) {
          cur = go[cur.first][cur.second][dp][cp];
          continue;
        } else {
          if (cp == 1) {
            cp = 0;
            dp = (dp + 1) % 4;
          } else
            cp = 1;
          continue;
        }
      }
      while (mp[cur.first + dx[dp]][cur.second + dy[dp]] ==
             mp[tmp.first][tmp.second]) {
        cur.first += dx[dp];
        cur.second += dy[dp];
      }
      int ddx, ddy;
      if (dp == 0)
        ddx = -1, ddy = 0;
      else if (dp == 1)
        ddx = 0, ddy = 1;
      else if (dp == 2)
        ddx = 1, ddy = 0;
      else
        ddx = 0, ddy = -1;
      if (cp == 1) {
        ddx *= -1;
        ddy *= -1;
      }
      while (mp[cur.first + ddx][cur.second + ddy] ==
             mp[tmp.first][tmp.second]) {
        cur.first += ddx;
        cur.second += ddy;
      }
      cal[tmp.first][tmp.second][dp][cp] = 1;
      if (mp[cur.first + dx[dp]][cur.second + dy[dp]] == 0) {
        poss[tmp.first][tmp.second][dp][cp] = 0;
        if (cp == 1) {
          cp = 0;
          dp = (dp + 1) % 4;
        } else {
          cp = 1;
        }
        continue;
      } else {
        poss[tmp.first][tmp.second][dp][cp] = 1;
        cur.first += dx[dp];
        cur.second += dy[dp];
        go[tmp.first][tmp.second][dp][cp] = cur;
        continue;
      }
    }
    printf("%d\n", mp[cur.first][cur.second]);
  }
  return 0;
}
