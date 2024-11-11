#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
const int MX = 5e4 + 5;
int z[MAX], a[MX], b[MX], l[MX], r[MX], ans[MX];
int main() {
  int n, m;
  z[0] = 0;
  for (int i = 1; i < MAX; i++) z[i] = z[i - 1] ^ i;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d%d", &l[i], &r[i]);
    for (int i = 1; i <= n; i++) {
      int mx = 0;
      for (int j = i; j <= n; j++) {
        if (a[i] <= a[j])
          mx = max(mx, z[a[i] - 1] ^ z[a[j]]);
        else
          mx = max(mx, z[a[j] - 1] ^ z[a[i]]);
        b[j] = mx;
      }
      for (int j = 1; j <= m; j++) {
        if (l[j] <= i && i <= r[j]) ans[j] = max(ans[j], b[r[j]]);
      }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
