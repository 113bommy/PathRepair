#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
int n, p;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= 10000000; i++) {
    if (n - i * p > 0 && i >= __builtin_popcount(n - i * p) && i <= (n - i * p))
      return cout << i << '\n', 0;
  }
  cout << -1 << '\n', 0;
}
