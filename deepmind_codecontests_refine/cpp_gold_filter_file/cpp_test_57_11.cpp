#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  long long T;
  scanf("%lld", &T);
  for (long long s, n, k; T; T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s == k)
      printf("YES\n");
    else if (s < k)
      printf("NO\n");
    else {
      long long k2 = k * 2, sk = min(s % k2, k - 1);
      printf((s / k2 * k + sk < n) ? "YES\n" : "NO\n");
    }
  }
}
