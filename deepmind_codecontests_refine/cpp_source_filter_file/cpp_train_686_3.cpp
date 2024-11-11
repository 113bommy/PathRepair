#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], b[10], ans = 100, mn1 = 10, mn2 = 10;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mn1 = min(mn1, a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    mn2 = min(mn2, b[i]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i] == b[j]) ans = min(ans, a[i]);
  printf("%d", min(ans, min(mn1, mn2) * 10 + max(mn1, mn2)));
}
