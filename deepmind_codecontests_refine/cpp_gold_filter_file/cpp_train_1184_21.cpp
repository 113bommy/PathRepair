#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;
int main() {
  long long n, k;
  cin >> n >> k;
  long long lo = 0, hi = k, mid;
  while (hi - lo > 0) {
    mid = lo + (hi - lo) / 2;
    if ((mid * k) - ((mid + 2) * (mid - 1) / 2) >= n)
      hi = mid;
    else
      lo = mid + 1;
  }
  lo == k ? cout << -1 : cout << lo;
  return 0;
}
