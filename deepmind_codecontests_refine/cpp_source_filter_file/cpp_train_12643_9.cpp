#include <bits/stdc++.h>
using namespace std;
const long long M = (1e9) + 7;
long long check(long long a) {
  if (a > 0)
    return a % M;
  else
    return (a + M) % M;
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  long long x, y, n;
  std::vector<long long> v;
  std::cin >> x >> y >> n;
  v.push_back(check(x));
  v.push_back(check(y));
  v.push_back(check(y - x));
  v.push_back(check(-x));
  v.push_back(check(-y));
  v.push_back(check(x - y));
  std::cout << v[(n - 1) % 6] << '\n';
  return 0;
}
