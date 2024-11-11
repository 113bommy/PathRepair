#include <bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010];
const long long inf = 1ll << 60;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  long long ans = 0, bns = inf;
  for (int i = 1; i <= n; ++i) {
    ans = -inf;
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        for (int k = 1; k <= m; ++k) {
          ans = max(ans, 1ll * a[j] * b[k]);
        }
      }
    }
    bns = min(bns, ans);
  }
  printf("%lld", bns);
  return 0;
}
