#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxm = 2005;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long n;
int main() {
  scanf("%lld", &n);
  long long cnt = 0;
  long long maxn = 0;
  long long pa = -1, pb = -1;
  for (int i = 1; i <= 9; i++) {
    cnt = cnt * 10 + 9;
    long long a = cnt / 2;
    long long b = cnt - a;
    if (a <= n && b <= n) {
      pa = a, pb = b;
      maxn = cnt;
      continue;
    } else
      break;
  }
  if (pa == -1) {
    long long ans = n * (n - 1) / 2;
    printf("%lld\n", ans);
    return 0;
  } else {
    long long tot = 0;
    long long ppp = pa;
    while (pa) {
      pa /= 10;
      tot++;
    }
    long long wei = 1;
    for (int i = 0; i < tot; i++) wei *= 10;
    long long q = max(pa, pb);
    long long p = min(pa, pb);
    long long kk = n - q - p;
    long long ans = 0;
    long long times = n - q + 1;
    long long ci = times / wei;
    ans += wei * ((1 + ci) * ci / 2);
    times %= wei;
    ans += times * (ci + 1);
    if (n >= maxn) ans -= 1 + (n - maxn) / wei;
    printf("%lld\n", ans);
  }
  return 0;
}
