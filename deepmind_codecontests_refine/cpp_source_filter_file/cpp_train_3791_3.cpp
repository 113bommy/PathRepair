#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 * 2;
int n, m, x[5050], y[5050], a[5050], b[5050], c[5050], d[5050], z[5050];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) x[i] = INF;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    if (a[i] == 1) {
      for (int j = b[i]; j <= c[i]; j++) {
        y[j] += d[i];
      }
    } else {
      for (int j = b[i]; j <= c[i]; j++) {
        x[j] = min(x[j], d[i] - y[j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) z[i] = x[i];
  bool ans = 1;
  for (int i = 1; i <= m && ans; i++) {
    if (a[i] == 2) {
      ans = 0;
      for (int j = b[i]; j <= c[i] && !ans; j++) {
        if (d[i] == x[j]) ans = 1;
      }
    } else {
      for (int j = b[i]; j <= c[i]; j++) x[j] += d[i];
    }
  }
  if (ans) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", z[i]);
  } else
    puts("NO");
  return 0;
}
