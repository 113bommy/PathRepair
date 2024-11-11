#include <bits/stdc++.h>
using namespace std;
pair<long long, pair<long long, long long> > gcd(long long a, long long b) {
  if (a == 0)
    return make_pair(b, make_pair(0, 1));
  else {
    pair<long long, pair<long long, long long> > x = gcd(b % a, a);
    return make_pair(
        x.first,
        make_pair(x.second.second - (b / a) * x.second.first, x.second.first));
  }
}
int main() {
  long long a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);
  pair<long long, pair<long long, long long> > g = gcd(a, b);
  long long gg = g.first;
  long long x = g.second.first;
  long long y = g.second.second;
  if (c % gg != 0)
    printf("-1\n");
  else {
    x *= c / gg;
    y *= c / gg;
    if (x > 5 * 1000000000000000000LL || x < -5 * 1000000000000000000LL ||
        y > 5 * 1000000000000000000LL || y < -5 * 1000000000000000000LL)
      printf("-1\n");
    else
      printf("%lld %lld\n", -x, -y);
  }
  return 0;
}
