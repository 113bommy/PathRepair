#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  long long n;
  cin >> n;
  n *= 2;
  vector<long long> res;
  for (long long p2 = 0; p2 <= 61; ++p2) {
    long long coef = 0;
    for (long long j = 0; j < p2; ++j) {
      coef += 1ll << (j + 1);
    }
    if (coef > n) break;
    long long low = 1, high = min(n / max(1ll, coef), 200000000ll);
    while (low < high) {
      long long mid = (low + high) / 2;
      if (coef * mid + mid * (mid - 1) < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    if (low % 2 == 1 && coef * low + low * (low - 1) == n) {
      res.push_back(low);
      for (int j = 0; j < p2; j++) res.back() *= 2ll;
    }
  }
  if (!res.size()) res.push_back(-1);
  sort(res.begin(), res.end());
  for (typeof(res.begin()) it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
  return 0;
}
