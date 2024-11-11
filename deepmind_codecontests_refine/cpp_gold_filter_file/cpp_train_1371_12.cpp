#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const int MOD = 1e9 + 7;
const int oo = 2 * MOD + 1e3;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> l = {1, 1}, r = {n, m};
  bool f = 0;
  int cnt = n * m;
  while (cnt--) {
    if (!f) {
      printf("%d %d\n", l.first, l.second);
      ++l.second;
      if (l.second == m + 1) l.second = 1, ++l.first;
    } else {
      printf("%d %d\n", r.first, r.second);
      --r.second;
      if (!r.second) r.second = m, --r.first;
    }
    f ^= 1;
  }
  return 0;
}
