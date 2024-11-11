#include <bits/stdc++.h>
using namespace std;
long long now, n, cnt, a[500001], b[500001], c[500001], p[500001], ans;
long long ins(long long x) {
  long long i;
  for (i = 62; i >= 0; i--)
    if (x & (1ll << i)) {
      if (p[i])
        x ^= p[i];
      else {
        p[i] = x;
        cnt++;
        return 1;
      }
    }
  return 0;
}
int main() {
  long long i;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i], &b[i]);
    c[i] = a[i] ^ b[i];
    ins(c[i]);
    now ^= a[i];
  }
  if (ins(now))
    puts("1/1");
  else {
    ans = 1 << cnt;
    printf("%lld/%lld", ans - 1, ans);
  }
}
