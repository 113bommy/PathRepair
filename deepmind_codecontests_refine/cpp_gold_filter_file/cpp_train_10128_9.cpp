#include <bits/stdc++.h>
using namespace std;
int ara[20003][7], s[103][103], b[3][3] = {{8, 4}, {1, 2}};
char ch;
int detf(int x, int y) {
  int det = 0;
  if (s[x][y]) det += b[0][0];
  if (s[x][y + 1]) det += b[0][1];
  if (s[x + 1][y]) det += b[1][0];
  if (s[x + 1][y + 1]) det += b[1][1];
  return det;
}
void fun(int x, int y, int& z) {
  int f[][7] = {{0, 0, 0, 0, 0, 0},
                {x, y + 1, x + 1, y + 1, x + 1, y},
                {x, y, x, y + 1, x + 1, y + 1},
                {x, y, x, y + 1, x + 1, y + 1},
                {x + 1, y, x + 1, y + 1, x, y + 1},
                {x, y, x, y + 1, x + 1, y + 1},
                {x, y, x + 1, y, x + 1, y + 1},
                {x, y + 1, x + 1, y, x + 1, y + 1},
                {x, y, x, y + 1, x + 1, y},
                {x, y, x, y + 1, x + 1, y + 1},
                {x, y, x + 1, y, x, y + 1},
                {x, y, x + 1, y, x + 1, y + 1},
                {x, y, x + 1, y, x + 1, y + 1},
                {x, y, x, y + 1, x + 1, y},
                {x, y, x, y + 1, x + 1, y + 1},
                {x, y, x + 1, y, x, y + 1}};
  int d = detf(x, y);
  while (d != 0) {
    z++;
    for (int i = 0; i < 6; i++) {
      ara[z][i] = f[d][i];
      if ((i & 1)) s[f[d][i - 1]][f[d][i]] = !s[f[d][i - 1]][f[d][i]];
    }
    d = detf(x, y);
  }
}
void fun_m(int x, int y, int& z) {
  int f[][7] = {{0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {x + 1, y, x + 1, y - 1, x, y - 1},
                {x + 1, y, x + 1, y - 1, x, y - 1},
                {x, y, x, y - 1, x + 1, y - 1},
                {x, y, x, y - 1, x + 1, y - 1},
                {x, y, x + 1, y, x, y - 1},
                {x, y, x + 1, y, x, y - 1},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {x + 1, y, x + 1, y - 1, x, y - 1},
                {x + 1, y, x + 1, y - 1, x, y - 1},
                {x, y, x, y - 1, x + 1, y - 1},
                {x, y, x, y - 1, x + 1, y - 1},
                {x, y, x + 1, y, x, y - 1},
                {x, y, x + 1, y, x, y - 1}};
  int d = detf(x, y - 1);
  while (d != 1 && d != 9 && d != 0 && d != 8) {
    z++;
    for (int i = 0; i < 6; i++) {
      ara[z][i] = f[d][i];
      if ((i & 1)) s[f[d][i - 1]][f[d][i]] = !s[f[d][i - 1]][f[d][i]];
    }
    d = detf(x, y);
  }
}
void fun_n(int x, int y, int& z) {
  int f[][7] = {{0, 0, 0, 0, 0, 0},
                {x, y, x - 1, y, x - 1, y + 1},
                {x, y + 1, x - 1, y + 1, x - 1, y},
                {x, y, x, y + 1, x - 1, y},
                {0, 0, 0, 0, 0, 0},
                {x, y, x - 1, y, x - 1, y + 1},
                {x, y + 1, x - 1, y + 1, x - 1, y},
                {x, y, x, y + 1, x - 1, y},
                {0, 0, 0, 0, 0, 0},
                {x, y, x - 1, y, x - 1, y + 1},
                {x, y + 1, x - 1, y + 1, x - 1, y},
                {x, y, x, y + 1, x - 1, y},
                {0, 0, 0, 0, 0, 0},
                {x, y, x - 1, y, x - 1, y + 1},
                {x, y + 1, x - 1, y + 1, x - 1, y},
                {x, y, x, y + 1, x - 1, y}};
  int d = detf(x - 1, y);
  while (d != 0 && d != 4 && d != 8 && d != 12) {
    z++;
    for (int i = 0; i < 6; i++) {
      ara[z][i] = f[d][i];
      if ((i & 1)) s[f[d][i - 1]][f[d][i]] = !s[f[d][i - 1]][f[d][i]];
    }
    d = detf(x, y);
  }
}
int main() {
  int t, n, m, k, v, f[7];
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch;
        s[i][j] = ch - '0';
      }
    }
    k = 0;
    if ((m & 1) || (n & 1)) {
      fun_m(n - 2, m - 1, k);
    }
    if ((m & 1)) {
      for (int j = 0; j < n; j += 2) {
        fun_m(j, m - 1, k);
      }
    }
    if ((n & 1)) {
      for (int j = 0; j < m - 1; j += 2) {
        fun_n(n - 1, j, k);
      }
    }
    for (int i = 0; i < n - 1; i += 2) {
      for (int j = 0; j < m - 1; j += 2) {
        fun(i, j, k);
      }
    }
    cout << k << '\n';
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < 6; j++) cout << ara[i][j] + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}
