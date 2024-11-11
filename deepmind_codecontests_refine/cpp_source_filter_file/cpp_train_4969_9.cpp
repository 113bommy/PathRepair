#include <bits/stdc++.h>
using namespace std;
bool check(long long m, long long n) {
  long long v = 0, p = 0;
  while (n > 0) {
    n -= min(m, n);
    v += min(m, n);
    long long mm = n / 10;
    n -= min(mm, n);
    p += min(mm, n);
  }
  return v >= p;
}
int main() {
  int T;
  long long n;
  scanf("%lld", &n);
  long long hi = n, lo = 1;
  long long ans = n;
  while (lo <= hi) {
    long long mid = (hi + lo) / 2;
    if (check(mid, n)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
