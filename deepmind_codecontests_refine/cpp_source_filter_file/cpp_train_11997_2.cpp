#include <bits/stdc++.h>
using namespace std;
string s[50];
int n, m, k;
int cor[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int minix, miniy, maxx, maxy;
pair<pair<int, int>, pair<int, int> > pontas[50 * 50];
void dfs(int x, int y, int id, char c) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (s[x][y] != c) return;
  if (cor[x][y] == -1) {
    cor[x][y] = id;
    minix = min(minix, x);
    maxx = max(maxx, x);
    miniy = min(miniy, y);
    maxy = max(maxy, y);
    for (int a = 0; a < (int)(4); a++) {
      dfs(x + dx[a], y + dy[a], id, c);
    }
  }
}
int black(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return 1;
  if (s[x][y] == '0') return 1;
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < (int)(n); i++) {
    cin >> s[i];
    m = (int)(s[i]).size();
  }
  memset(cor, -1, sizeof(cor));
  int c = 0;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      if (cor[i][j] == -1) {
        minix = 10000, maxx = -1;
        miniy = 10000, maxy = -1;
        dfs(i, j, c++, s[i][j]);
        pontas[c - 1] =
            make_pair(make_pair(minix, miniy), make_pair(maxx, maxy));
      }
    }
  }
  int at = 0;
  int dirA = 0, dirB = 0;
  for (int i = 0; i < (int)(k); i++) {
    int x = -1, y = -1;
    if (dirA == 0) {
      y = pontas[at].second.second + 1;
      if (dirB == 0) {
        x = pontas[at].first.first;
      } else {
        x = pontas[at].second.first;
      }
    } else if (dirA == 2) {
      y = pontas[at].first.second - 1;
      if (dirB == 1) {
        x = pontas[at].first.first;
      } else {
        x = pontas[at].second.first;
      }
    } else if (dirA == 1) {
      x = pontas[at].second.first + 1;
      if (dirB == 0) {
        y = pontas[at].second.second;
      } else {
        y = pontas[at].first.second;
      }
    } else if (dirA == 3) {
      x = pontas[at].first.first - 1;
      if (dirB == 1) {
        y = pontas[at].second.second;
      } else {
        y = pontas[at].first.second;
      }
    }
    if (!black(x, y)) {
      at = cor[x][y];
    } else {
      if (!dirB) {
        dirB++;
      } else {
        dirA = (dirA + 1) % 4;
        dirB = 0;
      }
    }
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) {
      if (cor[i][j] == at) {
        cout << s[i][j] << endl;
        return 0;
      }
    }
  return 0;
}
