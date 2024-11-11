#include <bits/stdc++.h>
using namespace std;
long long m;
long long test(long long x) {
  long long ans = 0;
  for (long long i = 2; i * i * i <= x; ++i) {
    ans += x / (i * i * i);
  }
  return ans;
}
long long bs(long long lo, long long hi) {
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    if (test(mid) >= m) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if (test(hi) == m)
    return hi;
  else if (test(lo) == m)
    return lo;
  return -1;
}
int main(void) {
  cin >> m;
  cout << bs(0, 100000000000000LL) << "\n";
  return 0;
}
