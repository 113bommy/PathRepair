#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (n > m) swap(n, m);
  long long ans;
  if (n <= k) {
    k -= n - 1;
    if (m <= k) {
      puts("-1");
      return 0;
    }
    ans = m / (k + 1);
  } else {
    ans = 1ll * (n / (k + 1)) * m;
    if (m > k) {
      ans = max(ans, 1ll * m / (k + 1) * n);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
