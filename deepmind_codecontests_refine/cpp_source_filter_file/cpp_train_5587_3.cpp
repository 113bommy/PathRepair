#include <bits/stdc++.h>
using namespace std;
char str[20][20];
int us[20][20];
int eg[28][2];
int tz[28];
int con[14][14];
int bR[15], bL[15];
int L[14][8], R[14][8], C[14], U[14][8];
int ma[14][4], mp[14];
int has[8][8];
int c[14], ac[14];
int total, r;
inline int del(int x, int y, int i) {
  if (c[y]) {
    has[c[x]][c[y]]++;
    has[c[y]][c[x]]++;
    if (has[c[x]][c[y]] > 1) return 1;
  } else {
    if (U[y][i] != -1) return 0;
    L[y][R[y][i]] = L[y][i];
    R[y][L[y][i]] = R[y][i];
    U[y][i] = x;
    C[y]--;
    if (C[y] == 0) return 1;
  }
  return 0;
}
inline void rev(int x, int y, int i) {
  if (c[y]) {
    has[c[x]][c[y]]--;
    has[c[y]][c[x]]--;
  } else {
    if (U[y][i] != x) return;
    L[y][R[y][i]] = i;
    R[y][L[y][i]] = i;
    U[y][i] = -1;
    C[y]++;
  }
}
void dfs2(int x) {
  int i, j, f;
  if (x == 14) {
    if (total == 0) {
      for (i = 0; i < 14; i++) {
        ac[i] = c[i];
      }
    }
    total++;
  } else {
    for (i = R[x][0]; i; i = R[x][i]) {
      f = 0;
      c[x] = i;
      bR[bL[x]] = bR[x];
      bL[bR[x]] = bL[x];
      for (j = 0; j < mp[x]; j++) {
        f += del(x, ma[x][j], i);
      }
      if (!f) {
        dfs2(bR[x]);
      }
      for (j = 0; j < mp[x]; j++) {
        rev(x, ma[x][j], i);
      }
      bR[bL[x]] = x;
      bL[bR[x]] = x;
      c[x] = 0;
    }
  }
}
void dfs1(int d, int p) {
  int i, j, x, y, f;
  if (d == 7) {
    dfs2(bR[14]);
  } else {
    for (i = p; i < r; i++) {
      f = 0;
      x = eg[i][0];
      y = eg[i][1];
      if (c[x] || c[y]) continue;
      c[x] = c[y] = d + 1;
      bR[bL[x]] = bR[x];
      bL[bR[x]] = bL[x];
      bR[bL[y]] = bR[y];
      bL[bR[y]] = bL[y];
      has[d + 1][d + 1]++;
      for (j = 0; j < mp[x]; j++) {
        if (ma[x][j] == y) continue;
        f += del(x, ma[x][j], d + 1);
      }
      for (j = 0; j < mp[y]; j++) {
        if (ma[y][j] == x) continue;
        f += del(y, ma[y][j], d + 1);
      }
      if (!f) {
        dfs1(d + 1, i + 1);
      }
      for (j = 0; j < mp[y]; j++) {
        if (ma[y][j] == x) continue;
        rev(y, ma[y][j], d + 1);
      }
      for (j = 0; j < mp[x]; j++) {
        if (ma[x][j] == y) continue;
        rev(x, ma[x][j], d + 1);
      }
      has[d + 1][d + 1]--;
      bR[bL[x]] = x;
      bL[bR[x]] = x;
      bR[bL[y]] = y;
      bL[bR[y]] = y;
      c[x] = c[y] = 0;
    }
  }
}
int main() {
  int n, m, i, j, flag, k, h, z, x, y;
  while (scanf("%d %d", &n, &m) == 2) {
    for (i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }
    memset(us, -1, sizeof(us));
    flag = 1;
    r = 0;
    for (i = 0; i < n && flag; i++) {
      for (j = 0; j < m; j++) {
        if (str[i][j] != '.' && us[i][j] == -1) {
          if (str[i][j + 1] == '.' || str[i + 1][j] == '.' ||
              str[i + 1][j + 1] == '.' || us[i + 1][j] != -1 ||
              us[i][j + 1] != -1 || us[i + 1][j + 1] != -1) {
            flag = 0;
            break;
          }
          us[i][j] = us[i + 1][j] = us[i][j + 1] = us[i + 1][j + 1] = r++;
        }
      }
    }
    if (!flag) {
      puts("0");
      continue;
    }
    r = z = 0;
    memset(con, 0, sizeof(con));
    flag = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (str[i][j] != '.') {
          for (h = 0; h < n && str[i][j] != '.'; h++) {
            for (k = 0; k < m; k++) {
              if (h == i && k == j) continue;
              if (str[i][j] == str[h][k]) {
                if (con[us[i][j]][us[h][k]]) {
                  flag = 0;
                  goto out;
                } else {
                  if (us[i][j] == us[h][k]) {
                    tz[z++] = us[i][j];
                  } else {
                    eg[r][0] = us[i][j];
                    eg[r][1] = us[h][k];
                    r++;
                  }
                  con[us[i][j]][us[h][k]] = con[us[i][j]][us[h][k]] = 1;
                }
                str[i][j] = str[h][k] = '.';
                break;
              }
            }
          }
        }
      }
    }
  out:
    if (flag == 0 || z > 7) {
      puts("0");
      continue;
    }
    for (i = 0; i <= 14; i++) {
      bR[i] = (i + 1) % 15;
      bL[i] = (i + 14) % 15;
    }
    for (i = 0; i < 14; i++) {
      for (j = 0; j <= 7; j++) {
        R[i][j] = (j + 1) % 8;
        L[i][j] = (j + 7) % 8;
        U[i][j] = -1;
      }
      C[i] = 7;
    }
    memset(mp, 0, sizeof(mp));
    for (i = 0; i < r; i++) {
      ma[eg[i][0]][mp[eg[i][0]]++] = eg[i][1];
      ma[eg[i][1]][mp[eg[i][1]]++] = eg[i][0];
    }
    memset(has, 0, sizeof(has));
    memset(c, 0, sizeof(c));
    for (i = 0; i < z; i++) {
      x = tz[i];
      bL[bR[x]] = bL[x];
      bR[bL[x]] = bR[x];
      c[x] = i + 1;
      has[i + 1][i + 1] = 1;
      for (j = 0; j < mp[x]; j++) {
        del(x, ma[x][j], i + 1);
      }
    }
    total = 0;
    dfs1(z, 0);
    printf("%d\n", total * 5040);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (us[i][j] == -1) {
          printf(".");
        } else {
          printf("%d", ac[us[i][j]] - 1);
        }
      }
      puts("");
    }
  }
  return 0;
}
