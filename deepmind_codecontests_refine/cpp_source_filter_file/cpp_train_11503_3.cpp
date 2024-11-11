#include <bits/stdc++.h>
using namespace std;
void solve() {
  int ans, i, n, m, a, b, d1, d2;
  scanf("%d%d%d%d", &n, &m, &d1, &a);
  ans = a + d1;
  for (i = 1; i < m; i++) {
    scanf("%d%d", &d2, &b);
    if (abs(a - b) > d2 - d1) {
      printf("IMPOSSIBLE\n");
      return;
    }
    ans = max(ans, (a + b + d2 - d1) / 2);
    d1 = d2;
    a = b;
  }
  ans = max(ans, a + n - d1);
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
