#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
char s[20][25];
int a[20][20];
int z[1 << 20], sv[20][20], c[20][20];
int main() {
  if (0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  while (scanf("%d%d", &(n), &(m)) == 2) {
    for (int i = 0; i < (n); ++i) scanf("%s", (s[i]));
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (m); ++j) scanf("%d", &(a[i][j]));
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (m); ++j) {
        int co = 0;
        int ma = 0;
        for (int k = 0; k < (n); ++k) {
          if (s[i][j] == s[k][j]) {
            sv[i][j] |= (1 << k);
            co += a[k][j];
            ma = max(ma, a[k][j]);
          }
        }
        c[i][j] = co - ma;
      }
    for (int i = 0; i < (1 << n); ++i) z[i] = INF;
    z[0] = 0;
    for (int mask = (1); mask < ((1 << n)); ++mask) {
      int lowbit = -1;
      for (int i = 0; i < (n); ++i)
        if (mask & (1 << i)) {
          lowbit = i;
          break;
        }
      for (int i = 0; i < (m); ++i) {
        z[mask] = min(z[mask], z[mask & ~(sv[lowbit][i])] + c[lowbit][i]);
        z[mask] = min(z[mask], z[mask & ~(1 << lowbit)] + a[lowbit][i]);
      }
    }
    printf("%d\n", z[(1 << n) - 1]);
  }
  return 0;
}
