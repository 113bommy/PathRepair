#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000020], QAQ;
inline bool mycmp(long long x, long long y) { return x > y; }
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", &QAQ, &a[i]);
  sort(a + 1, a + m + 1, mycmp);
  long long ans = 0;
  for (long long i = 1; i <= m; i++) {
    if (!(i & 1)) {
      if (n < ((i * (i - 1)) / 2 + i / 2)) break;
    } else {
      if (n < (i * (i - 1)) / 2) break;
    }
    ans += a[i];
  }
  printf("%lld", ans);
}
