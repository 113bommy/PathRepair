#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l = 0, r = 1e9;
  cin >> n >> k;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    long long ans = mid * (mid + 1) / 2;
    if (ans - n + mid == k) return cout << n - mid, 0;
    if (ans - n + mid > k)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}
