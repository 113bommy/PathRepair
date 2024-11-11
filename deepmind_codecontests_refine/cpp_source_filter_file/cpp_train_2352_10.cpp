#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  int ans = 102, tmp = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    int d = abs(m - i);
    if (x <= k and x > 0) ans = min(ans, d * 10);
  }
  printf("%d\n", ans);
  return 0;
}
