#include <bits/stdc++.h>
using namespace std;
const int inf = 100000;
int fk[inf], ff[inf], n, m, k;
int a[250][250];
int main() {
  iostream ::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      fk[a[i][j]]++;
      int x = a[i][j] - k, d = 0;
      while (x > -1) {
        fk[x]++;
        ++d;
        ff[x] += d;
        x -= k;
      }
      x = a[i][j] + k, d = 0;
      while (x < inf) {
        fk[x]++;
        ++d;
        ff[x] += d;
        x += k;
      }
    }
  int ans = 1e9;
  for (int i = 0; i <= inf; i++)
    if (fk[i] == n * m && ans > ff[i]) ans = ff[i];
  if (ans == 1e9)
    cout << -1;
  else
    cout << ans;
  return 0;
}
