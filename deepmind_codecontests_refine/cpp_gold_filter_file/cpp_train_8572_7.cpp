#include <bits/stdc++.h>
using namespace std;
int n, m, s;
long long ans;
long long F(int x, int y) { return (n - x + 1) * (m - y + 1); }
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= n; i += 2)
    for (int j = 1; j <= m; j += 2) {
      int s1 = i * j;
      if (s1 == s)
        ans += (((i - 1) / 2 + 1) * ((j - 1) / 2 + 1) * 2 - 1) * F(i, j);
      if (s1 < s) {
        int dt = s - s1;
        for (int k = 1; k < j; k += 2)
          if (!(dt % 2) && !(dt % k) && (i + dt / k <= n))
            ans += 2 * F(i + dt / k, j);
      }
    }
  printf("%lld\n", ans);
  return 0;
}
