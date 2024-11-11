#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t n;
  cin >> n;
  vector<pair<uint64_t, uint64_t>> sol;
  n *= 6;
  for (uint64_t i = 1; true; ++i) {
    uint64_t divisor = i * (i + 1);
    if (divisor > n) break;
    uint64_t quotient = n / divisor;
    uint64_t remainder = n % divisor;
    if (quotient < i * 2) break;
    if (remainder != 0) continue;
    uint64_t xm = quotient + i - 1;
    uint64_t mquotient = xm / 3;
    uint64_t mremainder = xm % 3;
    if (mquotient < i) break;
    if (mremainder != 0) continue;
    sol.push_back({i, mquotient});
  }
  if (sol.back().first == sol.back().second)
    cout << sol.size() * 2 - 1 << '\n';
  else
    cout << sol.size() * 2 << '\n';
  cout << sol[0].first << ' ' << sol[0].second;
  for (int i = 1; i < sol.size(); ++i) {
    cout << '\n' << sol[i].first << ' ' << sol[i].second;
  }
  if (sol.back().first != sol.back().second) {
    cout << '\n' << sol.back().second << ' ' << sol.back().first;
  }
  for (int i = sol.size() - 2; i >= 0; --i) {
    cout << '\n' << sol[i].second << ' ' << sol[i].first;
  }
  return 0;
}
