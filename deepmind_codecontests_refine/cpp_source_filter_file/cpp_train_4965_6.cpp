#include <bits/stdc++.h>
using namespace std;
inline bool can(long long n, long long k) {
  long long left = (n + 1) >> 1;
  while (n > 0) {
    n = max(0ll, n - k);
    left -= n / 10;
    n = max(0ll, n - n / 10);
    if (left < 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long l = 1, r = n, k = n;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (can(n, mid)) {
      k = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << k << endl;
}
