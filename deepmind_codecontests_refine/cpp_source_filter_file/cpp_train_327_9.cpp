#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 5e5 + 5, M = 2 * N + 5;
int n, t;
char second[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", &second);
    n = strlen(second);
    long long l = 0, r = 0, lmx = 0, lmn = 0, rmx = 0, rmn = 0;
    long long lmxlen = 0, lmnlen = 0, rmxlen = 0, rmnlen = 0;
    for (int i = 0; i < n; ++i) {
      if (second[i] == 'W')
        lmx = max(lmx, l++);
      else if (second[i] == 'S')
        lmn = min(lmn, l--);
      else if (second[i] == 'D')
        rmx = max(rmx, r++);
      else
        rmn = min(rmn, r--);
      lmxlen = max(lmxlen, lmx - l);
      lmnlen = max(lmnlen, l - lmn);
      rmxlen = max(rmxlen, rmx - r);
      rmnlen = max(rmnlen, r - rmn);
    }
    long long ans = (lmx - lmn + 1LL) * (rmx - rmn + 1LL);
    if (lmx - lmn > 1LL && lmxlen != lmnlen)
      ans = min(ans, (lmx - lmn) * (rmx - rmn + 1LL));
    if (rmx - rmn > 1LL && rmxlen != rmnlen)
      ans = min(ans, (lmx - lmn + 1LL) * (rmx - rmn));
    printf("%lld\n", ans);
  }
  return 0;
}
