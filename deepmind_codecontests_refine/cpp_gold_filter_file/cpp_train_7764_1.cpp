#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long x;
char s[100005];
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = (1); i <= (q); ++i) {
    scanf("%lld%s", &x, s + 1);
    long long l = strlen(s + 1);
    for (long long j = (1); j <= (l); ++j) {
      if (s[j] == 'U') {
        if (x == (1ll << (long long)(log2(n + 1) - 1))) continue;
        long long pos = log2((x & (-x)));
        if (x & (1 << pos + 1))
          x -= 1 << pos;
        else
          x += 1 << pos;
      } else if (s[j] == 'L') {
        if (x & 1) continue;
        long long t = (x & (-x));
        x -= t >> 1;
      } else if (s[j] == 'R') {
        if (x & 1) continue;
        long long t = (x & (-x));
        x += t >> 1;
      }
    }
    printf("%lld\n", x);
  }
  return 0;
}
