#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int SIZE = 1e6 + 5;
const long long INF = 1LL << 58;
const double eps = 1e-10;
char d[2009][2009];
char a[2009][2009];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int dy2[8] = {-2, -1, 0, 1, 2, 1, 0, -1};
int dx2[8] = {0, 1, 2, 1, 0, -1, -2, -1};
char v[5] = "^>v<";
char v2[5] = "v<^>";
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) {
    scanf("%s", (d[i]));
    for (int j = 0; j < (m); ++j) {
      if (d[i][j] == '*')
        a[i][j] = '*';
      else
        a[i][j] = '.';
    }
  }
  queue<pair<int, int> > q;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      if (d[i][j] == '*') continue;
      q.push(make_pair(i, j));
    }
  }
  while (((int)(q).size())) {
    pair<int, int> cur = q.front();
    q.pop();
    int y = cur.first, x = cur.second;
    if (a[y][x] != '.') continue;
    int ck = -1;
    for (int k = 0; k < (4); ++k) {
      int ny = y + dy[k], nx = x + dx[k];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (a[ny][nx] == '.') {
        if (ck != -1) {
          ck = -1;
          break;
        } else
          ck = k;
      }
    }
    if (ck == -1) continue;
    int ny = y + dy[ck], nx = x + dx[ck];
    a[y][x] = v[ck];
    a[ny][nx] = v2[ck];
    for (int k = 0; k < (8); ++k) {
      int ny = y + dy2[k], nx = x + dx2[k];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      q.push(make_pair(ny, nx));
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      if (a[i][j] == '.') {
        puts("Not unique");
        return 0;
      }
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      printf("%c", a[i][j]);
    }
    puts("");
  }
}
