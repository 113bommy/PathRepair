#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
vector<pair<pair<long long, long long>, int>> vec;
void solve(long long x, long long n) {
  long long ret = 0;
  while (n) {
    if (n & 1) {
      if (ret) vec.push_back(make_pair(make_pair(ret, x), 1));
      ret += x;
    }
    vec.push_back(make_pair(make_pair(x, x), 1));
    x += x;
    n >>= 1;
  }
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y);
  long long tmp = x;
  x = y;
  y = tmp - a / b * y;
  return g;
}
int main() {
  int x;
  scanf("%d", &x);
  int p = 0;
  while ((1 << p) <= x) p++;
  p--;
  long long y = 1ll * (1 << p) * x;
  solve(x, (1 << p));
  vec.push_back(make_pair(make_pair(x, y), 0));
  y ^= x;
  long long a, b;
  exgcd(x, y, a, b);
  b = -b;
  if (b < 0) {
    b = (b % x + x) % x;
    a = (1 + b * y) / x;
  }
  if (a % 2 == 0) {
    b += x;
    a += y;
  }
  solve(x, a);
  solve(y, b);
  vec.push_back(make_pair(make_pair(a * x, b * y), 0));
  printf("%d\n", ((int)(vec).size()));
  for (auto p : vec) {
    printf("%lld %c %lld\n", p.first.first, "^+"[p.second], p.first.second);
  }
  return 0;
}
