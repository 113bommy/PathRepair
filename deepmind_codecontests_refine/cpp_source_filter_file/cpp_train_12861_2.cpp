#include <bits/stdc++.h>
using namespace std;
unsigned long long int possible(long long int num) {
  unsigned long long int c = 0;
  for (unsigned long long int x = 2; x <= cbrt(num); x++) {
    c += num / (x * x * x);
  }
  return c;
}
int main() {
  unsigned long long int n;
  cin >> n;
  unsigned long long int lo = 0, hi = 1000000000000000, ans;
  bool poss = true;
  while (lo <= hi) {
    unsigned long long int mid = lo + (hi - lo + 1) / 2;
    unsigned long long int pos = possible(mid);
    if (pos == n) {
      ans = mid;
      poss = false;
      hi = mid - 1;
    } else if (pos < n) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  if (poss) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
