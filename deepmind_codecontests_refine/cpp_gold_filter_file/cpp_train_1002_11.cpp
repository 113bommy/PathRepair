#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
int n, m;
char mos[MAXN][MAXN];
signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", mos[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mos[i][j] ^ '.') {
        for (int k = 1; k <= n; ++k) {
          for (int l = 1; l <= m; ++l) {
            if (!(mos[k][l] ^ '#' || k == i || l == j)) {
              if (mos[i][l] ^ '.' && mos[k][j] ^ '#' ||
                  mos[i][l] ^ '#' && mos[k][j] ^ '.')
                return puts("No") & 0;
            }
          }
        }
      }
    }
  }
  return puts("Yes") & 0;
}
