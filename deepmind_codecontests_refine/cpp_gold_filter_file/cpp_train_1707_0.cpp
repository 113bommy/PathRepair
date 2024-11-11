#include <bits/stdc++.h>
using namespace std;
const int oo = (1 << 29);
const int MAXN = (90 * 90) / 2;
const int MAXV = 100;
int n;
int w[MAXN][MAXN];
int usedx[MAXN], usedy[MAXN];
int from[MAXN];
int labelx[MAXN], labely[MAXN];
bool kuhn(int x) {
  usedx[x] = true;
  for (int y = 1; y <= n; y++) {
    if (!usedy[y] && labelx[x] + labely[y] == w[x][y]) {
      usedy[y] = true;
      if (!from[y] || kuhn(from[y])) {
        from[y] = x;
        return true;
      }
    }
  }
  return false;
}
int hungarian() {
  for (int i = 1; i <= n; i++) {
    from[i] = 0;
    labely[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    labelx[i] = 0;
    for (int j = 1; j <= n; j++) {
      labelx[i] = max(labelx[i], w[i][j]);
    }
  }
  for (int k = 1; k <= n; k++) {
    while (1) {
      for (int i = 1; i <= n; i++) {
        usedx[i] = usedy[i] = false;
      }
      if (kuhn(k)) {
        break;
      }
      int exc = oo;
      for (int i = 1; i <= n; i++) {
        if (usedx[i]) {
          for (int j = 1; j <= n; j++) {
            if (!usedy[j]) {
              exc = min(exc, labelx[i] + labely[j] - w[i][j]);
            }
          }
        }
      }
      if (exc == 0 || exc == oo) {
        break;
      }
      for (int i = 1; i <= n; i++) {
        if (usedx[i]) {
          labelx[i] -= exc;
        }
        if (usedy[i]) {
          labely[i] += exc;
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += labely[i];
    res += labelx[from[i]];
  }
  return res;
}
int x[MAXN][MAXN];
int nod[MAXN][MAXN];
int movI[] = {1, 0, -1, 0};
int movJ[] = {0, 1, 0, -1};
int R, C;
bool can_move(int i, int j) { return (i >= 1 && j >= 1 && i <= R && j <= C); }
int get_nod(int i, int j) {
  int u = (i - 1) * C + j;
  u = (u + 1) / 2;
  return u;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  n = (R * C) / 2;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> x[i][j];
      nod[i][j] = get_nod(i, j);
    }
  }
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      int u = nod[i][j];
      if ((i + j) % 2 == 0) {
        for (int k = 0; k < 4; k++) {
          int ii = i + movI[k];
          int jj = j + movJ[k];
          if (can_move(ii, jj)) {
            int v = nod[ii][jj];
            w[u][v] = MAXV;
            if (x[i][j] != x[ii][jj]) {
              w[u][v] = MAXV - 1;
            }
          }
        }
      }
    }
  }
  cout << (n * MAXV) - hungarian() << '\n';
}
