#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int g[303][303];
int kk[4][303][303];
set<pair<int, int> > f;
const int LR = 0, RL = 1, UD = 2, DU = 3;
int tp, tu, td;
int ansx, ansy, ansx1, ansy1;
int mi = 2000000000;
int tmp;
int mabs(int x) {
  if (x < 0) return -x;
  return x;
}
int fuc(int x, int y, int x1, int y1) {
  int sum = 0;
  sum += kk[LR][x][y1] - kk[LR][x][y];
  sum += kk[UD][y1][x1] - kk[UD][y1][x];
  sum += kk[RL][x1][y] - kk[RL][x1][y1];
  sum += kk[DU][y][x] - kk[DU][y][x1];
  return sum;
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &tu, &td);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &g[i][j]);
  for (int i = 1; i <= n; i++) {
    tmp = 0;
    for (int j = 2; j <= m; j++) {
      if (g[i][j] == g[i][j - 1])
        tmp += tp;
      else if (g[i][j] > g[i][j - 1])
        tmp += tu;
      else
        tmp += td;
      kk[0][i][j] = tmp;
    }
    tmp = 0;
    for (int j = m - 1; j >= 1; j--) {
      if (g[i][j] == g[i][j + 1])
        tmp += tp;
      else if (g[i][j] > g[i][j + 1])
        tmp += tu;
      else
        tmp += td;
      kk[1][i][j] = tmp;
    }
  }
  for (int i = 1; i <= m; i++) {
    tmp = 0;
    for (int j = 2; j <= n; j++) {
      if (g[j][i] == g[j - 1][i])
        tmp += tp;
      else if (g[j][i] > g[j - 1][i])
        tmp += tu;
      else
        tmp += td;
      kk[2][i][j] = tmp;
    }
    tmp = 0;
    for (int j = n - 1; j >= 1; j--) {
      if (g[j][i] == g[j + 1][i])
        tmp += tp;
      else if (g[j][i] > g[j + 1][i])
        tmp += tu;
      else
        tmp += td;
      kk[3][i][j] = tmp;
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = i + 2; j <= n; j++) {
      f.clear();
      pair<int, int> ttmp;
      for (int k = 3; k <= m; k++) {
        ttmp.first = fuc(i, 1, j, k);
        ttmp.second = k;
        f.insert(ttmp);
      }
      int h = 0;
      for (int k = 3; k < m - 1; k++) {
        ttmp.first = t + h;
        ttmp.second = 0;
        set<pair<int, int> >::iterator p = f.lower_bound(ttmp);
        if (abs(p->first - t - h) < mi) {
          mi = abs(p->first - t - h);
          ansx = i;
          ansx1 = j;
          ansy = k - 2;
          ansy1 = p->second;
        }
        if (p != f.begin()) {
          p--;
          if (abs(p->first - t - h) < mi) {
            mi = abs(p->first - t - h);
            ansx = i;
            ansx1 = j;
            ansy = k - 2;
            ansy1 = p->second;
          }
        }
        ttmp.first = fuc(i, 1, j, k);
        ttmp.second = k;
        f.erase(ttmp);
        h += kk[LR][i][k - 1] - kk[LR][i][k - 2] + kk[RL][j][k - 1] -
             kk[RL][j][k - 2];
        h += kk[DU][k - 2][i] - kk[DU][k - 2][j] -
             (kk[DU][k - 1][i] - kk[DU][k - 1][j]);
      }
    }
  }
  printf("%d %d %d %d", ansx, ansy, ansx1, ansy1);
  return 0;
}
