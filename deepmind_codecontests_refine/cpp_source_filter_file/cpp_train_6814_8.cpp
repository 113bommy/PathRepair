#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long mod, l, r;
inline long long mul(long long x, long long y) { return x * y % mod; }
int main() {
  scanf("%lld", &mod);
  l = mod - mul(inf, 81);
  r = l + inf - 1;
  printf("%lld %lld", l, r);
  return 0;
}
