#include <bits/stdc++.h>
using namespace std;
long long mx = 1000000000000000000;
bool issq(long long x) {
  long long y = sqrt(x);
  while (y * y > x) y--;
  while (y * y < x) y++;
  return y * y == x;
}
set<long long> s;
map<long long, long long> m;
long long f(long long x) {
  auto it = s.upper_bound(x);
  if (it == s.end())
    return (s.size() - 1LL);
  else
    return (m[*it] - 1LL);
}
long long g(long long x) {
  long long y = sqrt(x);
  while (y * y > x) y--;
  while (y * y < x) y++;
  if (y * y == x)
    return y;
  else {
    y--;
    return y;
  }
}
int main() {
  long long i, j, q, l, r, ans;
  for (long long i = 2; i <= 1000000; ++i) {
    long long p = i * i;
    while ((double)p * i <= 1e18 + 100) {
      p *= i;
      s.insert(p);
    }
  }
  long long x;
  for (auto it = s.begin(); it != s.end();) {
    x = *it;
    it++;
    if (issq(x)) s.erase(x);
  }
  if (issq(x)) s.erase(x);
  long long ptr = 0;
  for (auto x : s) m[x] = ++ptr;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld%lld", &l, &r);
    l--;
    ans = f(r) - f(l);
    ans += g(r);
    ans -= g(l);
    printf("%lld\n", ans);
  }
}
