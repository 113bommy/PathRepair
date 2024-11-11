#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
int i, j, n, m, k, l, a[1001][101], kol, bit;
struct Pair {
  int f;
  int s;
} ans[5001];
int main() {
  srand(time(NULL));
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  if (k == 0)
    for (i = 1; i <= m; i++) {
      for (j = i + 1; j <= m; j++) {
        bit = 0;
        for (l = 1; l <= n; l++) {
          if (a[l][i] > a[l][j]) {
            swap(a[l][i], a[l][j]);
            bit = 1;
          }
        }
        if (bit) {
          ans[++kol].f = i;
          ans[kol].s = j;
        }
      }
    }
  if (k == 1)
    for (i = 1; i <= m; i++) {
      for (j = i + 1; j <= m; j++) {
        bit = 0;
        for (l = 1; l <= n; l++) {
          if (a[l][i] < a[l][j]) {
            swap(a[l][i], a[l][j]);
            bit = 1;
          }
        }
        if (bit) {
          ans[++kol].f = j;
          ans[kol].s = i;
        }
      }
    }
  cout << kol << endl;
  for (i = 1; i <= kol; i++) cout << ans[i].f << " " << ans[i].s << endl;
  return 0;
}
