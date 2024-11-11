#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  function<bool(long long)> is_square = [](long long x) {
    long long sol = sqrt(x);
    for (int i = -1; i <= 1; ++i)
      if ((sol + i) * (sol + i) == x) return true;
    return false;
  };
  function<long long(long long)> floor_o_sqrt = [](long long x) {
    long long sol = sqrt(x) - 1;
    for (int i = -1; i <= 1; ++i)
      if ((sol + i) * (sol + i) <= x) sol = sol + i;
    return sol;
  };
  vector<long long> m3;
  for (long long i = 2; i <= 1e6 + 10; ++i) {
    long long x = i * i * i;
    while (x <= 1e18 + 10) {
      if (not is_square(x)) m3.push_back(x);
      if ((double)x * i > 1e18 + 10 or x * i > 1e18 + 10) break;
      x *= i;
    }
  }
  sort(m3.begin(), m3.end());
  m3.resize(unique(m3.begin(), m3.end()) - m3.begin());
  int T;
  cin >> T;
  long long n;
  while (T--) {
    cin >> n;
    cout << n - (upper_bound(m3.begin(), m3.end(), n) - m3.begin()) -
                floor_o_sqrt(n) - 1
         << '\n';
  }
}
