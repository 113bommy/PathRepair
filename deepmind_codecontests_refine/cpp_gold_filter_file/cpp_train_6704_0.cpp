#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long n;
  cin >> n;
  set<long long> S;
  for (int k = (1); k < (62); ++k) {
    long long B = (1LL << k) - 3;
    long long lo = 0, hi = 2e9;
    if (k > 20) hi = min(hi, 2 * n / B + 10);
    while (lo < hi) {
      long long mid = (lo + hi) / 2;
      if (mid * mid + B * mid < 2 * n)
        lo = mid + 1;
      else
        hi = mid;
    }
    if (lo * lo + B * lo == 2 * n && (lo & 1) == 1) S.insert(lo << (k - 1));
  }
  if (S.size() == 0)
    puts("-1");
  else
    for (long long x : S) cout << x << endl;
  return 0;
}
