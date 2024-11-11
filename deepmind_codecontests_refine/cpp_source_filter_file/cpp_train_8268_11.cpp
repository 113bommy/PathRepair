#include <bits/stdc++.h>
using namespace std;
const int Up = 0, Left = 1, Down = 2, Right = 3;
int h[4][1005][1005];
int n, m, q;
int g[1005][1005];
int op, x, y;
void processrow(int i) {
  int last = -1;
  for (int(j) = 0; (j) < (m); ++(j)) {
    if (g[i][j] == 0) {
      h[Left][i][j] = h[Right][i][j] = 0;
      if (last == -1) continue;
      for (int(k) = (last); (k) < (j); ++(k)) {
        h[Right][i][k] = j - k;
        h[Left][i][k] = k - last + 1;
      }
      last = -1;
    } else {
      if (last == -1) last = j;
      if (j == m - 1) {
        for (int(k) = (last); (k) < (j + 1); ++(k)) {
          h[Right][i][k] = j - k + 1;
          h[Left][i][k] = k - last + 1;
        }
      }
    }
  }
  return;
}
void processcolumn(int i) {
  int last = -1;
  for (int(j) = 0; (j) < (n); ++(j)) {
    if (g[j][i] == 0) {
      h[Down][j][i] = h[Up][j][i] = 0;
      if (last == -1) continue;
      for (int(k) = (last); (k) < (j); ++(k)) {
        h[Down][k][i] = j - k;
        h[Up][k][i] = k - last + 1;
      }
      last = -1;
    } else {
      if (last == -1) last = j;
      if (j == n - 1) {
        for (int(k) = (last); (k) < (j + 1); ++(k)) {
          h[Down][k][i] = j - k + 1;
          h[Up][k][i] = k - last + 1;
        }
      }
    }
  }
  return;
}
void init() {
  for (int(i) = 0; (i) < (n); ++(i)) processrow(i);
  for (int(i) = 0; (i) < (m); ++(i)) processcolumn(i);
  return;
}
int calc_leftright_height(int x, int y, int dir) {
  int a = x, b = x;
  int best = 0;
  for (int height = h[dir][x][y]; height > 0; height--) {
    while (a > 0 && h[dir][a - 1][y] >= height) {
      a--;
    }
    while (b < n - 1 && h[dir][b + 1][y] >= height) {
      b++;
    }
    best = max(best, (b - a + 1) * height);
  }
  return best;
}
int calc_updown_height(int x, int y, int dir) {
  int a = y, b = y;
  int best = 0;
  for (int height = h[dir][x][y]; height > 0; height--) {
    while (a > 0 && h[dir][x][a - 1] >= height) {
      a--;
    }
    while (b < m - 1 && h[dir][x][b + 1] >= height) {
      b++;
    }
    best = max(best, (b - a + 1) * height);
  }
  return best;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d%d%d", &n, &m, &q);
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (m); ++(j)) scanf("%d", &g[i][j]);
  init();
  for (int(_a) = 0; (_a) < (q); ++(_a)) {
    scanf("%d%d%d", &op, &x, &y);
    x = n - x;
    y--;
    if (op == 1) {
      g[x][y] = 1 - g[x][y];
      processrow(x);
      processcolumn(y);
    } else {
      int best = 0;
      best = max(best, calc_leftright_height(x, y, Left));
      best = max(best, calc_leftright_height(x, y, Right));
      best = max(best, calc_updown_height(x, y, Up));
      best = max(best, calc_updown_height(x, y, Down));
      printf("%d\n", best);
    }
  }
  return 0;
}
