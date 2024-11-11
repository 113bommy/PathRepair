#include <bits/stdc++.h>
using namespace std;
int c, d, n, m, k;
int main() {
  scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
  int need = n * m - k;
  int ans = 1000000000;
  for (int i = 0; i <= m; i++) {
    int left = need - i * n;
    if (left <= 0) {
      ans = min(ans, c * i);
      continue;
    }
    ans = min(ans, left * d);
  }
  printf("%d\n", ans);
  return 0;
}
