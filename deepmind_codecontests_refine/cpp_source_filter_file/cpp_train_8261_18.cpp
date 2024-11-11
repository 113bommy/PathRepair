#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
const int H = 30;
int dp[2][16][H + 1][H + 1][H + 1];
bool solve(int test) {
  int n, h;
  scanf("%d %d", &n, &h);
  if (h == 1) {
    printf("4\n");
    return false;
  } else {
    dp[1][15][1][1][1] = 1;
  }
  int x[4];
  for (int k = 1; k < n; k++) {
    for (int alive = 1; alive < 16; alive++) {
      for (int a = alive & 2 ? 1 : h; a <= h; a++) {
        for (int b = alive & 4 ? 1 : h; b <= h; b++) {
          for (int c = alive & 8 ? 1 : h; c <= h; c++) {
            if (dp[k & 1][alive][a][b][c] == 0) continue;
            x[0] = alive & 1 ? 1 : h;
            x[1] = min(h, a + 1);
            x[2] = min(h, b + 1);
            x[3] = min(h, c + 1);
            int al = alive;
            for (int i = 1; i < 4; i++) {
              if (x[i] == h) {
                al &= ~(1 << i);
              }
            }
            for (int p = 0; p < 4; p++) {
              int mask = al;
              mask &= (1 << p) - 1;
              mask <<= 4 - p;
              mask |= al >> p;
              if (alive & (1 << p)) mask |= 1;
              add(dp[k + 1 & 1][mask][x[p + 1 & 3]][x[p + 2 & 3]][x[p + 3 & 3]],
                  dp[k & 1][alive][a][b][c]);
            }
            dp[k & 1][alive][a][b][c] = 0;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int alive = 1; alive < 16; alive++) {
    for (int a = alive & 2 ? 1 : h; a <= h; a++) {
      for (int b = alive & 4 ? 1 : h; b <= h; b++) {
        for (int c = alive & 8 ? 1 : h; c <= h; c++) {
          int o = dp[n & 1][alive][a][b][c];
          if ((alive & 1))
            add(ans, o);
          else if ((alive & 2) && a < h)
            add(ans, o);
          else if ((alive & 4) && b < h)
            add(ans, o);
          else if ((alive & 8) && c < h)
            add(ans, o);
        }
      }
    }
  }
  add(ans, ans);
  add(ans, ans);
  printf("%d\n", ans);
  return false;
}
int main() {
  int t = 0;
  while (solve(++t))
    ;
  return 0;
}
