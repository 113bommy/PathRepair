#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, i;
  long long d, ans, m, ac, ab, aac, aab;
  scanf("%d %lld %lld %d", &n, &d, &m, &r);
  ans = (((n - 1) * m + r) / d + 1) * d;
  for (i = 0; i < n; i++) {
    ac = i * m + r;
    ab = (i + 1) * m;
    aac = ac / d + 1;
    if (ab % d == 0)
      aab = ab / d - 1;
    else
      aab = ab / d;
    if (aab >= aac) {
      ans = aab * d;
      break;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
