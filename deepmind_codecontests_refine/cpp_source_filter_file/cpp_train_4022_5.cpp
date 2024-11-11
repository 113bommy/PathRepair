#include <bits/stdc++.h>
using namespace std;
long long n, m, a, d, CAND;
long long get(long long time) { return (time + CAND - 1) / CAND; }
long long getnum(long long time) { return 1 + time / CAND; }
int main() {
  scanf("%lld %lld %lld %lld", &n, &m, &a, &d);
  CAND = (a * ((d + a) / a));
  register long long ans = 0, cur = 0, nxt = 0;
  long long lst = a, x;
  while (--m > -2) {
    if (m != -1)
      scanf("%lld", &x);
    else
      x = 1.5e+18;
    if (x <= nxt) continue;
    lst = a * (nxt / a + 1);
    if (lst > n * a) {
      ans++;
      nxt = x + d;
    } else {
      if (x < lst) {
        ans++;
        nxt = x + d;
      } else {
        long long jumps = getnum(min(x, (long long)n * a) - lst);
        ans += jumps;
        nxt = lst + CAND * (jumps - 1) + d;
        if (x > nxt) {
          ans++;
          nxt = x + d;
        }
      }
    }
  }
  printf("%lld", ans - 1);
  return 0;
}
