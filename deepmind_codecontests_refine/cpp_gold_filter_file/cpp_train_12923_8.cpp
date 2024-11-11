#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, b;
  cin >> n >> b;
  vector<pair<long long, long long>> factor;
  for (auto d = 2LL; d * d <= b; ++d) {
    if (b % d == 0) {
      factor.emplace_back(d, 0);
      while (b % d == 0) {
        b /= d;
        factor.back().second++;
      }
    }
  }
  if (b > 1) factor.emplace_back(b, 1);
  long long rez = 1e18;
  for (auto it : factor) {
    long long x = it.first, ap = it.second, times = 0;
    while (x <= n) {
      times += n / x;
      if (x > n / it.first) break;
      x *= it.first;
    }
    rez = min(rez, times / ap);
  }
  cout << rez;
}
