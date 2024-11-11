#include <bits/stdc++.h>
using namespace std;
string mp[52];
int c[52][52];
pair<int, int> p[52 * 52][4][2];
int vis[52][52][4][2];
vector<char> res;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  int n, nm;
  cin >> n >> nm;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i];
    mp[i] = "0" + mp[i] + "0";
  }
  int sz = mp[1].size();
  string s;
  s.resize(sz, '0');
  mp[0] = mp[n + 1] = s;
  char col;
  int k = 1, rs, cs;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sz; j++) {
      if (!c[i][j] && mp[i][j] != '0') {
        col = mp[i][j];
        for (rs = j; rs <= sz; rs++) {
          if (mp[i][rs] != col) break;
        }
        rs--;
        p[k][2][1] = p[k][3][0] = make_pair(i, j);
        p[k][0][0] = p[k][3][1] = make_pair(i, rs);
        for (cs = i; cs <= n; cs++) {
          if (mp[cs][j] == col) {
            for (int jj = j; jj <= rs; jj++) {
              c[cs][jj] = k;
            }
          } else
            break;
        }
        cs--;
        p[k][1][1] = p[k][2][0] = make_pair(cs, j);
        p[k][0][1] = p[k][1][0] = make_pair(cs, rs);
        k++;
      }
    }
  }
  int x, y, d, r, nx, ny;
  x = y = 1;
  d = r = 0;
  k = 1;
  while (!vis[x][y][d][r]) {
    vis[x][y][d][r] = k++;
    res.push_back(mp[x][y]);
    x = p[c[x][y]][d][r].first;
    y = p[c[x][y]][d][r].second;
    nx = x + dx[d];
    ny = y + dy[d];
    if (mp[nx][ny] == '0') {
      if (r == 0)
        r = 1;
      else {
        r = 0;
        d = (d + 1) % 4;
      }
    } else {
      x = nx;
      y = ny;
    }
  }
  int nk = vis[x][y][d][r];
  if (nm < nk - 1)
    cout << res[nm] << endl;
  else {
    nm -= nk - 1;
    cout << res[nm % (k - nk) + nk - 1] << endl;
  }
  return 0;
}
