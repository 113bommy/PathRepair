#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("vpt")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long double inf = 1e18;
const long long mod = 1e9 + 7;
const long double fi = (sqrtl(5) + 1) / 2;
const long double eps = 1e-6;
long long count(long long x, long long y) {
  return (x * x + 2 * x * y + x + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long w, l, r, c;
  cin >> w;
  for (long long i = 1; i * i <= w; i++) {
    l = 1, r = 1e7;
    while (r - l > 1) {
      c = (l + r) >> 1;
      if (count(i, c) > w)
        r = c;
      else
        l = c;
    }
    if (count(i, l) == w) {
      cout << i << ' ' << l << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
