#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a[110][110], l[110], c[110];
bool ok;
bitset<110> L, C;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      l[i] += a[i][j];
      c[j] += a[i][j];
    }
  ok = 1;
  while (ok) {
    ok = 0;
    for (i = 1; i <= n; i++)
      if (l[i] < 0) {
        for (j = 1; j <= m; j++) {
          l[i] -= 2 * a[i][j];
          c[j] -= 2 * a[i][j];
          a[i][j] = -a[i][j];
        }
        L[i] = 1 - L[i];
        ok = 1;
        break;
      }
    if (ok) continue;
    for (j = 1; j <= m; j++)
      if (c[j] < 0) {
        for (i = 1; i <= n; i++) {
          l[i] -= 2 * a[i][j];
          c[j] -= 2 * a[i][j];
          a[i][j] = -a[i][j];
        }
        C[j] = 1 - C[j];
        ok = 1;
        break;
      }
  }
  cout << L.count() << ' ';
  for (i = 1; i <= n; i++)
    if (L[i]) cout << i << ' ';
  cout << '\n';
  cout << C.count() << ' ';
  for (i = 1; i <= m; i++)
    if (C[i]) cout << i << ' ';
  return 0;
}
