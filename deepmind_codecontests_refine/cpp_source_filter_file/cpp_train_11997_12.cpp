#include <bits/stdc++.h>
using namespace std;
const int u[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int step[50][50][4][2];
int main() {
  int n, m, T;
  char field[50][51];
  scanf("%d%d", &n, &T);
  for (int i = 0; i < n; i++) scanf("%s", field[i]);
  m = strlen(field[0]);
  memset(step, -1, sizeof(step));
  int x = 0, y = 0;
  int BP = field[0][0] - '1', DP = 0, CP = 0, res;
  for (int s = 0;; s++) {
    int L = y, R = y, U = x, D = x;
    bool v[50][50];
    memset(v, false, sizeof(v));
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    v[x][y] = true;
    while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();
      L = min(L, cur.second);
      R = max(R, cur.second);
      U = min(U, cur.first);
      D = max(D, cur.first);
      for (int k = 0; k < 4; k++) {
        int t1 = cur.first + u[k][0];
        int t2 = cur.second + u[k][1];
        if (0 <= t1 && t1 < n && 0 <= t2 && t2 < m &&
            field[t1][t2] == '1' + BP && !v[t1][t2]) {
          Q.push(make_pair(t1, t2));
          v[t1][t2] = true;
        }
      }
    }
    x = U;
    y = L;
    if (step[x][y][DP][CP] == -1) {
      step[x][y][DP][CP] = s;
      if (s == T) {
        printf("%d\n", BP + 1);
        return 0;
      }
    } else {
      res = (n - step[x][y][DP][CP]) % (s - step[x][y][DP][CP]) +
            step[x][y][DP][CP];
      break;
    }
    int t1, t2;
    if (DP == 0) {
      t2 = R + 1;
      if (CP == 0)
        t1 = U;
      else
        t1 = D;
    }
    if (DP == 1) {
      t1 = D + 1;
      if (CP == 0)
        t2 = R;
      else
        t2 = L;
    }
    if (DP == 2) {
      t2 = L - 1;
      if (CP == 0)
        t1 = D;
      else
        t1 = U;
    }
    if (DP == 3) {
      t1 = U - 1;
      if (CP == 0)
        t2 = L;
      else
        t2 = R;
    }
    if (t1 < 0 || t2 < 0 || t1 >= n || t2 >= m || field[t1][t2] == '0') {
      if (CP == 0)
        CP = 1;
      else {
        CP = 0;
        DP = (DP + 1) % 4;
      }
    } else {
      BP = field[t1][t2] - '1';
      x = t1;
      y = t2;
    }
  }
  for (int t1 = 0; t1 < n; t1++)
    for (int t2 = 0; t2 < m; t2++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 2; k++)
          if (step[t1][t2][j][k] == res) {
            printf("%c\n", field[t1][t2]);
            return 0;
          }
  return 0;
}
