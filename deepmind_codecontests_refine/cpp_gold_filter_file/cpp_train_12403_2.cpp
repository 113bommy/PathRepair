#include <bits/stdc++.h>
using namespace std;
int n, m, res = 0, cnt = 0;
vector<bool> vc[1000000];
bool used[101][101];
bool a[101];
int dx[] = {1, 0, 0, -1, 0};
int dy[] = {0, 1, -1, 0, 0};
void go(int x, int y, int ans, int id) {
  if (x == n + 1 && y == m + 1) {
    res = max(res, n * m - ans);
    return;
  }
  if (x == 1) {
    int i;
    for (i = 0; i <= 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      vc[id][i] = used[xx][yy];
      used[xx][yy] = 1;
    }
    a[y] = 1;
    if (y == m)
      go(x + 1, 1, ans + 1, id + 1);
    else
      go(x, y + 1, ans + 1, id + 1);
    a[y] = 0;
    for (i = 0; i <= 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      used[xx][yy] = vc[id][i];
    }
    if (y == m)
      go(x + 1, 1, ans, id + 1);
    else
      go(x, y + 1, ans, id + 1);
  } else {
    if (x != n) {
      if (used[x - 1][y]) {
        if ((y != 1 && used[x][y - 1])) {
          if (y == m)
            go(x + 1, 1, ans, id + 1);
          else
            go(x, y + 1, ans, id + 1);
        } else {
          int i;
          for (i = 0; i <= 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            vc[id][i] = used[xx][yy];
            used[xx][yy] = 1;
          }
          if (y == m)
            go(x + 1, 1, ans + 1, id + 1);
          else
            go(x, y + 1, ans + 1, id + 1);
          a[y] = 0;
          for (i = 0; i <= 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            used[xx][yy] = vc[id][i];
          }
          if (y == m)
            go(x + 1, 1, ans, id + 1);
          else
            go(x, y + 1, ans, id + 1);
        }
      } else {
        int i;
        for (i = 0; i <= 4; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          vc[id][i] = used[xx][yy];
          used[xx][yy] = 1;
        }
        if (y == m)
          go(x + 1, 1, ans + 1, id + 1);
        else
          go(x, y + 1, ans + 1, id + 1);
        for (i = 0; i <= 4; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          used[xx][yy] = vc[id][i];
        }
      }
    } else {
      if (used[x - 1][y]) {
        if (y != 1 && !used[x][y - 1]) {
          int i;
          for (i = 0; i <= 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            vc[id][i] = used[xx][yy];
            used[xx][yy] = 1;
          }
          if (y == m)
            go(x + 1, y + 1, ans + 1, id + 1);
          else
            go(x, y + 1, ans + 1, id + 1);
          for (i = 0; i <= 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            used[xx][yy] = vc[id][i];
          }
        } else {
          if (y == m) {
            if (used[x][y])
              go(x + 1, y + 1, ans, id + 1);
            else {
              go(x + 1, y + 1, ans + 1, id + 1);
            }
          } else
            go(x, y + 1, ans, id + 1);
        }
      } else {
        int i;
        for (i = 0; i <= 4; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          vc[id][i] = used[xx][yy];
          used[xx][yy] = 1;
        }
        if (y == m)
          go(x + 1, y + 1, ans + 1, id + 1);
        else
          go(x, y + 1, ans + 1, id + 1);
        for (i = 0; i <= 4; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          used[xx][yy] = vc[id][i];
        }
      }
    }
  }
}
int main() {
  for (int j = 1; j <= 60; j++) {
    for (int i = 0; i <= 4; i++) vc[j].push_back(0);
  }
  cin >> n >> m;
  if (n < m) swap(n, m);
  if (m == 1) {
    int s = n / 3 * 2;
    if (n % 3 == 2) s++;
    cout << s << endl;
    return 0;
  }
  go(1, 1, 0, 1);
  cout << res << endl;
}
