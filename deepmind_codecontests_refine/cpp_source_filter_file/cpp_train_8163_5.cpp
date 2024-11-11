#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, Q = 1e3;
int a[N + 5][N + 5];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) ans += a[i][j] * a[j][i];
    ans %= 2;
    int m;
    scanf("%d", &m);
    while (m--) {
      int k;
      scanf("%d", &k);
      if (k == 3)
        printf("%d\n", ans);
      else {
        int p;
        scanf("%d", &p);
        ans = 1 - ans;
      }
    }
  }
  return 0;
}
