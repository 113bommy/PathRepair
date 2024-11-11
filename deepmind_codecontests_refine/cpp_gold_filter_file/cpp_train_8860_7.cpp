#include <bits/stdc++.h>
using namespace std;
int d[100003];
signed main() {
  int n, s, u, v, ans = 0;
  scanf("%d%d", &n, &s);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    ++d[u], ++d[v];
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] > 1) continue;
    ++ans;
  }
  printf("%.9lf", s * 2.0 / ans);
  return 0;
}
