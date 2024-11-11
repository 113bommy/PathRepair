#include <bits/stdc++.h>
using namespace std;
long long s, x;
int main() {
  scanf("%lld %lld", &s, &x);
  long long y = s - x;
  if (y & 1) puts("0"), exit(0);
  if (y < 0) puts("0"), exit(0);
  y >>= 1;
  if (x & y) puts("0"), exit(0);
  s -= 2 * y;
  if (s < 0) puts("0"), exit(0);
  long long ans = 1LL << __builtin_popcountll(s);
  if (!y) ans -= 2;
  printf("%lld\n", max(0LL, ans));
  return 0;
}
