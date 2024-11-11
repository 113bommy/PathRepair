#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int q, i, f[40][2][2][2], g[40][2][2][2];
int read() {
  char c = getchar();
  int w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int cal(int x, int y, int z) {
  if (x < 0 || y < 0) return 0;
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  f[31][1][1][1] = 1;
  for (int i = 31; i >= 1; i--) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        for (int l = 0; l <= 1; l++) {
          if (!f[i][j][k][l]) continue;
          int la = j ? ((x >> (i - 1)) & 1) : 1;
          int lb = k ? ((y >> (i - 1)) & 1) : 1;
          int lc = l ? ((z >> (i - 1)) & 1) : 1;
          for (int a = 0; a <= la; a++) {
            for (int b = 0; b <= lb; b++) {
              if ((a ^ b) > lc) continue;
              add(f[i - 1][j & (a == la)][k & (b == lb)][l & ((a ^ b) == lc)],
                  f[i][j][k][l]);
              add(g[i - 1][j & (a == la)][k & (b == lb)][l & ((a ^ b) == lc)],
                  g[i][j][k][l]);
              add(g[i - 1][j & (a == la)][k & (b == lb)][l & ((a ^ b) == lc)],
                  f[i][j][k][l] * ((a ^ b) << (i - 1)) % mod);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        ans = (ans + f[0][i][j][k]) % mod;
        ans = (ans + g[0][i][j][k]) % mod;
      }
    }
  }
  return ans;
}
int main() {
  q = read();
  while (q--) {
    int x1 = read() - 1, y1 = read() - 1, x2 = read() - 1, y2 = read() - 1,
        k = read() - 1;
    long long ans = cal(x2, y2, k) - cal(x1 - 1, y2, k) - cal(x2, y1 - 1, k) +
                    cal(x1 - 1, y1 - 1, k);
    ans = (ans + 2 * mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
