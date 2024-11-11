#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long solve() {
  if (k * (k + 1) / 2 < n) return -1;
  long long l = 0, r = k, mid = (l + r) / 2, last = mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (k * (k + 1) / 2 - mid * (mid + 1) / 2 >= n)
      l = mid + 1, last = mid;
    else
      r = mid - 1;
  }
  return n - last;
}
int main() {
  cin >> n >> k;
  n--, k--;
  cout << solve() << endl;
  return 0;
}
