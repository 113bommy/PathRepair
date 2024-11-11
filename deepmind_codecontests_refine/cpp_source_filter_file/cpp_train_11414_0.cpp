#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
int n, a[10], f[5][1010][4100], bit[5][5];
char s[4][1010];
void upd(int &x, int v) { x = min(x, v); }
int id(int i, int j) {
  int now = (i - 1) * 4 + (j - 1);
  return 1 << now;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= 4; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j + i - 1 <= 4; j++) {
      for (int x = 1; x <= i; x++) {
        for (int y = 0; y < i; y++) {
          bit[i][j] += id(x, y + j);
        }
      }
      bit[i][j] ^= ((1 << 12) - 1);
    }
  }
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= n; j++) {
      for (int mask = 0; mask < (1 << 12); mask++) {
        f[i][j][mask] = inf;
      }
    }
  }
  f[4][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1; j <= 4; j++) {
      if (s[j][i] == '*') {
        now |= 1 << (j - 1);
      }
    }
    for (int mask = 0; mask < (1 << 8); mask++) {
      upd(f[0][i][(mask << 4) | now], f[4][i - 1][mask]);
    }
    for (int j = 1; j <= 4; j++) {
      for (int mask = 0; mask < (1 << 12); mask++) {
        int v = f[j - 1][i][mask];
        if (v >= inf) {
          continue;
        }
        upd(f[j][i][mask], v);
        for (int k = 1; k < 4 && k <= j; k++) {
          if (mask == 8) {
          }
          upd(f[j][i][mask & bit[k][j - k + 1]], v + a[k]);
        }
      }
    }
    for (int j = 1; j <= 4 && j <= i; j++) {
      upd(f[4][i][0], f[4][i - j][0] + a[4]);
    }
  }
  cout << f[4][n][0] << endl;
  return 0;
}
