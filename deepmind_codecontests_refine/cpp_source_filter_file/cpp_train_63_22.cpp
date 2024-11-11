#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  while (~scanf("%d%d", &n, &m)) {
    int k, ans = 1 << 29;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      if (m % k == 0) ans = min(ans, k);
    }
    printf("%d\n", ans);
  }
  return 0;
}
