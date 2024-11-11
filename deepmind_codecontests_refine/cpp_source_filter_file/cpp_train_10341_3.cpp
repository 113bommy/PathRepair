#include <bits/stdc++.h>
using namespace std;
long long i, n, now, ans, hh, m, p = 1000000009;
int main() {
  scanf("%lld", &n);
  if (n == 2) {
    puts("10");
    return 0;
  }
  m = n / 2;
  now = 4;
  hh = 1;
  for (i = 3; i <= m; i++) {
    now = now * 2 % p;
    hh = hh * now % p;
    ans = (ans + now) % p;
  }
  ans = ans * 4 + 6;
  ans %= p;
  ans = ans * ans % p;
  ans++;
  ans = ans * 2 % p;
  printf("%lld", ans);
}
