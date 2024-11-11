#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, i, a[101], b[101], c[101] = {0}, d = 1e9, ans = 0, j;
  cin >> n >> m >> k;
  for (i = 1; i <= m; i++) cin >> a[i];
  for (i = 1; i <= k; i++) cin >> b[i];
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= k; j++) {
      if (b[j] % a[i] == 0) c[i]++;
    }
    d = min(d, c[i]);
  }
  for (i = 1; i <= m; i++)
    if (c[i] == d) ans++;
  cout << ans << endl;
  for (i = 1; i <= m; i++)
    if (c[i] == d) cout << i << " ";
  return 0;
}
