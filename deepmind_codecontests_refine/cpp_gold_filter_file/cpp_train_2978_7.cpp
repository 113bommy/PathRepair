#include <bits/stdc++.h>
using namespace std;
int digsum(long long x) {
  int ans = 0;
  while (x) {
    ans += (x % 10);
    x /= 10;
  }
  return ans;
}
int main() {
  long long n, s;
  cin >> n >> s;
  long long l = 1, r = 1e18;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid - digsum(mid) >= s) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  long long from = l;
  l = from, r = n;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid - digsum(mid) >= s) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << l - from;
}
