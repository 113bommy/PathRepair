#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, j, ex, ey, sx, sy;
string res;
queue<pair<int, int> > Q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int D[51][51];
bool F[257];
char A[51][51];
void push(int x, int y, int z) {
  if ((x >= 0 && x < n) && (y >= 0 && y < m) && F[A[x][y]] && D[x][y] == -1) {
    D[x][y] = z;
    Q.push(make_pair(x, y));
  }
}
void rec(int i, int j) {
  int x, y, x2, y2, z;
  char c;
  string str;
  set<pair<int, int> > S;
  set<pair<int, int> >::iterator it;
  if (i == k) {
    memset(D, -1, sizeof D);
    push(ex, ey, 0);
    while (!Q.empty()) {
      x = Q.front().first;
      y = Q.front().second;
      Q.pop();
      for (i = 0; i < 4; i++) push(x + dx[i], y + dy[i], D[x][y] + 1);
    }
    if (D[sx][sy] != -1) {
      Q.push(make_pair(sx, sy));
      str = "";
      while (str.size() < D[sx][sy]) {
        c = 'z';
        while (!Q.empty()) {
          x = Q.front().first;
          y = Q.front().second;
          cout << flush;
          Q.pop();
          for (i = 0; i < 4; i++) {
            x2 = x + dx[i];
            y2 = y + dy[i];
            if ((x2 >= 0 && x2 < n) && (y2 >= 0 && y2 < m) &&
                D[x2][y2] == D[x][y] - 1) {
              if (A[x2][y2] < c) {
                c = A[x2][y2];
                S.clear();
              }
              if (A[x2][y2] == c) S.insert(make_pair(x2, y2));
            }
          }
        }
        for (it = S.begin(); it != S.end(); it++) Q.push(*it);
        str += c;
      }
      if (res == "S" || str.size() < res.size() ||
          (str.size() == res.size() && str < res))
        res = str;
    }
  } else
    for (; j < 'z'; j++) {
      F[j] = 1;
      rec(i + 1, j + 1);
      F[j] = 0;
    }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%s", A[i]);
    for (j = 0; j < m; j++)
      if (A[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (A[i][j] == 'T') {
        ex = i;
        ey = j;
      }
  }
  F['S'] = F['T'] = 1;
  res = "S";
  rec(0, 'a');
  printf("%s\n", res == "S" ? "-1" : res.substr(0, res.size() - 1).c_str());
  return 0;
}
