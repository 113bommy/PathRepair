#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, k;
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  long long a = (r + n - l + 1) % n;
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (k < a) {
    printf("-1");
    return 0;
  }
  long long ans = -1;
  if (k - a >= 0 && k - a <= a) ans = max(ans, k - a + n - a);
  for (long long l, r, i = 1; i <= k; i = r + 1) {
    l = i;
    r = k / (k / l);
    long long m = k / l;
    if (l - n > n) continue;
    long long bot =
        max(ceil((double)((k - a) / m - n - (k - a) % m - n + a) / (m + 1)),
            ceil((double)(-(k - a) % m) / m));
    bot = max(bot, (k - a) / m - r);
    long long top =
        min(floor((double)((k - a) / m - n - (k - a) % m) / (m + 1)),
            floor((double)(a - (k - a) % m) / m));
    top = min(top, (k - a) / m - l);
    if (bot <= top) ans = max(ans, (k - a) / m - bot - n);
  }
  k++;
  if (k - a >= 1 && k - a <= a) ans = max(ans, k - a + n - a);
  if (a) {
    for (long long l, r, i = 1; i <= k; i = r + 1) {
      l = i;
      r = k / (k / l);
      long long m = k / l;
      if (l - n > n) continue;
      long long bot =
          max(ceil((double)((k - a) / m - n - (k - a) % m - n + a) / (m + 1)),
              ceil((double)(1 - (k - a) % m) / m));
      bot = max(bot, (k - a) / m - r);
      long long top =
          min(floor((double)((k - a) / m - n - (k - a) % m) / (m + 1)),
              floor((double)(a - (k - a) % m) / m));
      top = min(top, (k - a) / m - l);
      if (bot <= top) ans = max(ans, (k - a) / m - bot - n);
    }
  } else {
    for (long long l, r, i = 1; i <= k; i = r + 1) {
      l = i;
      r = k / (k / l);
      long long m = k / l;
      if (l - n > n) continue;
      long long bot =
          max(ceil((double)((k - a) / m - n - (k - a) % m - n + a) / (m + 1)),
              ceil((double)(-(k - a) % m) / m));
      bot = max(bot, (k - a) / m - r);
      long long top =
          min(floor((double)((k - a) / m - n - (k - a) % m - 1) / (m + 1)),
              floor((double)(a - (k - a) % m) / m));
      top = min(top, (k - a) / m - l);
      if (bot <= top) ans = max(ans, (k - a) / m - bot - n);
    }
  }
  printf("%lld", ans);
  return 0;
}
