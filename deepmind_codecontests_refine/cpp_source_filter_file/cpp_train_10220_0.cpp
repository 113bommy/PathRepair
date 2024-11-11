#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f;
using namespace std;
const long long maxn = 2e5 + 100;
long long n, k;
long long a[maxn];
int32_t main() {
  long long q;
  scanf("%lld", &(q));
  while (q--) {
    scanf("%lld%lld", &(n), &(k));
    long long maxx = 0, minn = 0x3f3f3f3f;
    for (long long i = (1); i <= (n); i++) {
      scanf("%lld", &(a[i]));
      if (maxx < a[i]) maxx = a[i];
      if (minn > a[i]) minn = a[i];
    }
    long long x = minn + k;
    if (abs(x - maxx) > k)
      printf("-1");
    else
      printf("%lld", (x));
    printf("-1");
  }
  return 0;
}
